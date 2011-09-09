<?php
// $Id: og_reg_keys.views.inc,v 1.1 2008/11/26 19:42:21 marcp Exp $

/**
 * Implementation of hook_views_data().
 */
function og_reg_keys_views_data() {
  $data = array(
    'og_reg_keys' => array(
      'table' => array(
        'group' => t('Organic groups'),
        'join' => array(
          'node' => array(
            'left_field' => 'nid',
            'field' => 'nid'
          )
        )
      ),
      'code' => array(
        'title' => t('Og_reg_keys: Registration key'),
        // Information for displaying the registration key
        'field' => array(
          'handler' => 'views_handler_field',
          'click sortable' => FALSE,
          'help' => t('The registration key for a group.'),
        ),
      ),
      'editlink' => array(
        'title' => t('Og_reg_keys: Group edit link'),
        // Information for displaying the registration key
        'field' => array(
          'handler' => 'og_reg_keys_handler_field_group_edit_link',
          'click sortable' => FALSE,
          'help' => t('Link to edit the registration key for a group.'),
       ),
      ),
    )
  );
  
  return $data; 
}
