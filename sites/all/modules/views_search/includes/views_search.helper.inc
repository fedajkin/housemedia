<?php

/**
 * @file
 * Helper functions for Views Search module
 */

/**
 * Define options for a views 'null' argument that is invalid
 * (i.e. stops the view from executing).
 *
 * @return
 *   Returns the options for a null argument in a view
 */
function _views_search_invalid_null_argument_invalid() {

  $options = array(
    'default_action' => 'default',
    'style_plugin' => 'default_summary',
    'style_options' => array(),
    'wildcard' => 'all',
    'wildcard_substitution' => 'All',
    'default_argument_type' => 'php',
    'validate_type' => 'php',
    'validate_fail' => 'empty',
    'must_not_be' => 0,
    'id' => 'null',
    'relationship' => 'none',
    'validate_argument_php' => FALSE,
  );

  return $options;

}



/**
 * Determine if this view should be executed. 
 * Get the exposed input for this view and verify 
 * that at least one argument is meant to be used for this view.
 *
 * @param $view
 *   Full view object
 * @return
 *   Returns true if the user executed a search view
 */
function _views_search_execute_view($view = '') {

  if (!is_object($view)) {
    return;
  }

  // Determine all the exposed input filters for this view
  $view_filters = $view->display['default']->handler->options['filters'];
  $view_exposed_filters = array();
  foreach ($view_filters as $filter) {
    if ($filter['exposed']) {
      $view_exposed_filters[] = $filter['expose']['identifier'];
    }
  }

  // Determine the keys of the arguments that have been
  // passed to this view
  $exposed_input = array_keys($view->get_exposed_input());

  // If at least one passed argument is actually part of this
  // view, return TRUE
  if (array_intersect($exposed_input, $view_exposed_filters)) {
    return TRUE;
  }
  else {
    return FALSE;
  }

}



/**
 * Helper Function to return an array with basic information
 * about a view in a keyed array.
 *
 * @param $view
 *   View Object
 *
 * @return
 *   Returns array with information pieces (name, title, base path) about this view
 */
function _views_search_view_info($view = '') {

  if (!is_object($view) || get_class($view) != 'view') {
    return;
  }

  $view_info = array();
  $view_info['name'] = $view->name; // Name of the view
  $view_info['base_path'] = $view->display[$view->current_display]->display_options['path']; // Base path of the view
  $view_info['vid'] = $view->vid; // View ID
  $view_info['filters'] = serialize(_views_search_exposed_params_to_filters($view)); // Exposed filter parameters
  $view_info['current_display'] = $view->current_display; // Current display
  // Title of this view (depending on the current display)
  if (isset($view->display[$view->current_display]->title)) {
    $view_title = $view->display[$view->current_display]->display_options['title'];
  }
  else {
    $view_title = $view->display['default']->display_options['title'];
  }
  $view_info['title'] = $view_title;

  return $view_info;

}



/**
 * AHAH Callback Helper
 */
function _views_search_ahah_callback_helper() {

  // Some action just triggered this callback.
  // First, we prepare the form for being retrieved from the cache.
  $form_state = array('storage' => NULL, 'submitted' => FALSE);
  $form_build_id = $_POST['form_build_id'];

  // We retrieve the form from the cache.
  $form = form_get_cache($form_build_id, $form_state);

  // We prepare the form for processing
  $args = $form['#parameters'];
  $form_id = array_shift($args);
  $form_state['post'] = $form['#post'] = $_POST;
  $form['#programmed'] = $form['#redirect'] = FALSE;

  // We enable submit/validate handlers to dermine
  // if this form was AHAH-submitted.
  $form_state['ahah_submission'] = TRUE;
  $form_state['testing'] = $form['storage']['testvalue']['#value'];

  // This function is the heart of form API. This function calls the submit handlers,
  // which put whatever was worthy of keeping into $form_state.
  drupal_process_form($form_id, $form, $form_state);

  // Because the AHAH callback simulates the pressing of a button,
  // then your AHAH callback will need to do the same as what
  // drupal_get_form would do when the button is pressed.
  $form = drupal_rebuild_form($form_id, $form_state, $args, $form_build_id);

  // Return the form
  return $form;

}



/**
 * Helper function; deconstructs a params string from to an array of filters.
 *
 * @param $view
 *   View Object with exposed filters
 *
 * @return
 *  Array with filter name and value pairs
 */
function _views_search_exposed_params_to_filters($view) {

  $filters = array();
  if (is_object($view->display_handler)) {
    $exposed = $view->get_exposed_input();
    if (!empty($exposed)) {
      foreach ($exposed as $key => $value) {
        if (!empty($value) || $value == '0') {
          $filters[$key] = $value;
        }
      }
    }
  }
  // Remove unnecessary filters
  unset($filters['saved_search_name']);
  unset($filters['ssid']);
  unset($filters['overwrite_saved_search']);
  return $filters;

}



/**
 * Helper Function: Generate query parameters based on saved filters
 *
 * @param $serialized_filters
 *   Serialized saved search filters
 * @param $ssid
 *   Saved Search ID
 *
 * @returns
 *   Query parameters for a saved search
 */
function _views_search_filters_to_exposed_params($serialized_filters = '', $ssid = '') {

  if ($ssid == '') {
    drupal_set_message('small problem...');
    return;
  }

  // Determine the saved search filters
  $filters = unserialize($serialized_filters);

  if (!is_array($filters)) {
    $filters = array();
  }

  // Add the ID of the saved search ID to the filters
  $filters['ssid'] = $ssid;

  // Prepare the query params
  $link_options_query = array();
  foreach ($filters as $filter_key => $filter_value) {
    $query_params[$filter_key] = $filter_value;
  }

  return $query_params;

}


