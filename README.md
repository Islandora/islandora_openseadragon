# Islandora OpenSeadragon [![Build Status](https://travis-ci.org/Islandora/islandora_openseadragon.png?branch=7.x)](https://travis-ci.org/Islandora/islandora_openseadragon)

# Introduction

An Islandora viewer module using OpenSeadragon. Works with large image datastreams (JPEG-2000). Supports a custom Djatoka tilesource and a IIIF tilesource.

Based in spirit from the JS component of Kevin Clarke's [FreeLib-Djatoka](https://github.com/ksclarke/freelib-djatoka)

## Requirements

This module requires the following modules/libraries:

* [Islandora](https://github.com/islandora/islandora)
* [Tuque](https://github.com/islandora/tuque)
* [OpenSeadragon](https://github.com/openseadragon/openseadragon/)
* [Drupal Token Module](https://www.drupal.org/project/token)

## Installation

Install as usual, see [this](https://drupal.org/documentation/install/modules-themes/modules-7) for further information.

[Download](https://github.com/openseadragon/openseadragon/releases/download/v2.3.1/openseadragon-bin-2.3.1.zip) and install the Openseadragon library to your sites/libraries folder, or run `drush openseadragon-plugin`. Openseadragon 2.3.1 is known to work well with Islandora.

Note: If you use the Drush command, it is advisable to Move (not copy) the install script to your `.drush` folder and run it.

## Configuration

Configure the OpenSeadragon viewer settings.

![Configuration](https://user-images.githubusercontent.com/2857697/63660578-9e774700-c77c-11e9-864b-8c720b505f24.png)

## Documentation

Further documentation for this module is available at [our wiki](https://wiki.duraspace.org/display/ISLANDORA/Open+Seadragon)

## Troubleshooting/Issues

Having problems or solved a problem? Check out the Islandora google groups for a solution.

* [Islandora Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora)
* [Islandora Dev Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora-dev)

## Maintainers/Sponsors

Current maintainers:

* [Diego Pino](https://github.com/diegopino)

## Development

If you would like to contribute to this module, please check out [CONTRIBUTING.md](CONTRIBUTING.md). In addition, we have helpful [Documentation for Developers](https://github.com/Islandora/islandora/wiki#wiki-documentation-for-developers) info, as well as our [Developers](http://islandora.ca/developers) section on the [Islandora.ca](http://islandora.ca) site.

## License

[GPLv3](http://www.gnu.org/licenses/gpl-3.0.txt)
