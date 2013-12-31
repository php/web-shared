This repo contains CSS stylesheets and PHP code/templates that are shared
across multiple .php.net websites to make code and layout reuse easier.

In production (e.g. hostname ends with '.php.net') it will point to 
shared.php.net for all CSS+JS. It is also magically included via rsync
so there is no submodule required.

When running locally, you have to clone this repo and put it into your
web root as 'shared'.



