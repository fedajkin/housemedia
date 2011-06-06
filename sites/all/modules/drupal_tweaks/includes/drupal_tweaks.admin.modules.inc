<?php

/**
 * @file
 *   Form with Module Manager
 *
 * @version
 *
 * @developers
 *   Rafal Wieczorek <kenorb@gmail.com>
 */

/**
 * Menu callback for the settings operation form
 */
function drupal_tweaks_modules_form($form_state) {
  module_load_include('inc', 'drupal_tweaks'); // load additional functions from included file
  drupal_tweaks_include_shared_code();

  if (isset($form_state['values']['operation']) && $form_state['values']['operation'] == 'delete') {
    return drupal_tweaks_modules_multiple_uninstall_confirm($form_state, array_filter($form_state['values']['modules']));
  }
  $form = drupal_tweaks_modules_filter_form();
  
  $form['#theme'] = 'node_filter_form';
  $form['admin']  = drupal_tweaks_module_admin_modules();
    
  return $form;
}

/**
 * Return form for node administration filters.
 */
function drupal_tweaks_modules_filter_form() {
  $session = &$_SESSION['drupal_tweaks_modules_overview_filter'];
  $session = is_array($session) ? $session : array();
  $filters = drupal_tweaks_module_filters();

  $i = 0;
  $form['filters'] = array(
    '#type' => 'fieldset',
    '#title' => t('Show only items where'),
    '#theme' => 'node_filters',
  );
  $form['#submit'][] = 'drupal_tweaks_modules_filter_form_submit';
  foreach ($session as $filter) {
    list($type, $value) = $filter;
    $value = $filters[$type]['options'][$value];
    if ($i++) {
      $form['filters']['current'][] = array('#value' => t('<em>and</em> where <strong>%a</strong> is <strong>%b</strong>', array('%a' => $filters[$type]['title'], '%b' => $value)));
    }
    else {
      $form['filters']['current'][] = array('#value' => t('<strong>%a</strong> is <strong>%b</strong>', array('%a' => $filters[$type]['title'], '%b' => $value)));
    }
  }

  foreach ($filters as $key => $filter) {
    $names[$key] = $filter['title'];
    $form['filters']['status'][$key] = array('#type' => 'select', '#options' => $filter['options']);
  }

  $form['filters']['filter'] = array('#type' => 'radios', '#options' => $names, '#default_value' => 'status');
  $form['filters']['buttons']['submit'] = array('#type' => 'submit', '#value' => (count($session) ? t('Refine') : t('Filter')));
  if (count($session)) {
    $form['filters']['buttons']['undo'] = array('#type' => 'submit', '#value' => t('Undo'));
    $form['filters']['buttons']['reset'] = array('#type' => 'submit', '#value' => t('Reset'));
  }

  $form['filters']['current'][] = array(
     '#type' => 'textfield',
     '#title' => t('Name contains'),
     '#attributes' => array(
      //'onkeydown' => "return filter_modules(this, event);",
      'onkeyup' => "return filter_modules_keyup(this, event);",
      'onblur' => "return filter_modules_blur(this);"
      ),
     '#description' => t('Type part of module name.'),
     //'#autocomplete_path' => 'admin/drupal_tweaks/autocomplete/filter_modules',
     '#size' => 30,
     '#maxlength' => 60,
   );

  $js_code = "
        function filter_modules_blur(input)
        {
            if (input.value.length > 0)
                find_mod_matches(input.value);
            else
                set_mod_matches('table-row');
        }

        function filter_modules_keyup(input, e)
        {
            if (!e) {
                e = window.event;
            }
            switch (e.keyCode) {
                case 16: // shift
                case 17: // ctrl
                case 18: // alt
                case 20: // caps lock
                case 33: // page up
                case 34: // page down
                case 35: // end
                case 36: // home
                case 37: // left arrow
                case 38: // up arrow
                case 39: // right arrow
                case 40: // down arrow
                case 9:  // tab
                case 13: // enter
                case 27: // esc
                    return true;

                default: // all other keys
                    if (input.value.length > 0)
                        find_mod_matches(input.value);
                    else
                        set_mod_matches('table-row');
                    return true;
            }
        }

        function set_mod_matches(display)
        {
            $('tbody').children('tr').each(function() {
                $(this).css('display', display);
            });
        }

        var timer = null;

        function find_mod_matches(value)
        {
            if (this.timer) {
                clearTimeout(this.timer);
            }
            this.timer = setTimeout(function() {
                $.ajax({
                    type: 'GET',
                    url: '". check_url(url("admin/drupal_tweaks/autocomplete/filter_modules/", array('absolute' => TRUE))) ."' + value,
                    dataType: 'json',
                    success: function (matches) {
                        set_mod_matches('none');

                        $.each(matches, function(index, value) {
                          if($( '#' + value ).length)
                             $( '#' + value ).parent().parent().css('display', 'table-row');
                        });
                    },
                    error: function (xmlhttp) {
                        alert(Drupal.ahahError(xmlhttp, 'URL'));
                    }
                });

            }, 500);
        }
        ";

  drupal_add_js($js_code, 'inline');

  drupal_add_js('misc/form.js', 'core');

  return $form;
}

