<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function hm_profile_user_default_permissions() {
  $permissions = array();

  // Exported permission: create doradca content
  $permissions['create doradca content'] = array(
    'name' => 'create doradca content',
    'roles' => array(
      '0' => 'Doradca',
    ),
  );

  // Exported permission: create uzytkownik content
  $permissions['create uzytkownik content'] = array(
    'name' => 'create uzytkownik content',
    'roles' => array(
      '0' => 'Użytkownik',
    ),
  );

  // Exported permission: delete any doradca content
  $permissions['delete any doradca content'] = array(
    'name' => 'delete any doradca content',
    'roles' => array(),
  );

  // Exported permission: delete any uzytkownik content
  $permissions['delete any uzytkownik content'] = array(
    'name' => 'delete any uzytkownik content',
    'roles' => array(),
  );

  // Exported permission: delete own doradca content
  $permissions['delete own doradca content'] = array(
    'name' => 'delete own doradca content',
    'roles' => array(),
  );

  // Exported permission: delete own uzytkownik content
  $permissions['delete own uzytkownik content'] = array(
    'name' => 'delete own uzytkownik content',
    'roles' => array(),
  );

  // Exported permission: edit any doradca content
  $permissions['edit any doradca content'] = array(
    'name' => 'edit any doradca content',
    'roles' => array(),
  );

  // Exported permission: edit any uzytkownik content
  $permissions['edit any uzytkownik content'] = array(
    'name' => 'edit any uzytkownik content',
    'roles' => array(),
  );

  // Exported permission: edit field_dor_firma
  $permissions['edit field_dor_firma'] = array(
    'name' => 'edit field_dor_firma',
    'roles' => array(
      '0' => 'Doradca',
    ),
  );

  // Exported permission: edit field_dor_imie
  $permissions['edit field_dor_imie'] = array(
    'name' => 'edit field_dor_imie',
    'roles' => array(
      '0' => 'Doradca',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_dor_nazwisko
  $permissions['edit field_dor_nazwisko'] = array(
    'name' => 'edit field_dor_nazwisko',
    'roles' => array(
      '0' => 'Doradca',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_dor_telefon
  $permissions['edit field_dor_telefon'] = array(
    'name' => 'edit field_dor_telefon',
    'roles' => array(
      '0' => 'Doradca',
      '1' => 'anonymous user',
    ),
  );

  // Exported permission: edit field_imie
  $permissions['edit field_imie'] = array(
    'name' => 'edit field_imie',
    'roles' => array(
      '0' => 'Użytkownik',
    ),
  );

  // Exported permission: edit field_nazwisko
  $permissions['edit field_nazwisko'] = array(
    'name' => 'edit field_nazwisko',
    'roles' => array(
      '0' => 'Użytkownik',
    ),
  );

  // Exported permission: edit field_plec
  $permissions['edit field_plec'] = array(
    'name' => 'edit field_plec',
    'roles' => array(
      '0' => 'Użytkownik',
    ),
  );

  // Exported permission: edit field_rok_urodzenia
  $permissions['edit field_rok_urodzenia'] = array(
    'name' => 'edit field_rok_urodzenia',
    'roles' => array(
      '0' => 'Użytkownik',
    ),
  );

  // Exported permission: edit field_status
  $permissions['edit field_status'] = array(
    'name' => 'edit field_status',
    'roles' => array(
      '0' => 'Użytkownik',
    ),
  );

  // Exported permission: edit field_telefon
  $permissions['edit field_telefon'] = array(
    'name' => 'edit field_telefon',
    'roles' => array(
      '0' => 'Użytkownik',
    ),
  );

  // Exported permission: edit own doradca content
  $permissions['edit own doradca content'] = array(
    'name' => 'edit own doradca content',
    'roles' => array(
      '0' => 'Doradca',
    ),
  );

  // Exported permission: edit own uzytkownik content
  $permissions['edit own uzytkownik content'] = array(
    'name' => 'edit own uzytkownik content',
    'roles' => array(
      '0' => 'Użytkownik',
    ),
  );

  // Exported permission: edit privacy options for field field_dor_nazwisko
  $permissions['edit privacy options for field field_dor_nazwisko'] = array(
    'name' => 'edit privacy options for field field_dor_nazwisko',
    'roles' => array(
      '0' => 'Doradca',
    ),
  );

  // Exported permission: edit privacy options for field field_dor_telefon
  $permissions['edit privacy options for field field_dor_telefon'] = array(
    'name' => 'edit privacy options for field field_dor_telefon',
    'roles' => array(),
  );

  // Exported permission: edit privacy options for field field_nazwisko
  $permissions['edit privacy options for field field_nazwisko'] = array(
    'name' => 'edit privacy options for field field_nazwisko',
    'roles' => array(
      '0' => 'Użytkownik',
    ),
  );

  // Exported permission: edit privacy options for field field_rok_urodzenia
  $permissions['edit privacy options for field field_rok_urodzenia'] = array(
    'name' => 'edit privacy options for field field_rok_urodzenia',
    'roles' => array(),
  );

  // Exported permission: edit privacy options for field field_telefon
  $permissions['edit privacy options for field field_telefon'] = array(
    'name' => 'edit privacy options for field field_telefon',
    'roles' => array(),
  );

  // Exported permission: view field_dor_firma
  $permissions['view field_dor_firma'] = array(
    'name' => 'view field_dor_firma',
    'roles' => array(
      '0' => 'Doradca',
      '1' => 'Użytkownik',
    ),
  );

  // Exported permission: view field_dor_imie
  $permissions['view field_dor_imie'] = array(
    'name' => 'view field_dor_imie',
    'roles' => array(
      '0' => 'Deweloper',
      '1' => 'Doradca',
      '2' => 'Użytkownik',
      '3' => 'anonymous user',
    ),
  );

  // Exported permission: view field_dor_nazwisko
  $permissions['view field_dor_nazwisko'] = array(
    'name' => 'view field_dor_nazwisko',
    'roles' => array(
      '0' => 'Deweloper',
      '1' => 'Doradca',
      '2' => 'Użytkownik',
      '3' => 'anonymous user',
    ),
  );

  // Exported permission: view field_dor_telefon
  $permissions['view field_dor_telefon'] = array(
    'name' => 'view field_dor_telefon',
    'roles' => array(
      '0' => 'Deweloper',
      '1' => 'Doradca',
      '2' => 'Użytkownik',
      '3' => 'anonymous user',
    ),
  );

  // Exported permission: view private data for field field_dor_nazwisko
  $permissions['view private data for field field_dor_nazwisko'] = array(
    'name' => 'view private data for field field_dor_nazwisko',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view private data for field field_dor_telefon
  $permissions['view private data for field field_dor_telefon'] = array(
    'name' => 'view private data for field field_dor_telefon',
    'roles' => array(),
  );

  // Exported permission: view private data for field field_nazwisko
  $permissions['view private data for field field_nazwisko'] = array(
    'name' => 'view private data for field field_nazwisko',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view private data for field field_rok_urodzenia
  $permissions['view private data for field field_rok_urodzenia'] = array(
    'name' => 'view private data for field field_rok_urodzenia',
    'roles' => array(),
  );

  // Exported permission: view private data for field field_telefon
  $permissions['view private data for field field_telefon'] = array(
    'name' => 'view private data for field field_telefon',
    'roles' => array(),
  );

  return $permissions;
}
