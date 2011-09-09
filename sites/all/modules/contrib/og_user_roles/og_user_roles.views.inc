<?php
/**
 * Implementation of hook_views_data().
 */
function og_user_roles_views_data() {

  $data['og_users_roles']['table']['group']  = t('Organic groups Roles');

  $data['og_users_roles']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'left_table' => 'og_uid',
      'field' => 'uid',
      'handler' => 'og_users_roles_join_handler',
    ),
  );

  $data['og_users_roles']['rid'] = array(
    'title' => t('OG Roles'),
    'help' => t('Roles of user'),
    'field' => array(
      'handler' => 'views_handler_field_og_user_roles',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_user_roles',
    ),
    'sort' => array(
       'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_users_roles_rid',
      'name table' => 'role',
      'name field' => 'name',
      'empty field name' => t('No role'),
      'numeric' => TRUE,
    ),
  );
  return $data;
}

/**
 * There is not an easy way to define this join and allow it to handle aliases.
 */
class og_users_roles_join_handler extends views_join {
  // PHP 4 doesn't call constructors of the base class automatically from a
  // constructor of a derived class. It is your responsibility to propagate
  // the call to constructors upstream where appropriate.
  function construct($table = NULL, $left_table = NULL, $left_field = NULL, $field = NULL, $extra = array(), $type = 'LEFT') {
    parent::construct($table, $left_table, $left_field, $field, $extra, $type);
  }

  function join($table, &$query) {
    $output = parent::join($table, $query);
    $left = $query->get_table_info($this->left_table);
    $output .= " AND $left[alias].nid = $table[alias].gid";
    return $output;
  }
}

/**
 * Implementation of hook_views_handlers() to register all of the basic handlers
 * views uses.
 */
function og_user_roles_views_handlers() {
  return array(
    'handlers' => array(
      'views_handler_field_og_user_roles' => array(
        'parent' => 'views_handler_field_prerender_list',
      ),
    ),
  );
}
