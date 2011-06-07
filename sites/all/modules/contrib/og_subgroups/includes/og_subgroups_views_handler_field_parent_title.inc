<?php
class og_subgroups_views_handler_field_parent_title extends views_handler_field {
  function render($value) {
    $parent = og_subgroups_get_parent($value->og_subgroups_gid);
    return $parent['title'];
  }
}