<?php
class og_subgroups_views_handler_field_children extends views_handler_field_prerender_list {

  function init(&$view, $options) {
    parent::init($view, $options);
    $this->additional_fields['node_nid'] = array('table' => 'node', 'field' => 'nid');
    $this->additional_fields['og_subgroups_parent'] = array('table' => 'og_subgroups', 'field' => 'parent');
  }

  function query() {
    $this->add_additional_fields();
  }

  function pre_render($values) {
    // field_alias is used by the render method.
    $this->field_alias = $this->aliases['node_nid'];
    foreach ($values as $value) {
      $children = og_subgroups_get_children($value->nid);
      foreach ($children as $key => $title) {
        $this->items[$value->nid][$key] = l($title, "node/$key");
      }
    }
  }
}