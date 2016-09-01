<?php

/**
 * @file
 * Extract the version from the Javascript file.
 *
 * @return string
 *   The version string, or NULL if we couldn't find it.
 */

/**
 * Get the installed version.
 */
function islandora_openseadragon_get_installed_version() {
  $version = &drupal_static(__FUNCTION__, NULL);

  if ($version === NULL) {
    $path = libraries_get_path('openseadragon');
    $openseadragon_js = file_get_contents("$path/openseadragon.js");
    $matches = array();
    $count = preg_match('/@version\s+OpenSeadragon\s+((\d+\.){2}\d+)/', $openseadragon_js, $matches);
    if ($count) {
      $version = $matches[1];
    }
  }

  return $version;
}

/**
 * Helper to construct the URL used to retrieve a "clip" from Djatoka.
 *
 * @param string $params
 *   A string containing the $_GET clip value to be parsed.
 * @param bool $download
 *   Whether the URL being generated is for a download link.
 *
 * @return bool|array
 *   FALSE when invalid parameters passed in, otherwise an array containing:
 *   -original_params (string): A rawurlencoded string which can be used as or
 *   appended to the URL query string.
 *   -djatoka_image_url (string): URL to retrieve the image from Djatoka.
 *   -dimensions (array): An array containing the width and height of the image.
 *   Used when rendering the image on the print page.
 */
function islandora_openseadragon_construct_clip_url($params, $download = FALSE) {
  global $base_root;
  $settings = islandora_openseadragon_get_settings();
  $decoded_params = drupal_get_query_array($params);
  $djatoka_url = $settings['djatokaServerBaseURL'];
  $djatoka_params = array(
    'url_ver' => 'Z39.88-2004',
    'svc_id' => 'info:lanl-repo/svc/getRegion',
    'svc_val_fmt' => 'info:ofi/fmt:kev:mtx:jpeg2000',
    'svc.format' => 'image/jpeg',
  );
  // Only grab the two parameters that are expected to be there, ignore anything
  // else.
  $allowed_djatoka_param_keys = drupal_map_assoc(array(
    'rft_id',
    'svc.region',
  ));
  $allowed_djatoka_params = array_intersect_key($decoded_params, $allowed_djatoka_param_keys);
  if (empty($allowed_djatoka_params)) {
    return FALSE;
  }
  $rft_id = $decoded_params['rft_id'];
  $path = parse_url($rft_id, PHP_URL_PATH);
  // Remove sub dir from $path
  if (base_path() !== '/') {
    $path = substr($path, strlen(base_path()) - 1);
  }
  // Replace the first left-most slash to get a more Drupal-y path to validate
  // against.
  $drupal_path = preg_replace('/\//', '', $path, 1);
  $item = menu_get_item($drupal_path);
  if (!$item || $item['path'] !== 'islandora/object/%/datastream/%/view') {
    return FALSE;
  }
  $djatoka_url_params = drupal_http_build_query($djatoka_params + $allowed_djatoka_params);
  // XXX: See if Djatoka is relative or absolute and handle accordingly.
  // Building up URL this way because may encounter a relative or absolute path
  // to Djatoka. Similarly, the built in Drupal functions such as URL will
  // construct URLs with the multi-site/language prefixs present. Lastly, not
  // using url_is_external as a relative Djatoka path may have two slashes
  // preceding it which it would flag falsely.
  if (!$download || strpos($djatoka_url, 'http') === 0) {
    $url = "$djatoka_url?$djatoka_url_params";
  }
  else {
    $url = "{$base_root}{$djatoka_url}?$djatoka_url_params";
  }
  $dimensions = array();
  if (isset($decoded_params['dimensions'])) {
    $dimensions = explode(',', $decoded_params['dimensions']);
    $dimensions = array(
      'width' => $dimensions[0],
      'height' => $dimensions[1],
    );
  }
  return array(
    // XXX: Using drupal_http_build_query to avoid changing the underlying
    // functionality in the solution packs that currently implement.
    'original_params' => drupal_http_build_query($allowed_djatoka_params),
    'djatoka_image_url' => $url,
    'dimensions' => $dimensions,
  );
}
