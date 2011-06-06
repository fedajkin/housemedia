<?php
// $Id: user_relationships-actions_block.tpl.php 8347 2011-03-02 01:44:22Z sheena $
/**
 * @file 
 * Template of relationships add/remove block
 * List of current relationships to the viewed user
 */
$output = array();

if ($current_relationships) {
  $output[] = theme('item_list', $current_relationships, t('Your relationships to this user'), 'ul', array('class' => 'user_relationships'));
}

// List of actions that can be taken between the current and viewed user
if ($actions) {
  $output[] = theme('item_list', $actions, NULL, 'ul', array('class' => 'user_relationships_actions'));
}

print implode('', $output);

?>