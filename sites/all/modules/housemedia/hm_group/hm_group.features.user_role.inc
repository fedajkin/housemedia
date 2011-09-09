<?php

/**
 * Implementation of hook_user_default_roles().
 */
function hm_group_user_default_roles() {
  $roles = array();

  // Exported role: gość
  $roles['gość'] = array(
    'name' => 'gość',
  );

  // Exported role: mieszkaniec
  $roles['mieszkaniec'] = array(
    'name' => 'mieszkaniec',
  );

  return $roles;
}
