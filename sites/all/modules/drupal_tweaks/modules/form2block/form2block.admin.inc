<?php

/**
 * @file
 *   Settings Form
 *
 * @version
 *
 * @developers
 *   Rafal Wieczorek <kenorb@gmail.com>
 */


/**
 * Menu callback for the settings form.
 */
function form2block_settings_form() {
  $form['form2block'] = array(
    '#type' => 'fieldset',
    '#title' => t('Convert any form or node into block.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['form2block']['form2block_form_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Type form id or path of that form which you want to convert.'),
    '#default_value' => variable_get('form2block_form_id', ''),
    '#autocomplete_path' => 'admin/drupal_tweaks/autocomplete/form_id',
    '#size' => 30,
    '#maxlength' => 60,
    '#id' => 'form2block_form_id',
    '#suffix' => "<div id='form2block_preview'></div>",
  );
  drupal_add_js("$('#form2block_form_id').change(function() { $('#form2block_preview').append('Under development, sorry.') });", 'inline', 'footer');
  $form['form2block']['form2block_submit'] = array(
    '#type' => 'submit',
    '#value' => t('Convert'),
    '#prefix' => t('Under development...'),
    '#disabled' => TRUE,
  );


  return $form;
}

