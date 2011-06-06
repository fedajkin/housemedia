<?php
// $Id: autocomplete_element.test.inc,v 1.2.2.1 2010/04/02 14:42:51 b3n Exp $

/**
 * @file
 * Test form with autocomplete_element elements
 */
 
/**
 * Test form
 *
 * @return array
 * @author Ben Scott
 */
function autocomplete_element_test_form() {

  $form = array();
  
  $form['ac'] = array(
    '#type' => 'autocomplete',
    '#title' => t('autocomplete_element'),
    '#data' => _autocomplete_element_test_data()
  );
  
  $form['ac_callback'] = array(
    '#type' => 'autocomplete',
    '#title' => t('autocomplete_element (remote)'),
    '#data' => '/autocomplete_element/test/js'
  );
  
  $form['ac_default'] = array(
    '#type' => 'textfield', 
    '#title' => t('Default autocomplete'), 
    '#maxlength' => 60, 
    '#autocomplete_path' => 'user/autocomplete', 
  );
  
  $form['submit'] = array('#type' => 'submit', '#value' => t('Submit'));
  
  return $form;
  
}

/**
 * Menu callback; autocomplete_element test data
 *
 * @return void
 * @author Ben Scott
 */
function autocomplete_element_test_js() {
  
  $search = strtolower($_GET['search']);
  
  foreach (_autocomplete_element_test_data() as $item) {
    
    if (strlen($search) == 0 || (strpos(strtolower($item), $search) === 0)) {

      $results[] = $item;
      
    }
    
  }
  
  autocomplete_element_output($results);
  
}

/**
 * Test data
 *
 * @return array
 * @author Ben Scott
 */
function _autocomplete_element_test_data() {
  
  return array('One', 'Two', 'Three');
  
}