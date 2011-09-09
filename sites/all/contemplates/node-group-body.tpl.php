

<div id="group-vud-img" class="clearfix">
	<?php if (!empty($node->field_group_image[0]['filepath'])): ?>
    <?php print theme('imagecache', 'scale_150x', $node->field_group_image[0]['filepath'])?>
  <?php endif; ?>
  <?php print $node->content['vud_node_widget_display']['#value']; ?>
</div>

<h1><?php print check_plain($node->title); ?></h1>
<p><?php print check_plain($node->og_description); ?></p>

<div class="group-links clearfix">
  <?php print l(t('Forum'), 'node/'. $node->nid .'/content/forum/view'); ?>
  <?php foreach (_hm_group_subscribe_link($node) as $l): ?>
    <?php print $l; ?>
  <?php endforeach; ?>
</div>

<ul class="group-summary">
	<?php if ($node->available_flats): ?>
		<li class="available-flats">
		  <?php print t('Number of available flats'); ?>:
		  <?php print $node->available_flats; ?>
		</li>
	<?php endif; ?>
	
	<?php if ($node->completion_date): ?>
		<li class="completion-date">
		  <?php print t('Completion date'); ?>:
		  <?php print format_date($node->completion_date, 'custom', 'd F Y'); ?>
		</li>
	<?php endif; ?>
	
	<?php if ($gp = og_subgroups_get_parent($node->nid)): ?>
		<li>
			<?php print t('Developer'); ?>:
      <?php print l($gp['title'], 'node/'. $gp['gid']); ?>
  	</li>
  <?php endif; ?>

	<li>
	  <?php print t('Updated'); ?>: 
	  <?php print format_date($node->changed, 'custom', 'd F Y'); ?>
	</li>
</ul>


