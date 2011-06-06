<?php
// $Id$ 

/*!
 * Dynamic display block module template: plain-list30l - pager template
 * Copyright (c) 2008 - 2009 P. Blaauw All rights reserved.
 * Version 1.0 (20-DEC-2009)
 * Licenced under GPL license
 * http://www.gnu.org/licenses/gpl.html
 */

 /**
 * @file
 * Dynamic display block module template: plain-list30l - pager template
 * - Custom pager with images and text
 *
 * Available variables:
 * - $delta: Block number of the block.
 * - $pager: Type of pager to add
 * - $pager_items: pager item array
 * - $pager_position: position of the slider (right | left) 
 *
 * notes: don't change the ID names, they are used by the jQuery script.
 */
 $number_of_items = 6;        // total number of items to show  
 $number_of_items_per_row=6;  // number of items to show in a row
?>
<!-- custom pager with images and text. -->
<div id="ddblock-custom-pager-<?php print $delta ?>" class="<?php print $pager ?> <?php print $pager ?>-<?php print $pager_position ?> clear-block">
 <div  class="<?php print $pager ?>-inner" class="clear-block border">
  <?php if ($pager_items): ?>
   <?php $item_counter=0; ?>
   <ul>
   <?php foreach ($pager_items as $pager_item): ?>
    <div class="custom-pager-item">
    <li>
      <a href="#" title="navigate to topic" class="pager-link"><?php print $pager_item['text']; ?></a>
    </li> <!-- /custom-pager-item -->
    </div>
    <?php $item_counter++; if ($item_counter % $number_of_items_per_row <> 0):?>
     <?php if ($item_counter <> $number_of_items): ?>
       <div class="spacer-horizontal"><b></b></div>
     <?php endif; ?>  
    <?php endif; ?>  
   <?php endforeach; ?>
   </ul>
  <?php endif; ?>
 </div> <!-- /pager-inner-->
</div>  <!-- /pager-->