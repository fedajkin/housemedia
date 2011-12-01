<?php
/**
 * Arguments:
 * $node: marker node, which will be templated.
 * $content: Content prepared at preprocessed part
 */
?>
<div>

  <?php if($node->type == 'group'): ?>
    <?php print $invest_developer_description; ?><br />
    <?php print t('Free flats: @count', array("@count" => (int) $invest_free_flats)); ?><br />
    <?php print $flats_list; ?>
  <?php endif; ?>
</div>
