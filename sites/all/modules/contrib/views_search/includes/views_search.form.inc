<?php

/**
 * @file
 * Misc. form callbacks for Views Search module.
 */

/**
 * Form Callback for Saved Search dropdown
 *
 * @param $ssid
 *   Array of Saved Search IDs, required
 */
function views_search_saved_search_block_dropdown_form(&$form_state, $ssids = '') {

  if ($ssids == '') {
    return;
  }

  $options = array();
  foreach ($ssids as $ssid) {
    $saved_search = views_search_generate_saved_search_options($ssid);
    $options[$ssid] = $saved_search['name'];
  }

  $form['explanation'] = array(
    '#type' => 'item',
    '#value' => t('Select the Saved Search you want to run and click "GO".'),
  );
  $form['ssid'] = array(
    '#type' => 'select',
    '#options' => $options,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('GO'),
  );

  return $form;

}



/**
 * Submit Handler for Saved Search dropdown
 */
function views_search_saved_search_block_dropdown_form_submit($form, &$form_state) {

  $ssid = $form_state['values']['ssid'];
  if (!is_numeric($ssid)) {
    return;
  }
  $saved_search = views_search_generate_saved_search_options($ssid);
  drupal_goto($saved_search['path'], $saved_search['query_params']);

}



/**
 * Form Callback for form confirmation to delete a saved search
 */
function views_search_delete_saved_search_form($form, $ssid) {

  $ssid = filter_xss($ssid, array());

  // Get the full saved search object
  $saved_search = views_search_get_saved_search_object($ssid);

  // Make sure this is a saved search
  if (!is_object($saved_search)) {
    drupal_set_message('We could not locate this search in the database');
    drupal_goto('search/saved');
  }

  // Make sure this is the current user's saved search
  global $user;
  if ($user->uid != $saved_search->uid) {
    drupal_set_message('Don\'t you be deleting someone else\'s Saved Search!');
    drupal_goto('search/saved');
  }

  // Add some CSS
  drupal_add_css(drupal_get_path('module', 'views_search') . '/styles/views_search.css');

  $form = array();
  $form['ssid'] = array(
    '#type' => 'value',
    '#value' => $ssid,
  );

  $confirm_question = t('Are you sure want to delete this Saved Search?');
  $confirm_path = 'search/saved';
  $confirm_description = t('Once deleted, we cannot recover your Saved Search "!saved_search".', array('!saved_search' => $saved_search->name));
  $confirm_yes = t('Delete this Saved Search');
  $confirm_no = t('Cancel');

  return confirm_form($form, $confirm_question, $confirm_path, $confirm_description, $confirm_yes, $confirm_no);

}



/**
 * Delete a saved search
 */
function views_search_delete_saved_search_form_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    db_query("DELETE FROM {views_search} WHERE ssid = %d", $form_state['values']['ssid']);
    drupal_set_message(t('Your Saved Search was successfully deleted.'));
    $form_state['redirect'] = 'search/saved';
  }
}



/**
 * Form Callback for confirmation form to delete all saved searches for a specfific view
 */
function views_search_delete_all_saved_searches_form($form, $view_name) {

  $view_name = filter_xss($view_name, array());

  $form = array();
  $form['view_name'] = array(
    '#type' => 'value',
    '#value' => $view_name,
  );

  $confirm_question = t('Are you sure want to delete all Saved Searches for the view !view?', array('!view' => $view_name));
  $confirm_path = 'admin/settings/views_search';
  $confirm_description = t('This will delete <em>all</em> Saved Searches related to this view for <em>all</em> displays of this view. Be extremely careful with this feature, as any Saved Searches are not recoverable once they are deleted.');
  $confirm_yes = t('Yes, Delete All Saved Searches for this View');
  $confirm_no = t('Go back to Views Search configuration');

  return confirm_form($form, $confirm_question, $confirm_path, $confirm_description, $confirm_yes, $confirm_no);

}



/**
 * Delete all saved searches for a view
 */
function views_search_delete_all_saved_searches_form_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    db_query("DELETE FROM {views_search} WHERE view_name = '%s'", $form_state['values']['view_name']);
    drupal_set_message(t('All Saved Searches for the view !view where successfully deleted.',  array('!view' => $form_state['values']['view_name'])));
    $form_state['redirect'] = 'admin/settings/views_search';
  }
}