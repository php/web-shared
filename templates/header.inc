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
 *   $SEARCH    = array(
 *                  "method"      => "get",
 *                  "action"      => "/search.php",
 *                  "placeholder" => "Placeholder text",
 *                  "name"        => "input-name",
 *                ); // Search box, if any
 */
?>
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">

  <title>PHP: <?=$TITLE ?></title>
  <link type="text/css" media="all" rel="stylesheet" href="/shared/styles/defaults.css">
  <link href="http://fonts.googleapis.com/css?family=Source+Sans+Pro:400,600,400italic,600italic|Source+Code+Pro&subset=latin,latin-ext" rel="stylesheet" type="text/css">
  <link rel="shortcut icon" href="//php.net/favicon.ico">
</head>
<body id="<?=$SUBDOMAIN?>">

<header>
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
      </form>
    </div>
<?php endif ?>
  </nav>
</header>

<section class="fullscreen">


<?php /* vim: set ft=html et ts=2 sw=2: : */ ?>

