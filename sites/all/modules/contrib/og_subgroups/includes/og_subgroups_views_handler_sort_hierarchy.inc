<?php

class og_subgroups_views_handler_sort_hierarchy extends views_handler_sort {
  /**
   * The sort cannot be exposed
   */
  function can_expose() { return FALSE; }

  function query() {
    // Get the entire subgroup tree. The order in which the tree is built
    // is the order that the groups nodes should be displayed.
    $roots = og_subgroups_get_root();
    $tree = array_keys($roots);
    foreach($roots as $gid => $title) {
      $trees = og_subgroups_get_all_family($gid, 'down');
      foreach ($trees as $group) {
        $tree[] = $group->gid;
      }
    }

    if (!empty($tree)) {
      $sort_order = implode(',', $tree);
      $base_table = $this->query->base_table;
      $base_field = $this->query->base_field;
      $formula = "FIELD($base_table.$base_field, $sort_order)";

      $this->query->add_orderby(NULL, $formula, $this->options['order'], '_' . $this->field);
    }
  }
}