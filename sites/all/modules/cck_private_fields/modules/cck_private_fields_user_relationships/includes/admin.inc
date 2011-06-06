<?php
// $Id: admin.inc,v 1.1.2.1 2009/09/06 19:25:51 markuspetrux Exp $

/**
 * @file
 * Administrative interface for the module.
 */

/**
 * Alter the CCK Field settings form.
 */
function _cck_private_fields_user_relationships_content_field_edit_form_alter(&$form) {
  $field_name = $form['#field']['field_name'];
  $relationship_types = array();
  foreach (user_relationships_types_load() as $rtid => $relationship) {
    $relationship_types[$rtid] = $relationship->plural_name;
  }

  $form['field']['cck_private_fields']['user_relationships'] = array(
    '#type' => 'fieldset',
    '#title' => t('User relationships options'),
    '#weight' => 50,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['field']['cck_private_fields']['user_relationships']['relationship_types'] = array(
    '#type' => 'checkboxes',
    '#checkall' => TRUE,
    '#title' => t('Relationship types'),
    '#options' => $relationship_types,
    '#default_value' => variable_get('cck_private_fields_user_relationships_types_'. $field_name, array()),
    '#description' => t('Choose which relationship types that can be used to grant access to view this field when Private option is selected.'),
  );

  $form['#submit'][] = '_cck_private_fields_user_relationships_content_field_edit_form_submit';
}

/**
 * Submit function for Private Fields extra config.
 */
function _cck_private_fields_user_relationships_content_field_edit_form_submit($form, &$form_state) {
  $field_name = $form_state['values']['field_name'];
  $relationship_types = array_filter($form_state['values']['relationship_types']);
  variable_set('cck_private_fields_user_relationships_types_'. $field_name, $relationship_types);
}
