<?php
/**
 * Typical header
 *
 * Required variables:
 *
 *   $TITLE     = "Awesome Website"; // Page title
 *   $SUBDOMAIN = "people"; // Subdomain/Project
 *   $LINKS     = array(
 *   $HEAD_RAND = ""; // Random extra values needed for in <head>
 *                  array("href" => "/link.php", "text" => "Link text")
 *                ); // Menu menu links
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
isset($HEAD_RAND) || $HEAD_RAND = "";
isset($CSS)       || $CSS       = array();
isset($SEARCH)    || $SEARCH    = array();
$ROOT = substr($_SERVER["SERVER_NAME"], -8) == ".php.net" ? "//shared.php.net" : "/shared";
?>
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">

  <title>PHP: <?=$TITLE ?></title>
  <link type="text/css" media="all" rel="stylesheet" href="<?php echo $ROOT?>/styles/defaults.css">

<?php foreach($CSS as $style): ?>
  <link type="text/css" media="all" rel="stylesheet" href="<?php echo $ROOT?><?php echo $style?>">
<?php endforeach ?>

  <link href="//fonts.googleapis.com/css?family=Source+Sans+Pro:400,600,400italic,600italic|Source+Code+Pro&subset=latin,latin-ext" rel="stylesheet" type="text/css">
  <link rel="shortcut icon" href="//php.net/favicon.ico">
  <?=$HEAD_RAND?>
</head>
<body id="<?=$SUBDOMAIN?>">

<header>
  <div id="mainmenu-toggle-overlay"></div>
  <input type="checkbox" id="mainmenu-toggle">
  <nav class="fullscreen">
    <div class="mainscreen">
      <a href="/" class="home"><img src="//php.net/images/logo.php?<?=$SUBDOMAIN?>" width="72" height="36" alt="php"><span class="subdomain"><?=$SUBDOMAIN?></span></a>
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

<section class="fullscreen">


<?php /* vim: set ft=html et ts=2 sw=2: : */ ?>

