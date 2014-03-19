<?php
/**
 * Typical footer
 *
 * Required variables:
 *
 *   // Relative to /share, or prefixed with // for external js
 *   $JS = array("//example.com/external.js", "/js/local.js");
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
      <li><a href="//php.net/copyright">Copyright © 2001-2014 The PHP Group</a></li>
      <li><a href="//php.net/sites">Other PHP.net sites</a></li>
      <li><a href="//php.net/privacy">Privacy policy</a></li>
    </ul>
  </nav>
</footer>

<script src="//ajax.googleapis.com/ajax/libs/jquery/1.10.2/jquery.min.js"></script>
<script src="<?php echo $ROOT?>/js/external/mousetrap.min.js"></script>
<script src="<?php echo $ROOT?>/js/common.js"></script>
<?php foreach($JS as $script) :?>
  <?php if (strncmp($script, "//", 2) == 0): ?>
    <script src="<?php echo $script?>"></script>
  <?php else: ?>
    <script src="<?php echo $ROOT ?><?php echo $script?>"></script>
  <?php endif ?>
<?php endforeach ?>
</body>
</html>
<?php /* vim: set ft=html et ts=2 sw=2: : */ ?>
