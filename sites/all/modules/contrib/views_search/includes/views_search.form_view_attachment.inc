<?php

/**
 * @file
 * Form definitions for form that gets attached in a view header
 */

/**
 * Form callback for search view headers
 */
function views_search_content_attachment_before_form(&$form_state, $view = '') {

  // Store basic information about this view in the form storage ($form_state['storage'])
  // ONLY when the view object is passed. This will be looped through, even with AHAH turned on
  if (is_object($view) && get_class($view) == 'view') {
    $view_info = _views_search_view_info($view);
    foreach ($view_info as $view_key => $view_item) {
      $form_state['storage']['view_info'][$view_key] = $view_item;
    }
  }

  // Determine what state of the process this is
  if (isset($form_state['values']['op']) && ($form_state['values']['op'] == $form_state['values']['view_save'])) {
    $show_save_search_element = 1;
  }
  else {
    $show_save_search_element = 0;
  }

  // Determine if this is an already saved search
  $ssid = (isset($view->exposed_input['ssid'])) ? $view->exposed_input['ssid'] : 0;

  // Determine visibility of 'modify search' button.
  if ($ssid) {
    global $user;
    $saved_search_object = views_search_get_saved_search_object($ssid);
    $show_modify_button = ($saved_search_object->uid == $user->uid) ? 1 : 0;
  }
  else {
    $show_modify_button = 1;
  }

  // Define form attributes for styling
  $form['#attributes'] = array(
    'class' => 'search-view-attachment-form',
  );

  // Create a fieldset for all elements from this form.
  // All elements need to be re-drawn for AHAH.
  // If this view result was called from an exposed form in a block,
  // add an additional class.
  if (_views_search_view_exposed_block($view)) {
    $views_search_attachment_prefix = '<div id="views-search-attachment-ahah" class="views-search-exposed-block">';
  }
  else {
    $views_search_attachment_prefix = '<div id="views-search-attachment-ahah">';
  }
  $form['views_search_attachment'] = array(
    '#type' => 'fieldset',
    '#prefix' => $views_search_attachment_prefix,
    '#suffix' => '</div>',
  );

  // Button to start a new search using this view
  $form['views_search_attachment']['view_start_over'] = array(
    '#type' => 'submit',
    '#value' => t('Start a new ') . $form_state['storage']['view_info']['title'],
    '#submit' => array('views_search_view_start_over_submit'),
  );

  // Modify the exposed filters of this view
  if ($show_modify_button) {
    $view_modify_class = ($ssid) ? 'search-view-modify-saved' : 'search-view-modify';
    $form['views_search_attachment']['view_modify'] = array(
      '#type' => 'button',
      '#value' => ($ssid) ? t('Edit Saved Search') : t('Edit Search'),
      '#attributes' => array(
        'class' => $view_modify_class . ' ' . $form_state['storage']['view_info']['name'],
      ),
    );
  }

  // Only show all buttons related to save searches
  // if the current user has the correct permissions
  if (user_access('save views search')) {
    // Show this (via AHAH) if a user clicked on the "Save this search" button
    if ($show_save_search_element) {
      // Make sure the current user can still save searches (i.e. is not over his personal limit)
      if (!_views_search_saved_search_limit()) {
        // Textfield for saved search name
        $form['views_search_attachment']['save_search_name'] = array(
          '#type' => 'textfield',
          '#title' => t('Saved Search Name'),
          '#description' => t('Enter a name for this Saved Search (30 chars. max.)'),
          '#size' => 30,
          '#maxlength' => 30,
        );
        // Button to save this search
        $form['views_search_attachment']['save_search'] = array(
          '#type' => 'submit',
          '#value' => t('Save This Search'),
          '#description' => t('Save this as a new search'),
          '#submit' => array('views_search_save_search_submit'),
        );
      }
      // Otherwise display a link to allow the user to delete saved searches
      else {
        // Expose a hook so other modules can provide alternative content
        $alternative_content = module_invoke_all('views_search_content', 'saved_search_limit');
        // If other modules provide content, display it here
        if ($alternative_content) {
          $manage_saved_searches_content = '';
          foreach ($alternative_content as $content) {
            $manage_saved_searches_content .= $content;
          }
        }
        // If no other module provides alterantive content, display default text
        else {
          $manage_saved_searches_content_replace = array(
            '!link' => l('Delete existing Saved Searches.', 'search/saved'),
            '!limit' => _views_search_saved_search_limit(),
          );
          $manage_saved_searches_content = t('You reached your Saved Search limit (!limit). !link', $manage_saved_searches_content_replace);
        }
        $form['views_search_attachment']['manage_saved_searches'] = array(
          '#prefix' => '<div id="saved_search_limit">',
          '#suffix' => '</div>',
          '#value' => $manage_saved_searches_content,
          '#weight' => -10,
        );
      }
    }
    // Only show the 'Saved Search' button if this search isn't already saved
    // and none of the displays in this view use AJAX.
    elseif (!$ssid && !_views_search_view_ajax_enabled($view)) {
      $form['views_search_attachment']['view_save'] = array(
        '#type' => 'submit',
        '#value' => t('Save this search'),
        '#description' => t('Save the criteria for this search for later usage'),
        '#ahah' => array(
          'path' => 'views_search/toggle_attachment/callback',
          'wrapper' => 'views-search-attachment-ahah',
          'effect' => 'fade',
        ),
      );
    }

    // Button to cancel
    $form['views_search_attachment']['save_search_cancel'] = array(
      '#type' => 'submit',
      '#value' => t('Cancel This'),
      '#description' => t('Don\'t save this search at this point.'),
      '#weight' => 10,
      '#ahah' => array(
        'path' => 'views_search/toggle_attachment/callback',
        'wrapper' => 'views-search-attachment-ahah',
        'effect' => 'fade',
      ),
    );

    // Visually hide certain elements of the form when the "Save Search" form is visible
    if ($show_save_search_element) {
      $form['views_search_attachment']['view_start_over']['#attributes']['style'] = 'display:none';
      $form['views_search_attachment']['view_modify']['#attributes']['style'] = 'display:none';
    }
    else {
      $form['views_search_attachment']['save_search_cancel']['#attributes']['style'] = 'display:none';
    }

  }

  return $form;

}



