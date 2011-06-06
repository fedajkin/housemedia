<?php
// $Id: twocol-70-30.tpl.php 8347 2011-03-02 01:44:22Z sheena $
/**
 * @file
 * Template for a 2 column panel layout.
 *
 * This template provides a two column 30%-70% panel display layout.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['left']: Content in the left column.
 *   - $content['right']: Content in the right column.
 */
?>
<div class="panel-display twocol-70-30 clearfix" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="panel-panel panel-col-first">
    <div class="inner"><?php print $content['left']; ?></div>
  </div>
  <div class="panel-panel panel-col-last">
    <div class="inner"><?php print $content['right']; ?></div>
  </div>
</div>