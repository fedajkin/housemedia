<?php
// $Id: autocomplete_element.admin.inc,v 1.1.2.2 2010/04/02 14:42:51 b3n Exp $

/**
 * @file
 * Administrative settings callbacks for the autocomplete module.
 */

/**
 * Administrative settings.
 *
 * @return
 *   An array of form elements.
 */
function autocomplete_element_admin_settings() {

  $form = array();

  $form['autocomplete_element_override'] = array(
    '#type' => 'checkbox',
    '#title' => t('Override autocomplete'),
    '#default_value' => autocomplete_element_variable_get('override'),
    '#description' => t('Do you want to use the jquery.autocomplete plugin for all autocomplete form elements?')
  );

  
  return system_settings_form($form);

}
