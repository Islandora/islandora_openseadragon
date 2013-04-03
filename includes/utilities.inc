<?php

/**
 * Extract the version from the Javascript file.
 *
 * @return int
 *   An integer as provided by islandora_openseadragon_version_string_to_int().
 *
 * @see islandora_openseadragon_version_string_to_int()
 */
function islandora_openseadragon_get_installed_version() {
   $version = &drupal_static(__FUNCTION__, NULL);

   if ($version === NULL) {
     $path = libraries_get_path('openseadragon');
     $openseadragon_js = file_get_contents("$path/openseadragon.js");
     $matches = array();
     $count = preg_match('/@version\s+OpenSeadragon\s+((\d+\.){2}\d+)/', $openseadragon_js, $matches);
     if ($count) {
       $version = islandora_openseadragon_version_string_to_int($matches[1]);
     }
   }

   return $version;
}

/**
 * Parse the version to something more comparable.
 *
 * Versions seem to go to three digits, in each component...  Build something
 * up...
 *
 * @param string $version_string
 *   A version string as OpenSeadragon (currently) uses in the JS doxygen
 *   comments...  Something like: "0.9.124" or "0.9.76".
 *
 * @return int
 *   An integer representing the version.
 */
function islandora_openseadragon_version_string_to_int($version_string) {
   $version = 0;
   foreach (explode('.', $version_string) as $part) {
     $version *= 1000;
     $version += intval($part);
   }
   return $version;
}
