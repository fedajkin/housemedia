

<div id="group-vud-img">
	<?php if (!empty($node->field_group_image[0]['filepath'])): ?>
    <?php print theme('imagecache', 'scale_150x', $node->field_group_image[0]['filepath'])?>
  <?php endif; ?>
  <?php print $node->content['vud_node_widget_display']['#value']; ?>
</div>

<h1><?php print check_plain($node->title); ?></h1>
<?php print check_plain($node->og_description); ?>

<ul class="group-summary">
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

<?php
// dsm($node);


