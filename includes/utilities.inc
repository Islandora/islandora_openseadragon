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
