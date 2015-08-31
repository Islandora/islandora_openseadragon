# Islandora OpenSeadragon [![Build Status](https://travis-ci.org/Islandora/islandora_openseadragon.png?branch=7.x)](https://travis-ci.org/Islandora/islandora_openseadragon)

# Introduction

A Djatoka TileSource for Seadragon

Based in spirit from the JS component of Kevin Clarke's [FreeLib-Djatoka](https://github.com/ksclarke/freelib-djatoka)

Instead of "synthesizing" the info for DZI, we create the path to access Djatoka directly, and obtain different regions for the tiles.

Reverse proxy config: We make the assumption that we (reverse) proxy Djatoka, to fix the same-origin issue.

For Apache, with Drupal running on the same box as Apache, a couple lines like:

```
ProxyPass /adore-djatoka http://localhost:8080/adore-djatoka
ProxyPassReverse /adore-djatoka http://localhost:8080/adore-djatoka
```

in the Apache config somewhere (either the main apache.conf, httpd.conf, or in and arbitrarily named *.conf in your Apache's conf.d directory should suffice to establish the reverse proxy.

In Debian derived systems one will need to create location entries for each proxy or remove the Deny from All in mod_proxy's conf file.

## Requirements

This module requires the following modules/libraries:

* [Islandora](https://github.com/islandora/islandora)
* [Tuque](https://github.com/islandora/tuque)
* [OpenSeadragon](http://openseadragon.github.io/releases/openseadragon-bin-0.9.129.zip)
* [Islandora Paged Content](https://github.com/Islandora/islandora_paged_content/) (Conditional: should not require any additional actions from the user as the solution packs that use the feature requiring the islandora_paged_content module include it in their depency lists.)

## Installation

Install as usual, see [this](https://drupal.org/documentation/install/modules-themes/modules-7) for further information.

[Download](https://github.com/openseadragon/openseadragon/releases/download/v2.0.0/openseadragon-bin-2.0.0.zip) and install the Openseadragon library to your sites/libraries folder, or run `drush openseadragon-plugin`. Openseadragon 2.0.0 is known to work well with Islandora.

Note: If you use the Drush command, it is advisable to Move (not copy) the install script to your `.drush` folder and run it.

## Configuration

Set the paths for 'Djatoka server base URL' and configure OpenSeadradon in Administration » Islandora » OpenSeadragon (admin/islandora/module).

![Configuration](https://camo.githubusercontent.com/c1bf991b5cc758a4420444564a91b286007e6f6e/687474703a2f2f692e696d6775722e636f6d2f4e6566597169432e706e67)

## Troubleshooting/Issues

Having problems or solved a problem? Check out the Islandora google groups for a solution.

* [Islandora Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora)
* [Islandora Dev Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora-dev)

## Maintainers/Sponsors

Current maintainers:

* [Jordan Dukart](https://github.com/jordandukart)

## Development

If you would like to contribute to this module, please check out our helpful [Documentation for Developers](https://github.com/Islandora/islandora/wiki#wiki-documentation-for-developers) info, as well as our [Developers](http://islandora.ca/developers) section on the Islandora.ca site.

## License

[GPLv3](http://www.gnu.org/licenses/gpl-3.0.txt)
