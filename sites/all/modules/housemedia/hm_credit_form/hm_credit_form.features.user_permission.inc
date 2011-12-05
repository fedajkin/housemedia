<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function hm_credit_form_user_default_permissions() {
  $permissions = array();

  // Exported permission: edit field_credit_form_account_limit
  $permissions['edit field_credit_form_account_limit'] = array(
    'name' => 'edit field_credit_form_account_limit',
    'roles' => array(
      '0' => 'Doradca',
    ),
  );

  // Exported permission: edit field_credit_form_advisor
  $permissions['edit field_credit_form_advisor'] = array(
    'name' => 'edit field_credit_form_advisor',
    'roles' => array(),
  );

  // Exported permission: edit field_credit_form_amount
  $permissions['edit field_credit_form_amount'] = array(
    'name' => 'edit field_credit_form_amount',
    'roles' => array(
      '0' => 'Doradca',
    ),
  );

  // Exported permission: edit field_credit_form_card_limit
  $permissions['edit field_credit_form_card_limit'] = array(
    'name' => 'edit field_credit_form_card_limit',
    'roles' => array(
      '0' => 'Doradca',
    ),
  );

  // Exported permission: edit field_credit_form_income
  $permissions['edit field_credit_form_income'] = array(
    'name' => 'edit field_credit_form_income',
    'roles' => array(
      '0' => 'Doradca',
    ),
  );

  // Exported permission: edit field_credit_form_name
  $permissions['edit field_credit_form_name'] = array(
    'name' => 'edit field_credit_form_name',
    'roles' => array(
      '0' => 'Doradca',
    ),
  );

  // Exported permission: edit field_credit_form_obligations
  $permissions['edit field_credit_form_obligations'] = array(
    'name' => 'edit field_credit_form_obligations',
    'roles' => array(
      '0' => 'Doradca',
    ),
  );

  // Exported permission: edit field_credit_form_surname
  $permissions['edit field_credit_form_surname'] = array(
    'name' => 'edit field_credit_form_surname',
    'roles' => array(
      '0' => 'Doradca',
    ),
  );

  // Exported permission: view field_credit_form_account_limit
  $permissions['view field_credit_form_account_limit'] = array(
    'name' => 'view field_credit_form_account_limit',
    'roles' => array(
      '0' => 'Doradca',
      '1' => 'Użytkownik',
    ),
  );

  // Exported permission: view field_credit_form_advisor
  $permissions['view field_credit_form_advisor'] = array(
    'name' => 'view field_credit_form_advisor',
    'roles' => array(
      '0' => 'Doradca',
      '1' => 'Użytkownik',
    ),
  );

  // Exported permission: view field_credit_form_amount
  $permissions['view field_credit_form_amount'] = array(
    'name' => 'view field_credit_form_amount',
    'roles' => array(
      '0' => 'Doradca',
      '1' => 'Użytkownik',
    ),
  );

  // Exported permission: view field_credit_form_card_limit
  $permissions['view field_credit_form_card_limit'] = array(
    'name' => 'view field_credit_form_card_limit',
    'roles' => array(
      '0' => 'Doradca',
      '1' => 'Użytkownik',
    ),
  );

  // Exported permission: view field_credit_form_income
  $permissions['view field_credit_form_income'] = array(
    'name' => 'view field_credit_form_income',
    'roles' => array(
      '0' => 'Doradca',
      '1' => 'Użytkownik',
    ),
  );

  // Exported permission: view field_credit_form_name
  $permissions['view field_credit_form_name'] = array(
    'name' => 'view field_credit_form_name',
    'roles' => array(
      '0' => 'Doradca',
      '1' => 'Użytkownik',
    ),
  );

  // Exported permission: view field_credit_form_obligations
  $permissions['view field_credit_form_obligations'] = array(
    'name' => 'view field_credit_form_obligations',
    'roles' => array(
      '0' => 'Doradca',
      '1' => 'Użytkownik',
    ),
  );

  // Exported permission: view field_credit_form_surname
  $permissions['view field_credit_form_surname'] = array(
    'name' => 'view field_credit_form_surname',
    'roles' => array(
      '0' => 'Doradca',
      '1' => 'Użytkownik',
    ),
  );

  return $permissions;
}
