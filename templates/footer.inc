<?php
/**
 * Typical footer
 *
 * Required variables:
 *
 *   $JS = array("//example.com/external.js", "/shared/js/local.js");
 */

isset($JS) || $JS = array();
?>
</section><!-- .fullscreen -->
<footer>
  <nav class="fullscreen">
    <ul>
      <li><a href="//php.net/copyright">Copyright © 2001-2013 The PHP Group</a></li>
      <li><a href="//php.net/site">Other PHP.net sites</a></li>
      <li><a href="//php.net/privacy">Privacy policy</a></li>
    </ul>
  </nav>
</footer>

<?php foreach($JS as $script) :?>
<script type="text/javascript" src="<?=$script?>"></script>
<?php endforeach ?>
</body>
</html>
<?php /* vim: set ft=html et ts=2 sw=2: : */ ?>
