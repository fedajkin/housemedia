<?php


/**
 * @file
 * Code for the settings page for OG Project.
 */

/**
 * Form builder for the administrative settings page.
 */
function og_project_settings_form($form_state) {
  $project_group_behavior = variable_get('og_content_type_usage_project_project', 'group_post_standard');
  if ($project_group_behavior == 'group') {
    $types = array(
      'project_issue' => 'og_project_issue_automatic_audience',
      'project_release' => 'og_project_release_automatic_audience',
    );
    foreach ($types as $type => $variable) {
      if (module_exists($type)) {
        $form['og_project_audience'][$variable] = _og_project_audience_setting($type, $variable);
      }
    }
    if (!empty($form['og_project_audience'])) {
      $placeholders['%project'] = node_get_types('name', 'project_project');
      $form['og_project_audience']['#type'] = 'fieldset';
      $form['og_project_audience']['#title'] = t('Automatic group audience for %project content', $placeholders);
      $form['og_project_audience']['#description'] = t('Your site is configured with %project nodes as Organic Groups. Projects can also have other nodes associated with them, which you may want to have automatically posted to the corresponding Organic Group.', $placeholders);
    }
  }
  if (!empty($form)) {
    return system_settings_form($form);
  }
  return array();
}

/**
 * Helper function to generate the settings form element for a given type.
 *
 * @param $type
 *   Node type to add the audience setting for (e.g. 'project_issue').
 * @param $variable
 *   Name of the variable to use for the audience setting for the given type.
 *
 * @return
 *   A Form API array defining a checkbox for the given node type and setting.
 *
 * @see og_project_settings_form()
 */
function _og_project_audience_setting($type, $variable) {
  $placeholders['%project'] = node_get_types('name', 'project_project');
  $placeholders['%node_type'] = node_get_types('name', $type);

  $group_behavior = variable_get("og_content_type_usage_$type", 'group_post_standard');
  if ($group_behavior == 'group_post_standard' || $group_behavior == 'group_post_wiki') {
    return array(
      '#title' => t('Automatically set group audience for %node_type content', $placeholders),
      '#type' => 'checkbox',
      '#default_value' => variable_get($variable, FALSE),
      '#description' => t('If enabled, the group audience field for %node_type content will automatically be set to the %project that the %node_type belongs to.', $placeholders),
    );
  }
  else {
    $placeholders['!node_type_edit_url'] = url('admin/content/node-type/' . str_replace('_', '-', $type), array('query' => drupal_get_destination()));
    return array(
      '#type' => 'markup',
      '#value' => t('%node_type nodes are not configured so they can be posted to an Organic Group. If you would like to change this, you can <a href="!node_type_edit_url">edit the %node_type content type</a> and alter the "Organic Groups usage" setting.', $placeholders),
    );
  }
}

