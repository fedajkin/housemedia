<?php
// $Id: slider.tpl.php,v 1.1 2008/10/15 10:04:25 marktheunissen Exp $

/**
 * @file slider.tpl.php
 * Default output for a slider node.
 */

?>
<?php if ($valid_slider): ?>

  <div id="sliderwrapper">
    <div id="slider">

      <?php if ($tabs_position): ?>
        <div class="scroll">
          <div class="scrollContainer">
            <?php print $slider_content_formatted ?>
          </div>
        </div>
        <?php print $tabs_formatted ?>

      <?php else: ?>
        <?php print $tabs_formatted ?>
        <div class="scroll">
          <div class="scrollContainer">
            <?php print $slider_content_formatted ?>
          </div>
        </div>

      <?php endif; ?>

      <div class="clear-block"></div>
    </div>
  </div>

<?php else: ?>

  <div id="sliderwrapper">
    <?php print t('An error has occurred while trying to create this slider.') ?>
  </div>

<?php endif; ?>
