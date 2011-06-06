<?php

/**
 * Enable OG Subgroups to trigger a condition based on node's position at or
 * below the OG defined in the condition.
 */
class og_subgroups_context_condition_node_in_or_below_og extends context_condition {

  // Values for options form in Context UI.
  function condition_values() {

    $sql = "SELECT n.nid, n.title, n.type FROM {node} n INNER JOIN {og} o ON n.nid = o.nid ORDER BY n.type, n.title";
    $result = db_query(db_rewrite_sql($sql));

    $values = array();
    while ($group = db_fetch_object($result)) {
      $type = node_get_types('name', $group->type);
      $values[$group->nid] = $type . ': ' . $group->title;
    }

    return $values;
  }

  // Execute conditional check.
  // See $plugin->execute in og_subgroups_context.module
  function execute() {

    if ($this->condition_used()) {

      // Get NID we're 'in'.
      // Path of type node/NID
      if ((arg(0) == 'node') && (is_numeric(arg(1)))) {
        $nid = arg(1);
      }
      // Path of type node/add with a ?gids[] argument
      if ((arg(0) == 'node') && (arg(1) == 'add') && (is_numeric($_GET['gids'][0]))) {
        $nid = $_GET['gids'][0];
      }
      // Path of type og/user/GID (OG management paths).
      if ((arg(0) == 'og') && (arg(1) == 'users') && (is_numeric(arg(2)))) {
        $nid = arg(2);
      }

      // Make sure we're on/in a node.
      if ($nid) {

        foreach ($this->get_contexts($value) as $context) {

          // Get groups checked in our conditions when context was defined.
          $check_groups = $context->conditions['og_subgroups_context_condition_node_in_or_below_og']['values'];

          // Get children groups.
          $full_children = og_subgroups_get_all_family($check_groups, 'down');

          // Flatten children array.
          $children = array();
          foreach ($full_children as $object) {
            $children[$object->gid] = $object->title;
          } 

          // $children contains all of the children groups, add the parents that
          // started it all so we have the whole family. :)
          $family = $children + array_flip($check_groups);

          // If current node is an OG in defined OG's family.
          if (in_array($nid, array_keys($family))) {

            $this->condition_met($context, $value);

          }
          // Else, check if current node is non-OG node in defined OG's family.
          else { 

            // Query in og_ancestry to see if current node is IN ( $family ).
            // group_nid can == 0, so explicitly prevent returning those rows.
            $sql = "SELECT group_nid FROM {og_ancestry} WHERE nid = %d AND group_nid IN (" . db_placeholders($family, 'int') . ") AND group_nid <> 0";
            $results = db_result(db_query($sql, array_merge((array) $nid, array_flip($family))));

            if ($results) {

              $this->condition_met($context, $value);

            }

          }

        }

      }

    }

  }

}
