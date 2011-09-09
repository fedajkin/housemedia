

<div id="group-vud-img" class="clearfix">
	<?php if (!empty($node->field_group_image[0]['filepath'])): ?>
    <?php print theme('imagecache', 'scale_150x', $node->field_group_image[0]['filepath'])?>
  <?php endif; ?>
</div>

<h1><?php print check_plain($node->title); ?></h1>
<p><?php print check_plain($node->og_description); ?></p>

