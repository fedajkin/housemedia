<?php
/**
 * Arguments:
 * $node: marker node, which will be templated.
 * $content: Content prepared at preprocessed part
 */
?>
<div>
  <?php if ($node->type == 'doradca'): ?>

  <?php print $advisor_title; ?><br />
  <?php if (!empty($advisor_name)): ?>
    <?php print $advisor_name; ?><br />
  <?php endif; ?>

  <?php if (!empty($advisor_company)): ?>
    <?php print $advisor_company; ?>
  <?php endif; ?>

  <?php if (!empty($advisor_phone)): ?>
    <?php print $advisor_phone; ?>
  <?php endif; ?>

  <?php elseif($node->type == 'group'): ?>

    <?php print $invest_title; ?><br />
    <?php print $invest_photo; ?><br />
    <?php print $invest_developer_description; ?><br />
    <?php print t('Free flats: @count', array("@count" => (int) $invest_free_flats)); ?><br />
    <?php print $invest_subscribe_toggle; ?>
    <?php print $invest_forum; ?>

  <?php elseif($node->type == 'mieszkanie'): ?>

    <?php print l($node->title, 'node/'. $node->nid); ?>
    <?php print $flat_room_count ?>
    <?php print $flat_stock; ?>
    <?php print $flat_levels; ?>
    <?php print $flat_price_one_meter; ?>
    <?php print $flat_full_price; ?>

  <?php endif; ?>
</div>
