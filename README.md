# Islandora OpenSeadragon [![Build Status](https://travis-ci.org/Islandora/islandora_openseadragon.png?branch=7.x)](https://travis-ci.org/Islandora/islandora_openseadragon)

## Introduction

This is an Islandora viewer module using OpenSeadragon. It allows users to view large image datastreams (like JPEG-2000) through image tile servers. This module supports a custom Djatoka tilesource and a IIIF tilesource.

Based in spirit on the JS component of Kevin Clarke's [FreeLib-Djatoka](https://github.com/ksclarke/freelib-djatoka).

## Requirements

This module requires the following modules/libraries:

* [Islandora](https://github.com/islandora/islandora)
* [Tuque](https://github.com/islandora/tuque)
* [OpenSeadragon](https://github.com/openseadragon/openseadragon/)
* [Drupal Token Module](https://www.drupal.org/project/token)

In addition, either Djatoka or a IIIF image server needs to be setup.

## Installation

Install the module as usual, see [Drupal 7's documentation on installing modules](https://drupal.org/documentation/install/modules-themes/modules-7) for further information.

The OpenSeadragon JavaScript library is not included in this module. Openseadragon 2.3.1 is known to work well with Islandora.
You can use Drush to download and install it automatically or do it manually.

Older versions must be updated. You can do this quickly 
with the provided Drush command.

### Drush OpenSeadragon installation

This module provides a Drush command to download and install a recent version of OpenSeadragon. It is advisable to *move* (not copy) the install script to your `.drush` folder and run the following command from that folder:

`drush openseadragon-plugin`

### Manual OpenSeadragon installation

Download the [OpenSeadragon 2.3.1 binary release](https://github.com/openseadragon/openseadragon/releases/download/v2.3.1/openseadragon-bin-2.3.1.zip) and install the Openseadragon library to your sites/libraries folder.

## Configuration

Islandora OpenSeadragon offers many settings to be configured. All settings are found in Administration » Islandora » Islandora Viewers » OpenSeadragon (admin/islandora/islandora_viewers/openseadragon).

In this README, only the image server settings are highlighted.
Other settings are explained on the [Open Seadragon wiki page](https://wiki.duraspace.org/display/ISLANDORA/Open+Seadragon).

### Djatoka Image Server

When you use the Adore-Djatoka Image Server ("Djatoka"), you need to set the base URL to the Adore-Djatoka server OpenURL resolver.
The base URL depends on the setup of Djatoka, including (optional) configuration of a reverse proxy.

By default, Islandora OpenSeadragon expects that the Djatoka OpenURL resolver is reachable on the same domain name and port as Islandora itself, at the path `adore-djatoka/resolver`.
A checkmark and confirmation message appear when Islandora can connect to the server.
If Islandora cannot connect to the server, a cross and error message appear.

![Configuration](https://user-images.githubusercontent.com/25011926/40389344-2a7854ea-5de0-11e8-8db9-7a1bf25f2561.png)

### IIIF Image server

When you use the IIIF Image Server, you need to specify:

* the base URL of the image server;
* whether to send the image access token as a HTTP header instead of a query parameter;
* the pattern to use as the image identifier.

As with Djatoka, the base URL depends on the setup of your IIIF image server and reverse proxy, if you use one.
Any [IIIF](https://iiif.io) image server can be used as the IIIF tile source. This IIIF server does need to be configured to resolve the image identifier to retrieve the image.

By default, Islandora OpenSeadragon uses the full URL to the image's JP2 datastream and the image access token as image identifier.
If you use the [Cantaloupe 🍈](https://cantaloupe-project.github.io/) IIIF image server,
you can configure it to resolve these identifiers using the [`HttpResolver`](https://cantaloupe-project.github.io/manual/3.4/resolvers.html#HttpResolver) with no prefix specified.

### Reverse Proxy

A reverse proxy can be used to make an image server available on the same domain as Drupal,
so that cross-origin resource access and the need for CORS headers are avoided.
Various applications can be used as a reverse proxy; [Apache HTTPD] and [nginx] are common in reverse proxy setups.
For details on configuring your reverse proxy, you should consult the documentation for your application of choice.

[Apache HTTPD]: https://httpd.apache.org
[nginx]: https://nginx.org/

Note: if you use a reverse proxy, you may need to configure the image server as well, so that it knows
what external URLs are used to reach the image server. Whether this is necessary and how the image server
needs to be configured, depends on the image server.

## Documentation

Further documentation for this module is available at [our wiki](https://wiki.duraspace.org/display/ISLANDORA/Open+Seadragon).

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