/**
 * AHAH Callback function for toggline the "Save a Search" part of the attachment
 */
function views_search_toggle_save_search_attachment_callback() {

  $form = _views_search_ahah_callback_helper();

  // Get the save search fieldset (as an array)
  $views_search_attachment = $form['views_search_attachment'];

  // Prevent duplicate wrappers, see http://drupalsn.com/learn-drupal/drupal-tutorials/getting-going-ahah-and-drupal-6
  unset($views_search_attachment['#prefix'], $views_search_attachment['#suffix']);

  // Renders HTML given a structured array tree.
  $output = drupal_render($views_search_attachment);

  // Final rendering callback.
  print drupal_json(array('status' => TRUE, 'data' => $output));
  exit();

}



/**
 * Form callback for starting over with a search view
 */
function views_search_view_start_over_submit($form, &$form_state) {
  if (empty($form_state['ahah_submission'])) {
    $form_state['redirect'] = $form_state['storage']['view_info']['base_path'];
    // TODO: The form doesn't redirect if I don't unset $form_state['storage']
    unset($form_state['storage']);
  }
}



/**
 * Form callback for saving a search
 */
function views_search_save_search_submit($form, &$form_state) {

  // Only execute this for non-AHAH submissions
  if (empty($form_state['ahah_submission'])) {

    // Create shortcut for saved search name
    $save_search_name = $form_state['values']['save_search_name'];

    // Error checking for saved search name
    $status = _views_search_check_saved_search_name($save_search_name);
    if ($status['error']) {
      drupal_set_message($status['error'], 'error');
      return;
    }

    // Store this view in the database
    $view_info = $form_state['storage']['view_info'];
    unset($form, $form_state);
    views_search_write_saved_search($view_info, $save_search_name);

  }

}



/**
 * Callback function to determine if the currently logged_in user already used a name for a saved search
 *
 * @param $name
 *   Saved search name to check
 * @return
 *   Returns 1 if this name was already used
 */
function views_search_check_saved_search_name_callback($name = '') {

  if (!user_is_logged_in()) {
    return;
  }

  if ($name == '') {
    $status = FALSE;
  }
  else {
    $status = TRUE;
  }

  // Load the global user object
  global $user;

  // Only proceed with plain text
  $name = filter_xss($name, array());

  // Determine if this name was already used
  $name_in_use = _views_search_saved_search_name_prevent_duplicate($name, $user->uid);

  // Final rendering callback.
  print drupal_json(array('status' => $status, 'data' => $name_in_use));
  exit();

}