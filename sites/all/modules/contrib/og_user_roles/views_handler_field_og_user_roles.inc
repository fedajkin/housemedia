<?php
// $Id: views_handler_field_og_user_roles.inc,v 1.0 2010/08/08 17:34:00 destination_node Exp $
/**
 * Field handler to provide a list of roles.
 */
class views_handler_field_og_user_roles extends views_handler_field_prerender_list {
  function construct() {
    parent::construct();
    $this->additional_fields['uid'] = array('table' => 'users', 'field' => 'uid');
    $this->additional_fields['gid'] = array('table' => 'og_uid', 'field' => 'nid');
    }

  function query() {
    $this->add_additional_fields();
    $this->field_alias = $this->aliases['uid'];
  }

  function pre_render($values) {
    $uids = array();
    $this->items = array();

    foreach ($values as $result) {
      $uid = $result->{$this->aliases['uid']};
      $gid = $result->{$this->aliases['gid']};
      if ($gid) {
        $result = db_query("SELECT u.uid, u.rid, r.name FROM {role} r INNER JOIN {og_users_roles} u ON u.rid = r.rid WHERE u.uid = $uid AND u.gid = $gid ORDER BY r.name");

        while ($role = db_fetch_object($result)) {
          $this->items[$uid][$role->rid]['role'] = check_plain($role->name);
          $this->items[$uid][$role->rid]['rid'] = $role->rid;
          $this->items[$uid][$role->rid]['gid'] = $role->gid;

        }
      }
    }
  }

  function render_item($count, $item) {
    return $item['role'];
  }

  /**
   * Render all items in this field together.
   *
   * When using advanced render, each possible item in the list is rendered
   * individually. Then the items are all pasted together.
   */
  function render_items($items) {
    if (!empty($items)) {
      if ($this->options['type'] == 'separator') {
        return implode(check_plain($this->options['separator']), $items);
      }
      else {
        return theme('item_list', $items, NULL, $this->options['type']);
      }
    }
  }
}
