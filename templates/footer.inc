<?php
/**
 * Typical footer
 *
 * Required variables:
 *
 *   // Relative to /share, or prefixed with // for external js
 *   $JS = array("//example.com/external.js", "/js/local.js");
 *
 *   or, to avoid including the common JS altogether:
 *   $JS = false;
 */

isset($JS) || $JS = array();
isset($SECONDSCREEN) || $SECONDSCREEN = "";
$ROOT = substr($_SERVER["SERVER_NAME"], -8) == ".php.net" ? "//shared.php.net" : "/shared";
?>
<?php if ($SECONDSCREEN): ?>
<section class="secondscreen">
  <?=$SECONDSCREEN?>
</section>
<?php endif ?>
</section><!-- .fullscreen -->
<footer>
  <nav class="fullscreen">
    <ul>
      <li><a href="//php.net/copyright">Copyright © 2001-<?php echo date('Y'); ?> The PHP Group</a></li>
      <li><a href="//php.net/sites">Other PHP.net sites</a></li>
      <li><a href="//php.net/privacy">Privacy policy</a></li>
    </ul>
  </nav>
</footer>

<?php
if ($JS !== false) {
  $current_time = time();
  $scripts = array_merge(array(
    '//ajax.googleapis.com/ajax/libs/jquery/2.1.1/jquery.min.js',
    '/js/external/mousetrap.min.js',
    '/js/common.js'
  ), $JS);
  foreach ($scripts as $script):
    if (strncmp($script, "//", 2) == 0) {
      echo "<script src='$script'></script>\n";
    } else {
      $filemtime = filemtime(__DIR__ . "/..{$script}") ?: $current_time;
      echo "<script src='{$ROOT}{$script}?filemtime=$filemtime'></script>\n";
    }
  endforeach;
} ?>
</div><!-- .wrap -->
</body>
</html>
<?php /* vim: set ft=html et ts=2 sw=2: : */ ?>