/**
 * Process result from node administration filter form.
 */
function drupal_tweaks_modules_filter_form_submit($form, &$form_state) {
  $filters = drupal_tweaks_module_filters();
  switch ($form_state['values']['op']) {
    case t('Filter'):
    case t('Refine'):
      if (isset($form_state['values']['filter'])) {
        $filter = $form_state['values']['filter'];

        // Flatten the options array to accommodate hierarchical/nested options.
        $flat_options = form_options_flatten($filters[$filter]['options']);

        if (isset($flat_options[$form_state['values'][$filter]])) {
          $_SESSION['drupal_tweaks_modules_overview_filter'][] = array($filter, $form_state['values'][$filter]);
        }
      }
      break;
    case t('Undo'):
      array_pop($_SESSION['drupal_tweaks_modules_overview_filter']);
      break;
    case t('Reset'):
      $_SESSION['drupal_tweaks_modules_overview_filter'] = array();
      break;
  }
}

/** 
 * List module administration filters that can be applied.
 */
function drupal_tweaks_module_filters() {
  // Regular filters
  $filters['status'] = array(
    'title' => t('status'),
    'options' => array(
      'status|1' => t('enabled'),
      'status|0' => t('disabled'), 
      'schema_version|-1' => t('uninstalled'),
      // 'schema_version|!-1' => t('not uninstalled'), // TODO
    ),
  );

  // $filters['package'] = array('title' => t('package'), 'options' => node_get_types('names')); // TODO

  return $filters;
}

/**
 * Form builder: Builds the node administration overview.
 */
function drupal_tweaks_module_admin_modules() {

  $filter = drupal_tweaks_module_build_filter_query();

  $result = db_query('SELECT * FROM {system} s '. $filter['join'] . ' ' . $filter['where'] .' ORDER BY s.weight DESC');

  $form['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Module operations'),
    '#prefix' => '<div class="container-inline">',
    '#suffix' => '</div>',
  );

  $options = array();
  foreach (module_invoke_all('drupal_tweaks_module_operations') as $operation => $array) {
    $options[$operation] = $array['label'];
  }
  $form['options']['operation'] = array(
    '#type' => 'select',
    '#options' => $options,
    '#default_value' => 'approve',
  );
  $form['options']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Execute'),
    '#submit' => array('drupal_tweaks_module_admin_modules_submit'),
  );

  $destination = drupal_get_destination();
  $nodes = array();
  while ($module = db_fetch_object($result)) {
    $modules[$module->name] = '';
    $info = (object)unserialize($module->info);
// var_dump($info); exit;
    $form['name'][$module->name] = array('#value' => l($info->name, 'http://drupal.org/project/'. $module->name, array('attributes' => array('target' => '_blank'))));
    $form['raw_name'][$module->name] =  array('#value' => $module->name, "#prefix" => '<div id="'. $module->name .'">', "#suffix" => "</div>");
    $form['version'][$module->name] =  array('#value' => $info->version);
    $form['package'][$module->name] = array('#value' => $info->package);
    $form['schema'][$module->name] = array('#value' => $module->schema_version);
    $form['status'][$module->name] =  array('#value' => ($module->status ? t('enabled') : t('disabled')));
    // $form['operations'][$module->name] = array('#value' => l(t('edit'), 'node/'. $module->name .'/edit', array('query' => $destination)));
  }
  $form['modules'] = array('#type' => 'checkboxes', '#options' => $modules);
  //$form['pager'] = array('#value' => theme('pager', NULL, 50, 0));
  $form['#theme'] = 'drupal_tweaks_module_admin_modules';
  return $form;
}

/**
 * Process drupal_tweaks_module_admin_modules form submissions.
 * 
 * Execute the chosen 'Update option' on the selected modules.
 */
