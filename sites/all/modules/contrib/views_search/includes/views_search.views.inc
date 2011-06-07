<?php

/**
 * @file
 * Views integration and default view implementations for Views Search module.
 */

/**
 * Implementation of hook_views_data()
 */
function views_search_views_data() {

  $data = array();

  $data['views_search']['table'] = array(
    'group' => t("Views Search"),
    'title' => t("Views Saved Searches"),
    'help' => t("Search views saved by a user."),
  );

  $data['views_search']['table']['base'] = array(
    'field' => 'ssid',
    'title' => 'Saved Searches',
    'help' => t("Sets of search filters saved by a user."),
    'weight' => 10,
  );

  $data['views_search']['uid'] = array(
    'title' => t('User ID'),
    'help' => t('User ID of the user that saved a search.'),
    'field' => array(
      'handler' => 'views_handler_field_user',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_user_uid',
      'name field' => 'name',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_user_current',
      'type' => 'yes-no',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['views_search']['created'] = array(
    'title' => t('Timestamp of Saved Search'),
    'help' => t('Timestamp when the saved search was created.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['views_search']['view_name'] = array(
    'title' => t('View Name'),
    'help' => t('Machine name of saved view'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['views_search']['view_display'] = array(
    'title' => t('Display ID'),
    'help' => t('Display ID of saved view'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['views_search']['name'] = array(
    'title' => t('Saved Search Name'),
    'help' => t('Name of the Saved Search'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['views_search']['filters'] = array(
    'title' => t('Saved Search Filters'),
    'help' => t('Saved Search Filters'),
    'field' => array(
      'click sortable' => FALSE,
    ),
  );

  return $data;

}



/**
 * Implementation of hook_views_default_views().
 */
function views_search_views_default_views() {
  /*
   * View 'views_saved_searches'
   */
  $view = new view;
  $view->name = 'views_saved_searches';
  $view->description = 'Shows saved search for the current user.';
  $view->tag = 'views_search';
  $view->view_php = '';
  $view->base_table = 'views_search';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'name' => array(
      'label' => 'Saved Search Name',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
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
      'exclude' => 0,
      'id' => 'name',
      'table' => 'views_search',
      'field' => 'name',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
    'view_name' => array(
      'label' => 'Search Type',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
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
      'exclude' => 0,
      'id' => 'view_name',
      'table' => 'views_search',
      'field' => 'view_name',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'nothing' => array(
      'label' => 'Actions',
      'alter' => array(
        'text' => '',
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
      'exclude' => 0,
      'id' => 'nothing',
      'table' => 'views',
      'field' => 'nothing',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'name' => array(
      'order' => 'ASC',
      'id' => 'name',
      'table' => 'views_search',
      'field' => 'name',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'uid' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'uid',
      'table' => 'views_search',
      'field' => 'uid',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'role',
    'role' => array(
      '2' => 2,
    ),
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Saved Searches');
  $handler->override_option('empty_format', '1');
  $handler->override_option('use_more', 1);
  $handler->override_option('use_more_always', 1);
  $handler->override_option('use_more_text', 'Manage Your Saved Searches');
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 1,
    'order' => 'asc',
    'columns' => array(
      'name' => 'name',
      'view_name' => 'view_name',
      'nothing' => 'nothing',
    ),
    'info' => array(
      'name' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'view_name' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'nothing' => array(
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('empty', 'You don\'t have any Saved Searches.');
  $handler->override_option('path', 'search/saved');
  $handler->override_option('menu', array(
    'type' => 'normal',
    'title' => 'Saved Searches',
    'description' => 'Manage your Saved Searches',
    'weight' => '50',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->override_option('fields', array(
    'name' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
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
      'exclude' => 0,
      'id' => 'name',
      'table' => 'views_search',
      'field' => 'name',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
  ));
  $handler->override_option('block_description', 'Saved Searches');
  $handler->override_option('block_caching', -1);
  $views[$view->name] = $view;

  return $views;
}