<?php

/**
 * @file
 * Admin functions for Views Search module.
 */

/**
 * Administration callback for Views Search admin page.
 */
function views_search_admin_configure() {

  // Define Views that should be converted into Search Views
  $views = views_get_all_views();  // Load all views

  // Fill an array with available view names
  $options = array();
  foreach ($views as $view) {
    // Only include views that have at least one exposed filters
    $exposed = FALSE;
    // Cycle through all displays of this view
    foreach ($view->display as $display) {
      if (isset($display->display_options['filters'])) {
        foreach ($display->display_options['filters'] as $filter) {
          if ($filter['exposed'] == TRUE) {
            $exposed = TRUE;
          }
        }
      }
    }
    if ($exposed) {
      $options[$view->name] = $view->name;
    }
  }

  // Sort this array alphabetically
  uasort($options, '_views_search_admin_sort_views');

  $form['views_search'] = array(
    '#type' => 'fieldset',
    '#title' => 'Enabled Search Views',
    '#description' => t('Only views that have at least one exposed filters can be turned into a search view. If you can\'t find the view you are looking for in this list, make sure that view has at least one exposed filter.'),
  );

  $form['views_search']['views_search_enabled_views'] = array(
    '#title' => t('Convert the checked views into search views'),
    '#type' => 'checkboxes',
    '#options' => $options,
    '#default_value' => variable_get('views_search_enabled_views', array()),
  );

  // Define Saved Search Role Limits
  $form['saved_search_role_limits'] = array(
    '#type' => 'fieldset',
    '#title' => t('Saved Search Limits'),
    '#description' => t('Define how many searches can be saved per role. Leave at 0 for unlimited. Note that each role needs to have the \'save views search\' permission to save searches at all. If you are missing a role on this page, ' . l('configure user permissions', 'admin/user/permissions') . ' first.'),
  );

  // Get available user roles that can save a search view
  $roles = user_roles(TRUE, 'save views search');

  foreach ($roles as $rid => $role_name) {
    $form['saved_search_role_limits']['views_search_saved_search_max_role_' . $rid] = array(
      '#type' => 'textfield',
      '#title' => t('Maximum amount of Saved Searches for ') . $role_name,
      '#description' => t('Enter the number of searches users with this role can save'),
      '#default_value' => variable_get('views_search_saved_search_max_role_' . $rid, 0),
      '#size' => 5,
    );
  }

  // Allow admins with correct permissions to mass-delete saved searches by view
  if (user_access('mass delete views search')) {
    $search_views = variable_get('views_search_enabled_views', array());
    $form['saved_search_mass_delete'] = array(
      '#type' => 'fieldset',
      '#title' => t('Delete All Saved Searches By View'),
      '#description' => t('If a specific views has changed so that the Saved Searches are not working properly any more, you can clear out all Saved Searches for that view here.'),
    );
    foreach ($search_views as $search_view_name => $search_view_param) {
      if ($search_view_param) {
        $form['saved_search_mass_delete'][$search_view_name] = array(
          '#type' => 'item',
          '#value' => l('Delete all Saved Searches for the view \'' . $search_view_name . '\'', 'views_search/delete/all_for_view/' . $search_view_name),
        );
      }
    }
  }

  return system_settings_form($form);

}



/**
 * Sort views alphabetically on admin form
 */
function _views_search_admin_sort_views($a, $b) {
  if ($a == $b) {
    return 0;
  }
  return ($a < $b) ? -1 : 1;
}