function drupal_tweaks_module_admin_modules_submit($form, &$form_state) {
  $operations = module_invoke_all('drupal_tweaks_module_operations');
  $operation = $operations[$form_state['values']['operation']];
  // Filter out unchecked nodes
  $modules = array_filter($form_state['values']['modules']);
  if ($function = $operation['callback']) {
    // Add in callback arguments if present.
    if (isset($operation['callback arguments'])) {
      $args = array_merge(array($modules), $operation['callback arguments']);
    }
    else {
      $args = array($modules);
    }
    call_user_func_array($function, $args);

    cache_clear_all();
  }
  else {
    // We need to rebuild the form to go to a second step.  For example, to
    // show the confirmation form for the deletion of nodes.
    $form_state['rebuild'] = TRUE;
  }
}

/**
 * Build query for node administration filters based on session.
 */
function drupal_tweaks_module_build_filter_query() {
  $filters = drupal_tweaks_module_filters();

  // Build query
  $where = $args = array();
  $where[] = "s.type = 'module'";
  $join = '';
  foreach ($_SESSION['drupal_tweaks_modules_overview_filter'] as $index => $filter) {
    list($key, $value) = $filter;
    switch ($key) {
      case 'status':
        // Note: no exploitable hole as $key/$value have already been checked when submitted
        list($key, $value) = explode('|', $value, 2);
        $where[] = 's.'. $key .' = %d';
        break;
      case 'package':
        // $where[] = "s.type = '%s'";
        break;
    }
    $args[] = $value;
  }
  $where = count($where) ? 'WHERE '. implode(' AND ', $where) : '';

  return array('where' => $where, 'join' => $join, 'args' => $args);
}

function drupal_tweaks_modules_multiple_uninstall_confirm(&$form_state, $modules) {

  $form['modules'] = array('#prefix' => '<ul>', '#suffix' => '</ul>', '#tree' => TRUE);
  // array_filter returns only elements with TRUE values
  foreach ($modules as $mname => $value) {
    $info = db_result(db_query('SELECT info FROM {system} WHERE name = %s', $mname));
    $title = unserialize($info)->name;
    $form['modules'][$mname] = array(
      '#type' => 'hidden',
      '#value' => $mname,
      '#prefix' => '<li>',
      '#suffix' => check_plain($title) ."</li>\n",
    );
  }
  $form['operation'] = array('#type' => 'hidden', '#value' => 'delete');
  $form['#submit'][] = 'drupal_tweaks_modules_multiple_uninstall_confirm_submit';
  return confirm_form($form,
                      t('Are you sure you want to uninstall these modules?'),
                      'admin/drupal_tweaks/modules', t('This action cannot be undone.'),
                      t('Uninstall all'), t('Cancel'));
}

function drupal_tweaks_modules_multiple_uninstall_confirm_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    foreach ($form_state['values']['modules'] as $mname => $value) {
      drupal_set_message(t('Removed %module.'), array('%module' => $mname));
      // node_delete($nid);
    }
    drupal_set_message(t('The selected modules have been uninstalled.'));
  }
  $form_state['redirect'] = 'admin/drupal_tweaks/modules';
  return;
}

/**
 * Implementation of hook_drupal_tweaks_module_operations().
 */
function drupal_tweaks_drupal_tweaks_module_operations() {
  $operations = array(
    'install' => array(
      'label' => t('Install'),
      'callback' => 'drupal_tweaks_module_op_mass_update',
      'callback arguments' => array('op' => 'install'),
    ),
    'disable' => array(
      'label' => t('Disable'),
      'callback' => 'drupal_tweaks_module_op_mass_update',
      'callback arguments' => array('op' => 'disable'),
    ),
    'uninstall' => array(
      'label' => t('Disable & Uninstall'),
      'callback' => 'drupal_tweaks_module_op_mass_update',
      'callback arguments' => array('op' => 'uninstall'),
    ),
    'reenable' => array(
      'label' => t('Disable & Enable again'),
      'callback' => 'drupal_tweaks_module_op_mass_update',
      'callback arguments' => array('op' => 'reenable'),
    ),
    'reinstall' => array(
      'label' => t('Uninstall & Install again'),
      'callback' => 'drupal_tweaks_module_op_mass_update',
      'callback arguments' => array('op' => 'reinstall'),
    ),
  );
  return $operations;
}

/**
 * Implementation of hook_drupal_tweaks_module_operations() callback
 */
function drupal_tweaks_module_op_install() {
}

