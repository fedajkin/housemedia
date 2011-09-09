<?php

/**
 * Callback for hook_block()
 */
function _hm_group_block($op = 'list', $delta = 0, $edit = array()) {
  switch ($op) {
    case 'list':
      $function = '_hm_group_block_list';
      break;
    case 'view':
    case 'configure':
    case 'save':
      $function = "_hm_group_{$delta}_block_{$op}";
      break;
  }
  
  if ($function && function_exists($function)) {
    return call_user_func($function, $edit); 
  }
}

/**
 * Declare a list of all the available blocks
 */
function _hm_group_block_list() {
  $blocks = array();
  $blocks['info_tabs'] = array(
    'info'  => t('Group info tabs'),
    'cache' => BLOCK_NO_CACHE
  );
  $blocks['members'] = array(
    'info'  => t('Group members'),
    'cache' => BLOCK_NO_CACHE
  );
  return $blocks;
}

function _hm_group_info_tabs_block_view() {
  
  $quicktabs['qtid']  = 'hm_group_info_tabs';
  $quicktabs['ajax']  = FALSE;
  $quicktabs['style'] = 'nostyle';
  $quicktabs['tabs']  = array(
    '0' => array(
  		'title'   => t('Description'),
      'type'    => 'node',
      'nid'     => arg(1),
      'teaser'	=> 0
    ),
    '1' => array(
  		'title'   => t('Details'),
      'type'    => 'view',
      'vid'     => 'hm_investment_node',
      'display' => 'block_1',
    ),
    '2' => array(
  		'title'   => t('Gallery'),
      'type'    => 'view',
      'vid'     => 'hm_group_gallery',
      'display' => 'block_1',
    ),
    '3' => array(
  		'title'   => t('Flats'),
      'type'    => 'view',
      'vid'     => 'mieszkania',
      'display' => 'block_1',
    ),
    '4' => array(
  		'title'   => t('Promotions'),
      'type'    => 'view',
      'vid'     => 'hm_promotion_group',
      'display' => 'block_1',
    )
  );

  
  return array(
    'subject' => '',
    'content' => theme('quicktabs', $quicktabs)
  );
}

function _hm_group_members_block_view() {
  // Detect the group context
  if ($group = og_features_get_group_context()) {
    // Count the number of group members for the block title
    $sql = "SELECT count(uid) FROM {og_uid} WHERE nid = %d AND is_active = 1";
    $count = db_result(db_query($sql, $group->nid));
      
    // Load the group managers from the view
    if ($view = views_get_view('hm_group_block_members')) {
      if ($output = $view->execute_display('block_1')) {
        $managers = $output['content'];
      }
      $view->destroy();
    }
    
    // Load the group members from the view
    if ($view = views_get_view('hm_group_block_members')) {
      if ($output = $view->execute_display('block_2')) {
        $residents = $output['content'];
      }
      $view->destroy();
    }
    
    if ($view = views_get_view('hm_group_block_members')) {
      if ($output = $view->execute_display('block_3')) {
        $guests = $output['content'];
      }
      $view->destroy();
    }
    
    // Add a link to view all the members
    $link = og_is_group_admin($group) ? l(t('View all members'), "og/users/{$group->nid}/faces") : NULL;
    
    return array(
      'subject' => t('Group members (!count)', array('!count' => $count)),
      'content' => theme('hm_group_members_block', $managers, $residents, $guests, $link),
    );
  }
  
  return NULL;
}
