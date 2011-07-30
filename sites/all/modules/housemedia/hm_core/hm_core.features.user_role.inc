<?php

/**
 * Implementation of hook_user_default_roles().
 */
function hm_core_user_default_roles() {
  $roles = array();

  // Exported role: Deweloper
  $roles['Deweloper'] = array(
    'name' => 'Deweloper',
  );

  // Exported role: Doradca
  $roles['Doradca'] = array(
    'name' => 'Doradca',
  );

  // Exported role: Użytkownik
  $roles['Użytkownik'] = array(
    'name' => 'Użytkownik',
  );

  return $roles;
}
