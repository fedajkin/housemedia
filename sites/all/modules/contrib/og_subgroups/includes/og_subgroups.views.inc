<?php

/**
 * @file Contains the Views api functions 
 */

/**
 * Implementation of hook_views_handlers().
 */
function og_subgroups_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'og_subgroups') .'/includes',
    ),
    'handlers' => array(
      // arguments
      'og_subgroups_views_handler_argument_gid' => array(
        'parent' => 'views_handler_argument_numeric',
      ),
      'og_subgroups_views_handler_argument_parent' => array(
        'parent' => 'views_handler_argument_numeric',
      ),
      'og_subgroups_views_handler_argument_content' => array(
        'parent' => 'og_subgroups_views_handler_argument_gid',
      ),
      // fields
      'og_subgroups_views_handler_field_children' => array(
        'parent' => 'views_handler_field_prerender_list',
      ),
      'og_subgroups_views_handler_field_parent_title' => array(
        'parent' => 'views_handler_field',
      ),
      // filters
      'og_subgroups_views_handler_filter_og_group_nid_override' => array(
        'parent' => 'views_handler_filter_many_to_one',
      ),
      // sorts
      'og_subgroups_views_handler_sort_hierarchy' => array(
        'parent' => 'views_handler_sort',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_data().
 */
function og_subgroups_views_data() {
  $data['og_subgroups']['table']['group']  = t('OG Subgroups');
  $data['og_subgroups']['table']['join']['node'] = array(
    'left_field' => 'nid',
    'field' => 'gid',
    'type' => 'left',
  );

  $data['og_subgroups']['gid'] = array(
    'title' => t('Group ID'),
    'help' => t('Use the nid of a group as a starting point to retrieve other groups in the hierarchy.'),
    'argument' => array(
      'handler' => 'og_subgroups_views_handler_argument_gid',
    ),
    'field' => array(
      'title' => t('Child Groups'),
      'help' => t('List of child groups nested under a parent.'),
      'handler' => 'og_subgroups_views_handler_field_children',
    ),
    'sort' => array(
      'title' => t('Hierarchy Order'),
      'help' => t('Sort the groups by the order in which they appear in the subgroup tree.'),
      'handler' => 'og_subgroups_views_handler_sort_hierarchy',
    ),
  );

  $data['og_subgroups']['parent'] = array(
    'title' => t('Parent Group ID'),
    'help' => t('The Node ID of the parent group.'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'argument' => array(
      'help' => t('The group ID of a parent node. Filters for groups that has the specified parent(s)'),
      'handler' => 'og_subgroups_views_handler_argument_parent',
    ),
  );

  $data['og_subgroups']['parent_title'] = array(
    'title' => t('Parent Group Title'),
    'help' => t('The Node title of the parent group.'),
    'real field' => 'gid',
    'field' => array(
      'handler' => 'og_subgroups_views_handler_field_parent_title',
    ),
  );

  // Use the og_ancestry as an aliased table.
  $data['og_subgroups_posts']['table']['group']  = t('OG Subgroups');
  $data['og_subgroups_posts']['table']['join']['node'] = array(
    'table' => 'og_ancestry',
    'left_field' => 'nid',
    'field' => 'nid',
  );

  $data['og_subgroups_posts']['content'] = array(
    'title' => t('Group ID'),
    'help' => t('<strong>Posts</strong> are filtered for specified branches of the subgroup tree'),
    'argument' => array(
      'handler' => 'og_subgroups_views_handler_argument_content',
      'field' => 'group_nid',
      'numeric' => TRUE,
    ),
  );

  return $data;
}

/**
 * Implementation of hook_views_data_alter().
 */
function og_subgroups_views_data_alter(&$data) {
  $data['og_ancestry']['group_nid']['filter']['handler'] = 'og_subgroups_views_handler_filter_og_group_nid_override';
}