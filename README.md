This repo contains CSS stylesheets and PHP code/templates that are shared
across multiple .php.net websites to make code and layout reuse easier.

In production (e.g. hostname ends with '.php.net') it will point to 
shared.php.net for all CSS+JS. It is also magically included via rsync
so there is no submodule required.

When running locally, you have to clone this repo and put it into your
web root as 'shared'.

To see the styles that are defined, you can run the standalone PHP server and
access the test page:

```sh
$ ln -s . shared
$ php -S localhost:9000
# view http://localhost:9000
```

If you are running a local version of one of the sites that uses
web-shared, you can also just access `http://localhost:PORT/shared/`
