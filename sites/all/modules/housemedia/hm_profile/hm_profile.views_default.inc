<?php

/**
 * Implementation of hook_views_default_views().
 */
function hm_profile_views_default_views() {
  $views = array();

  // Exported view: hm_profile_friends
  $view = new view;
  $view->name = 'hm_profile_friends';
  $view->description = '';
  $view->tag = 'hm_profile';
  $view->view_php = '';
  $view->base_table = 'users';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'requestee_id' => array(
      'label' => 'requestee',
      'required' => 0,
      'id' => 'requestee_id',
      'table' => 'user_relationships',
      'field' => 'requestee_id',
      'relationship' => 'none',
    ),
    'requester_id' => array(
      'label' => 'requester',
      'required' => 0,
      'id' => 'requester_id',
      'table' => 'user_relationships',
      'field' => 'requester_id',
      'relationship' => 'none',
    ),
    'rtid' => array(
      'label' => 'rtid',
      'required' => 0,
      'id' => 'rtid',
      'table' => 'user_relationships',
      'field' => 'rtid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'picture' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => 'd',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'imagecache_preset' => 'group_images_thumb',
      'exclude' => 0,
      'id' => 'picture',
      'table' => 'users',
      'field' => 'picture',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'random' => array(
      'order' => 'ASC',
      'id' => 'random',
      'table' => 'views',
      'field' => 'random',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array(
    'requester_id' => array(
      'default_action' => 'default',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'Wszystko',
      'title' => '',
      'breadcrumb' => '',
      'default_argument_type' => 'php',
      'default_argument' => '',
      'validate_type' => 'none',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'requester_id',
      'table' => 'user_relationships',
      'field' => 'requester_id',
      'validate_user_argument_type' => 'uid',
      'validate_user_roles' => array(
        '2' => 0,
        '3' => 0,
        '4' => 0,
        '6' => 0,
        '7' => 0,
        '9' => 0,
        '10' => 0,
        '5' => 0,
        '8' => 0,
      ),
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_fixed' => '',
      'default_argument_user' => 0,
      'default_argument_php' => 'if ($_GET[\'q\'] == \'stream\') {
  return $GLOBALS[\'user\']->uid;
}
else if ($account = _commons_profile_get_current_user()) {
  return $account->uid;
}',
      'validate_argument_node_type' => array(
        'blog' => 0,
        'document' => 0,
        'event' => 0,
        'faq' => 0,
        'credit_form' => 0,
        'inw_detal' => 0,
        'news' => 0,
        'deweloper' => 0,
        'doradca' => 0,
        'uzytkownik' => 0,
        'promotion' => 0,
        'forum' => 0,
        'group' => 0,
        'notice' => 0,
        'page' => 0,
        'dew_szczegoly' => 0,
        'grupa_powitanie' => 0,
        'mieszkanie' => 0,
        'opis_dewelopera' => 0,
        'opis_inwestycji' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '4' => 0,
        '5' => 0,
        '2' => 0,
        '3' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_transform' => 0,
      'validate_user_restrict_roles' => 0,
      'validate_argument_node_flag_name' => '*relationship*',
      'validate_argument_node_flag_test' => 'flaggable',
      'validate_argument_node_flag_id_type' => 'id',
      'validate_argument_user_flag_name' => '*relationship*',
      'validate_argument_user_flag_test' => 'flaggable',
      'validate_argument_user_flag_id_type' => 'id',
      'validate_argument_is_member' => 'OG_VIEWS_DO_NOT_VALIDATE_MEMBERSHIP',
      'validate_argument_group_node_type' => array(
        'group' => 0,
      ),
      'validate_argument_php' => '',
      'override' => array(
        'button' => 'Nadpisz',
      ),
      'default_argument_activity_log_stream_owner_type' => 'user',
    ),
  ));
  $handler->override_option('filters', array(
    'approved' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'approved',
      'table' => 'user_relationships',
      'field' => 'approved',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'users',
      'field' => 'status',
      'relationship' => 'none',
    ),
    'rtype' => array(
      'operator' => 'not in',
      'value' => array(
        '0' => '2',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => 'rtype_op',
        'label' => 'User relationships: Relationship type',
        'use_operator' => FALSE,
        'identifier' => 'rtype',
        'remember' => FALSE,
        'single' => TRUE,
        'optional' => TRUE,
        'reduce' => FALSE,
      ),
      'id' => 'rtype',
      'table' => 'user_relationships',
      'field' => 'rtype',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Nadpisz',
      ),
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Znajomi');
  $handler->override_option('use_ajax', TRUE);
  $handler->override_option('items_per_page', 12);
  $handler->override_option('use_pager', 'mini');
  $handler->override_option('style_plugin', 'grid');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'columns' => '4',
    'alignment' => 'horizontal',
    'fill_single_line' => 1,
  ));
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->override_option('block_description', 'Current user\'s friends');
  $handler->override_option('block_caching', -1);

  $views[$view->name] = $view;

  return $views;
}
