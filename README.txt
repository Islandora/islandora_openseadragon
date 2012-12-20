A Djatoka TileSource for Seadragon

Based in spirit from the JS component of
https://github.com/ksclarke/freelib-djatoka

Instead of "synthesizing" the info for DZI, we create the path to access
Djatoka directly, and obtain different regions for the tiles.

-- Reverse proxy config --
We make the assumption that we (reverse) proxy Djatoka, to fix the same-origin
issue.

For Apache, with Drupal running on the same box as Apache, a couple lines like:

ProxyPass /adore-djatoka/ http://localhost:8080/adore-djatoka/
ProxyPassReverse /adore-djatoka/ http://localhost:8080/adore-djatoka/

in the Apache config somewhere (either the main apache.conf, httpd.conf, or in
and arbitrarily named *.conf in your Apache's conf.d directory should suffice 
to establish the reverse proxy.
In Debian derived systems one will need to create location entries for each
proxy or remove the Deny from All in mod_proxy's conf file.

Note: the image passed to Djatoka needs anonymous user access permissions.

-- OpenSeadragon --
We assume the core OpenSeadragon Javascript is put into sites/all/libraries/openseadragon. It can be obtained from 
https://github.com/thatcher/openseadragon/tarball/master

TODO:
====

High

- clean up preprocess function
- availablity for multiple url's through array (newspapers)
- check for DZI, djatoka as fallback
- check for djatoka availability first.

Medium
- documentation

Low