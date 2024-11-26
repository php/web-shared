<?php

/*
 * This is a very simple page to demonstrate the layout features of the shared
 * stylesheets.
 */

$available_styles = [ 'doc', 'master', 'people', 'qa', 'snaps', 'svn', 'wiki' ];

$requested_style = @$_REQUEST['style'];

$TITLE = "PHP Shared Test";
$LINKS = [
    [ 'href' => '//www.php.net', 'text' => 'Main website' ],
    [ 'href' => './', 'text' => 'Current' ],
    [ 'href' => '//example.com', 'text' => 'Example' ],
];
$HEAD_WIKI = '';
$HEAD_RAND = '';
if (in_array($requested_style, $available_styles)) {
  $SUBDOMAIN = "{$requested_style}(test)";
  $CSS[] = "/styles/{$requested_style}.css";
} else {
  $SUBDOMAIN = "test";
  $CSS = [ ];
}
$SEARCH = [
    'method' => 'get',
    'action' => '//php.net/search.php',
    'placeholder' => 'Text to search',
    'name' => 'pattern',
    'hidden' => [],
];
$CURRENT_PAGE = 'Current';

$lipsum = <<<LIPSUM
Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod
tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim
veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea
commodo consequat. Duis aute irure dolor in reprehenderit in voluptate
velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat
cupidatat non proident, sunt in culpa qui officia deserunt mollit anim
id est laborum.
LIPSUM;

$short_lipsum = implode('', array_slice(preg_split('/([.\?!])/', $lipsum, -1, PREG_SPLIT_NO_EMPTY | PREG_SPLIT_DELIM_CAPTURE), 0, 6));

$very_short_lipsum = implode('', array_slice(preg_split('/([.\?!])/', $lipsum, -1, PREG_SPLIT_NO_EMPTY | PREG_SPLIT_DELIM_CAPTURE), 0, 2));

require_once 'templates/header.inc';
?>

<section class="mainscreen">
  <h1>This is the H1</h1>

  <p><?= $lipsum ?>

  <h2>This is an H2</h2>

  <p><?= $short_lipsum ?>

  <h3>This is an H3</h3>

  <p>Text with a <sup>superscript</sup> and a <sub>subscript</sub>.

  <h4>This is an H4</h4>

  <p>This is a <a href="//www.php.net">link to the PHP website</a>.

  <h5>This is an H5</h5>

  <p><?= $short_lipsum ?>

  <h6>This is an H6</h6>

  <p><?= $very_short_lipsum ?>

  <h2>Warning</h2>

  <div class="warning">
    <?= $short_lipsum ?>
  </div>

  <h2>Lists</h2>

  <h3>Ordered List</h3>

  <ol>
    <li><?= $very_short_lipsum ?>
    <li><?= $very_short_lipsum ?>
    <li><?= $very_short_lipsum ?>
    <li><?= $very_short_lipsum ?>
      <ol>
        <li><?= $very_short_lipsum ?>
        <li><?= $very_short_lipsum ?>
      </ol>
    <li><?= $very_short_lipsum ?>
    <li><?= $very_short_lipsum ?>
    <li><?= $very_short_lipsum ?>
  </ol>

  <h3>Unordered List</h3>

  <ul>
    <li><?= $very_short_lipsum ?>
    <li><?= $very_short_lipsum ?>
    <li><?= $very_short_lipsum ?>
      <ul>
        <li><?= $very_short_lipsum ?>
        <li><?= $very_short_lipsum ?>
      </ul>
    <li><?= $very_short_lipsum ?>
    <li><?= $very_short_lipsum ?>
    <li><?= $very_short_lipsum ?>
  </ul>

  <h3>Definition List</h3>

  <dl>
    <dt>Definition term
    <dd><?= $short_lipsum; ?>
    <dt>Another definition
    <dd><?= $short_lipsum; ?>
  </dl>

  <h2>Horizontal Rule</h2>

  <hr>

  <h2>Code</h2>

  <pre><?php highlight_file('templates/footer.inc'); ?></pre>

  <h2>Table</h2>

  <table>
    <caption>Table caption</caption>
    <thead>
      <tr>
        <th>Column 1</th>
        <th>Column 2</th>
        <th>Column 3</th>
        <th>Column 4</th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <td>Column 1</td>
        <td>Column 2</td>
        <td>Column 3</td>
        <td>Column 4</td>
      </tr>
      <tr>
        <td>Column 1</td>
        <td>Column 2</td>
        <td>Column 3</td>
        <td>Column 4</td>
      </tr>
      <tr>
        <td>Column 1</td>
        <td>Column 2</td>
        <td>Column 3</td>
        <td>Column 4</td>
      </tr>
      <tr>
        <td>Column 1</td>
        <td>Column 2</td>
        <td>Column 3</td>
        <td>Column 4</td>
      </tr>
      <tr>
        <td>Column 1</td>
        <td>Column 2</td>
        <td>Column 3</td>
        <td>Column 4</td>
      </tr>
    </tbody>
    <tfoot>
      <tr>
        <th colspan="4">Table footer</th>
      </tr>
    </tfoot>
  </table>

  <h2>More text</h2>

  <p><?=$lipsum?>
</section>

<section class="secondscreen">
  <p><?= $short_lipsum ?>
  <h2>Styles</h2>
  <ul>
    <li><a href="<?= $_SERVER['PHP_SELF'] ?>">Default</a>
<?php foreach ($available_styles as $style):?>
    <li><a href="<?= $_SERVER['PHP_SELF'] . '?style=' . $style ?>"><?= $style ?></a>
<?php endforeach ?>
  </ul>
  <h2>Another H2</h2>
  <p><?= $short_lipsum ?>
</section>

<?php
require_once 'templates/footer.inc';
/* vim: set ft=php et ts=2 sw=2: : */
