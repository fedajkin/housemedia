<?php
// $Id: og_reg_keys.views_default.inc,v 1.1.2.1 2009/11/01 22:08:08 marcp Exp $

/**
 * Implementation of hook_views_default_views().
 *
 */
function og_reg_keys_views_default_views() {
  $views = array();
  
  $view = new view;
  $view->name = 'og_reg_keys_edit';
  $view->description = 'Display group registration keys';
  $view->tag = 'og';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'title' => array(
      'label' => 'Group',
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'name' => array(
      'label' => 'Manager',
      'link_to_user' => 1,
      'exclude' => 0,
      'id' => 'name',
      'table' => 'users',
      'field' => 'name',
      'relationship' => 'none',
    ),
    'code' => array(
      'label' => 'Registration key',
      'exclude' => 0,
      'id' => 'code',
      'table' => 'og_reg_keys',
      'field' => 'code',
      'relationship' => 'none',
    ),
    'edit_node' => array(
      'label' => 'Edit registration key',
      'text' => 'edit',
      'exclude' => 0,
      'id' => 'edit_node',
      'table' => 'node',
      'field' => 'edit_node',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'type_groups_all' => array(
      'operator' => '=',
      'value' => '',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type_groups_all',
      'table' => 'og',
      'field' => 'type_groups_all',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('items_per_page', 50);
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_plugin', 'table');
  
  $views['og_reg_keys_edit'] = $view;
    
  return $views;
}
