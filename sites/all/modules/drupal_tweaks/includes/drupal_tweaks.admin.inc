<?php

/**
 * @file
 *   Form with Settings
 *
 * @version
 *
 * @developers
 *   Rafal Wieczorek <kenorb@gmail.com>
 */


/**
 * Menu callback for the settings general operation form.
 */
function drupal_tweaks_general_op_form() {
  module_load_include('inc', 'drupal_tweaks'); // load additional functions from included file
  drupal_tweaks_include_shared_code();
  // drupal_add_js(drupal_get_path('module', 'drupal_tweaks') . '/js/drupal_tweaks.general.js'); // ?

   /* MODULE OPERATIONS */   
   $form['drupal_tweaks_modules_op'] = array(    
     '#type' => 'fieldset',  
     '#title' => t('Module quick operations'),   
     '#description' => t('You can also do it manually on <a target=_blank href="!url">Module Page</a>.', array('!url' => url('admin/build/modules'))),   
     '#collapsible' => TRUE,     
     '#collapsed' => FALSE,  
   );    
   $form['drupal_tweaks_modules_op']['drupal_tweaks_enable_module'] = array(     
     '#type' => 'textfield',     
     '#title' => t('Enable the module.'),    
     '#description' => t('Type which module you want to enable.'),   
     '#autocomplete_path' => 'admin/drupal_tweaks/autocomplete/disabled_modules',    
     '#size' => 30,  
     '#maxlength' => 60,     
   );    
   $form['drupal_tweaks_modules_op']['drupal_tweaks_disable_module'] = array(    
     '#type' => 'textfield',     
     '#title' => t('Disable the module.'),   
     '#description' => t('Type which module you want to disable.'),  
     '#autocomplete_path' => 'admin/drupal_tweaks/autocomplete/enabled_modules',     
     '#size' => 30,  
     '#maxlength' => 60,     
   );    
   $form['drupal_tweaks_modules_op']['drupal_tweaks_module_submit'] = array(     
     '#type' => 'submit',    
     '#value' => t('Save'),  
   );

  /* NODE OPERATIONS */
  $form['drupal_tweaks_nodes_op'] = array(
    '#type' => 'fieldset',
    '#title' => t('Node quick operations'),
    '#description' => t('You can also do it manually on <a target=_blank href="!url">Content Page</a>.', array('!url' => url('admin/content/node'))),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['drupal_tweaks_nodes_op']['drupal_tweaks_node'] = array(
    '#type' => 'textfield',
    '#title' => t('Find the node.'),
    '#description' => t('Type node which you want to find.'),
    '#autocomplete_path' => 'admin/drupal_tweaks/autocomplete/nodes',
    '#size' => 30,
    '#maxlength' => 60,
    //'#suffix' => t('Under development'),
  );
  $form['drupal_tweaks_user_op'] = array(
    '#type' => 'fieldset',
    '#title' => t('User quick operations'),
    '#description' => t('You can also do it manually on <a target=_blank href="!url">User List Page</a>.', array('!url' => url('admin/user/user'))),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['drupal_tweaks_user_op']['drupal_tweaks_user'] = array(
    '#type' => 'textfield',
    '#title' => t('Find the user.'),
    '#description' => t('Type user which you want to find.'),
    '#autocomplete_path' => 'admin/drupal_tweaks/autocomplete/users',
    '#size' => 30,
    '#maxlength' => 60,
    //'#suffix' => t('Under development'),
  );

  return $form;
}

/**
 * Menu callback for the settings general operation form.
 */
function drupal_tweaks_general_op_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  switch ($values['op']) {
    case t('Save'):
    break;
  }
}

