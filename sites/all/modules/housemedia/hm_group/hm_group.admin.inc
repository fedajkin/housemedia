<?php 

function hm_group_admin_settings() {
  $form = array();

  $form['reg_keys'] = array(
    '#title'			 => t('Organic groups registration keys'),
    '#type'        => 'fieldset',
    '#collapsed'   => TRUE,
    '#collapsible' => TRUE
  );
  
  $form['reg_keys']['hm_group_reg_keys_help_nid'] = array(
    '#title'         => t('Help page NID'),
    '#type'          => 'textfield',
    '#default_value' => variable_get('hm_group_reg_keys_help_nid', ''),
    '#description'   => t('Enter valid NID of node that contains explanation about a registration keys. This node will automatically linked in registration keys form.')
  );
  
  return system_settings_form($form);
}