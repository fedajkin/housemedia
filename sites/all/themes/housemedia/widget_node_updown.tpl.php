<?php

/**
 * @file
 * widget.tpl.php
 *
 * UpDown widget theme for Vote Up/Down
 */
?>
<div class="vud-widget vud-widget-updown" id="<?php print $id; ?>">

  <?php if ($show_links): ?>
    <?php if ($show_up_as_link): ?>
      <a href="<?php print $link_up; ?>" rel="nofollow" class="<?php print $link_class_up; ?>">
    <?php endif; ?>
        <div class="<?php print $class_up; ?> updown-up" title="<?php print t('Vote up!'); ?>">+</div>
        <?php /* <div class="element-invisible"><?php print t('Vote up!'); ?></div>*/ ?>
    <?php if ($show_up_as_link): ?>
      </a>
    <?php endif; ?>
  <?php endif; ?>
  
  <div class="updown-score">
    <?php print t('Rating'); ?>: <?php print $unsigned_points; ?>
  </div>
  
  <?php if ($show_links): ?>
    <?php if ($show_down_as_link): ?>
      <a href="<?php print $link_down; ?>" rel="nofollow" class="<?php print $link_class_down; ?>">
    <?php endif; ?>
        <div class="<?php print $class_down; ?> updown-down" title="<?php print t('Vote down!'); ?>">-</div>
        <?php /* <div class="element-invisible"><?php print t('Vote down!'); ?></div>*/ ?>
    <?php if ($show_down_as_link): ?>
      </a>
    <?php endif; ?>
  <?php endif; ?>
</div>