/**
 * Helper Function to prevent the usage of the same
 * name for saved searches by one user.
 *
 * @param $name
 *   Name of the saved search, string
 * @param $uid
 *   User ID of the user in question
 *
 * @return
 *   Returns Saved Search ID if this name was already used for a saved search by this user
 */
function _views_search_saved_search_name_prevent_duplicate($name = '', $uid = '') {

  if ($name == '' || $uid == '') {
    return;
  }

  $ssid = db_result(db_query("SELECT ssid FROM {views_search} WHERE uid = %d and name = '%s'", $uid, $name));

  if ($ssid) {
    return $ssid;
  }

}



/**
 * Helper function to determine if a user has
 * reached his saved search limit.
 * This will check all roles the current user has
 * and use the highest possible limit available.
 *
 * 1. Determine all roles that can save search views
 * 2. Determine which of those roles the current user has
 * 3. Determine the highest possible max_search value from those roles
 * 4. Determine if the user has used the allowed amount of saved searches
 *
 * @param $uid
 *   User ID, optional (defaults to current user)
 *
 * @return
 *   Returns the upper maximum amount of saved searches for this role,
 *   only if the user has already hit his limit.
 *
 */
function _views_search_saved_search_limit($uid = '') {

  if ($uid == '') {
    global $user;
  }
  else {
    $user = user_load($uid);
  }

  // Determine all roles that can save a search
  $roles_saved_search = user_roles(TRUE, 'save views search');

  // Determine the intersection between the user's role and the roles that can save views searches
  $role_save_search_intersect = array_intersect_assoc($roles_saved_search, $user->roles);

  $saved_search_max = 0;
  // Determine the highest possible amount of saved searches for this user
  foreach ($role_save_search_intersect as $rid => $role_name) {
    $max_saved_search_role = variable_get('views_search_saved_search_max_role_' . $rid, 0);
    // If this role can save searches and there is no limit set,
    // this user can still save views searches.
    if ($max_saved_search_role == 0) {
      return FALSE;
    }
    // Use the highest possible amount of saved searches
    if ($max_saved_search_role > $saved_search_max) {
      $saved_search_max = $max_saved_search_role;
    }
  }

  // Determine if this user has already saved more saved searches than his max
  if (views_search_get_saved_search_count($user->uid) >= $saved_search_max) {
    return $saved_search_max;
  }

}



/**
 * Helper function to check for various factors of a saved search name:
 * 1. Name can't include special characters
 * 2. Name can't be empty
 * 3. Name has to be unique for this uer
 *
 * @param $saved_search_name
 *   Name of the saved search to check
 * @return
 *   Array containing (1) error message and (2) optionally ssid, if this saved search was already saved
 */
function _views_search_check_saved_search_name($name = '') {

  $status = array();

  // Make sure users don't use HTML or PHP for search names
  $name_clean = filter_xss(trim($name), array());

  if ($name != $name_clean) {
    $status['error'] = t('Your search was <em>not</em> saved. Please only use regular characters for your search.');
    return $status;
  }

  // Make sure the user enters a name at all
  if (!$name_clean) {
    $status['error'] = t('Your search was <em>not</em> saved. Please enter a name for your Saved Search.');
    return $status;
  }

  // Make sure the user doesn't use the same name twice
  $ssid = _views_search_saved_search_name_prevent_duplicate($name_clean, $GLOBALS['user']->uid);
  if ($ssid) {
    $status['error'] = t('You already used this name for a Saved Search. Please choose a different name.');
    $status['ssid'] = $ssid;
    return $status;
  }

}



/**
 * Helper function to add a CSS class to a form element
 *
 * @param $new_class
 *   Additional class to be added, as string
 * @param $existing_class
 *   Existing class as a string, if available
 *
 * @return
 *   Complete set of classes as a string
 */
function _views_search_form_add_css_class($new_class = FALSE, $existing_classes) {

  // Make sure both variables are strings, if passed
  if (!is_string($new_class) || (isset($existing_classes) && !is_string($existing_classes))) {
    return;
  }

  // If there is no existing class, just return the new class
  if (!$existing_classes) {
    return $new_class;
  }

  // Otherwise, split up the existing classes and add the new one
  $classes = split(' ', $existing_classes);
  $classes[] = $new_class;
  return implode(' ', $classes);

}



/**
 * Determine if any of the dipslays in this view use AJAX
 *
 * @param $view
 *   View Object, required
 * @return
 *   True, if one of the displays uses AJAX
 */
function _views_search_view_ajax_enabled($view = '') {

  if (!is_object($view)) {
    return;
  }

  foreach ($view->display as $display_name => $display) {
    if ($display->display_options['use_ajax']) {
      return TRUE;
    }
  }

}



/**
 * Determine if the filters of this view are exposed in a block.
 *
 * @param $view
 *   View object, required.
 * @return
 *   TRUE if the filters are exposed
 */
function _views_search_view_exposed_block($view = '') {

  if (!is_object($view)) {
    return;
  }

  // Determine if the current display overrode the exposed_block option,
  // otherwise use the default exposed_block setting.
  if (isset($view->display[$view->current_display]->handler->options['exposed_block'])) {
    $exposed_block = $view->display[$view->current_display]->handler->options['exposed_block'];
  } else {
    $exposed_block = $view->display['default']->display_options['exposed_block'];
  }
  
  if ($exposed_block) {
    return TRUE;
  }

}