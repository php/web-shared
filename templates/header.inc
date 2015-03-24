<?php
/**
 * Typical header
 *
 * Required variables:
 *
 *   $TITLE     = "Awesome Website"; // Page title
 *   $SUBDOMAIN = "people"; // Subdomain/Project
 *   $LINKS     = array(
 *                  array("href" => "/link.php", "text" => "Link text")
 *                ); // Menu menu links
 *   $HEAD_WIKI = ""; // DokuWiki's extra <head> elements
 *   $HEAD_RAND = ""; // Random extra values needed for in <head>
 *   $CSS       = array("/styles/local.css"); // (relative to /shared)
 *   $SEARCH    = array(
 *                  "method"      => "get",
 *                  "action"      => "/search.php",
 *                  "placeholder" => "Placeholder text",
 *                  "name"        => "input-name",
 *                  "hidden"      => array(array("name" => "hidden-input-name", "value" => "hidden-input-value")),
 *                ); // Search box, if any
 */
isset($TITLE)     || $TITLE     = "Hypertext Preprocessor";
isset($SUBDOMAIN) || $SUBDOMAIN = "";
isset($LINKS)     || $LINKS     = array();
isset($HEAD_WIKI) || $HEAD_WIKI = "";
isset($HEAD_RAND) || $HEAD_RAND = "";
isset($CSS)       || $CSS       = array();
isset($SEARCH)    || $SEARCH    = array();
$ROOT = substr($_SERVER["SERVER_NAME"], -8) == ".php.net" ? "//shared.php.net" : "/shared";
$current_time = time();
?>
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">

  <title>PHP: <?=$TITLE ?></title>

  <?=$HEAD_WIKI ?>
<?php
$styles = array_merge(array(
  '/styles/defaults.css'
), $CSS);
foreach($styles as $style):
  // note that $style should have a leading slash
  $filemtime = filemtime(__DIR__ . '/..' . $style) ?: $current_time;
  echo "  <link media='all' rel='stylesheet' href='{$ROOT}{$style}?filemtime=$filemtime'/>\n";
endforeach
?>

  <link href="//fonts.googleapis.com/css?family=Source+Sans+Pro:300,400,600,400italic,600italic|Source+Code+Pro&amp;subset=latin,latin-ext" rel="stylesheet">
  <link rel="shortcut icon" href="//php.net/favicon.ico">
<!--[if lt IE 9]>
  <script src="//shared.php.net/js/html5shiv.js"></script>
<![endif]-->
  <?=$HEAD_RAND?>
</head>
<body id="<?=$SUBDOMAIN?>">

<div class="wrap">
<header class='clearfix'>
  <div id="mainmenu-toggle-overlay"></div>
  <input type="checkbox" id="mainmenu-toggle">
  <nav class="fullscreen">
    <div class="mainscreen">
      <a href="/" class="home"><img src="//php.net/images/logo.php?<?=$SUBDOMAIN?>" width="48" height="24" alt="php"><span class="subdomain"><?=$SUBDOMAIN?></span></a>
      <ul>
<?php foreach($LINKS as $link): ?>
        <li><a href="<?=$link["href"]?>"><?=$link["text"]?></a></li>
<?php endforeach ?>
      </ul>
    </div>
<?php if ($SEARCH): ?>
    <div class="secondscreen">
      <form method="<?=$SEARCH["method"]?>" action="<?=$SEARCH["action"]?>">
        <input type="search" placeholder="<?=$SEARCH["placeholder"]?>" name="<?=$SEARCH["name"]?>" class="search">
<?php if(isset($SEARCH["hidden"])) foreach((array)$SEARCH["hidden"] as $entry): ?>
        <input type="hidden" name="<?=$entry["name"]?>" value="<?=$entry["value"]?>">
<?php endforeach ?>
      </form>
    </div>
<?php endif ?>
  </nav>
</header>
<div id="flash-message"></div>
<nav id="megadropdown"></nav>

<section class="fullscreen clearfix">

<?php /* vim: set ft=html et ts=2 sw=2: : */ ?>