/**
 * Make mass update of modules
 *
 * IMPORTANT NOTE: This function is intended to work when called
 * from a form submit handler. Calling it outside of the form submission
 * process may not work correctly.
 *
 * @param array $modules
 *   Array of module names to update.
 * @param array $updates
 *   Array of key/value pairs with node field names and the
 *   value to update that field to.
 */
function drupal_tweaks_module_op_mass_update($modules, $op) {
  // We use batch processing to prevent timeout when updating a large number
  // of nodes.
  if (count($modules) > 10) {
    $batch = array(
      'operations' => array(
        array('_module_mass_update_batch_process', array($modules, $op))
      ),
      'finished' => '_module_mass_update_batch_finished',
      'title' => t('Processing'),
      // We use a single multi-pass operation, so the default
      // 'Remaining x of y operations' message will be confusing here.
      'progress_message' => '',
      'error_message' => t('The operation has encountered an error.'),
      // The operations do not live in the .module file, so we need to
      // tell the batch engine which file to load before calling them.
      'file' => drupal_get_path('module', 'drupal_tweaks') .'/includes/drupal_tweaks.admin.modules.inc',
    );
    batch_set($batch);
  }
  else {
    foreach ($modules as $mname) {
      _module_mass_update_helper($mname, $op);
    }
    drupal_set_message(t('The operation has been performed.'));
  }
}

/**
 * Module Mass Update Batch operation
 */
function _module_mass_update_batch_process($modules, $op, &$context) {
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = count($modules);
    $context['sandbox']['modules'] = $modules;
  }

  // Process modules by groups of 5.
  $count = min(5, count($context['sandbox']['modules']));
  for ($i = 1; $i <= $count; $i++) {
    $mname = array_shift($context['sandbox']['modules']);
    $module = _module_mass_update_helper($mname, $op);

    // Store result for post-processing in the finished callback.
    $context['results'][] = l($module->name, 'node/'. $module->name);

    // Update our progress information.
    $context['sandbox']['progress']++;
  }

  // Inform the batch engine that we are not finished,
  // and provide an estimation of the completion level we reached.
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

/**
 * Module Mass Update - helper function.
 */
function _module_mass_update_helper($mname, $op) {
    switch ($op) {
        case 'disable':
                module_disable(array($mname));
                if (!module_exists($module_disable)) {
                  drupal_set_message(t('Module %module has been successfully disabled.', array('%module' => $mname)));
                  cache_clear_all();
                  drupal_clear_css_cache();
                  drupal_clear_js_cache();
                  actions_synchronize(); // Synchronize to catch any actions that were added or removed. 
                } else {
                  drupal_set_message(t('Unknown error on disabling %module module.', array('%module' => $mname)), 'error');
                }
            break;
        case 'install':
                module_enable(array($mname));

                if (module_exists($mname)) {
                    module_load_include('inc', 'drupal_tweaks'); // load additional functions from included file
                    drupal_set_message(t('Module %module has been successfully enabled.', array('%module' => $mname)));
                    drupal_tweaks_module_check_db_changes($mname);

                    include_once './includes/install.inc';
                    if (drupal_get_installed_schema_version($mname) == SCHEMA_UNINSTALLED && drupal_check_module($mname)) {
                        drupal_install_modules(array($mname));
                        drupal_set_message(t('Module %module has been installed.', array('%module' => $mname)));
                    }

                    drupal_rebuild_theme_registry();
                    node_types_rebuild();
                    cache_clear_all('schema', 'cache');
                    drupal_clear_css_cache();
                    drupal_clear_js_cache();

                    // Notify locale module about module changes, so translations can be
                    // imported. This might start a batch, and only return to the redirect
                    // path after that.
                    module_invoke('locale', 'system_update', array($mname));

                    // Synchronize to catch any actions that were added or removed.
                    actions_synchronize();
                } else {
                  drupal_set_message(t('Unknown error on enabling %module module.', array('%module' => $mname)), 'error');
                }

            break;
        case 'uninstall':
                _module_mass_update_helper($mname, 'disable');
                drupal_uninstall_module($mname);
                drupal_set_message(t('Module %module has been uninstalled.', array('%module' => $mname)));
                break;
        case 'reenable':
                _module_mass_update_helper($mname, 'disable');
                _module_mass_update_helper($mname, 'install');
                break;
        case 'reinstall':
                _module_mass_update_helper($mname, 'uninstall');
                _module_mass_update_helper($mname, 'install');
                break;
    }
    return array('name' => $mname);
}

