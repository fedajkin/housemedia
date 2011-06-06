<?php
// $Id: sweaver_plugin_themesettings.inc,v 1.1.2.31 2010/11/01 13:06:55 jyve Exp $

/**
 * @file
 * Theme settings plugin.
 */
class sweaver_plugin_themesettings extends sweaver_plugin {

  /**
   * Init function.
   */
  public function sweaver_init() {
    // Override theme settings in $conf variable when in Draft.
    if (sweaver_session(NULL, 'draft_mode') || sweaver_session(NULL, 'sweaver_temp')) {
      $sweaver = Sweaver::get_instance();
      $sweaver_style = $sweaver->get_current_style();
      if (isset($sweaver_style->themesettings) && !empty($sweaver_style->themesettings)) {
        global $conf;
        $theme_settings_name = str_replace('/', '_', 'theme_'. $sweaver->get_theme_key() .'_settings');
        $conf[$theme_settings_name] = unserialize($sweaver_style->themesettings);
      }
    }
  }

  /**
   * Frontend form.
   */
  public function sweaver_form() {
    $form = array();
    $form['#popups'] = array();

    // Get theme settings form.
    $themesettings = array();
    $sweaver = Sweaver::get_instance();
    $sweaver_style = $sweaver->get_current_style();
    if (isset($sweaver_style->themesettings) && !empty($sweaver_style->themesettings)) {
      $themesettings = unserialize($sweaver_style->themesettings);
    }
    $form = $this->sweaver_get_theme_settings_form($sweaver->get_theme_key(), $themesettings);

    // Add extra property for theme settings which need to be saved also.
    // Form alters on the theme settings form must be put those keys in this array.
    $form['#sweaver_other_themesettings'] = array();

    // Let other modules alter the form.
    $form_state = array();
    drupal_prepare_form('system_theme_settings', $form, $form_state);
    // We need to unset the #type, otherwise a nested form is created, which breaks in IE7.
    unset($form['#type']);

    // Convert all fieldsets to buttons. The content of those fieldsets
    // will be moved into the Sweaver popup.
    $i = 1;
    $weight = -100;
    foreach (element_children($form) as $key) {
      if (isset($form[$key]['#type']) && $form[$key]['#type'] == 'fieldset') {

        // Skip fieldsets which the user doesn't have access to.
        if (isset($form[$key]['#access']) && $form[$key]['#access'] === FALSE) {
          continue;
        }

        $title = $form[$key]['#title'];

        $form['item_'. $i] = array(
          '#type' => 'markup',
          '#value' => '<div class="popup-link"><a href="#" id="theme-settings-link-'. $i .'">'. check_plain($title) .'</a></div>',
          '#weight' => $weight++,
        );

        if (isset($form[$key]['#prefix'])) {
          $form[$key]['#prefix'] .= '<div style="display:none" id="theme-settings-data-'. $i .'">';
        }
        else {
          $form[$key]['#prefix'] = '<div style="display:none"id="theme-settings-data-'. $i .'">';
        }

        if (isset($form[$key]['#suffix'])) {
          $form[$key]['#suffix'] = '</div>'. $form[$key]['#suffix'];
        }
        else {
          $form[$key]['#suffix'] = '</div>';
        }

        unset($form[$key]['#collapsible']);
        unset($form[$key]['#collapsed']);
        unset($form[$key]['#attributes']);

        // Add to popups.
        $form['#popups'][] = $key;

        $i++;
      }
    }

    // Deny access to the buttons and add our own.
    $form['buttons']['#access'] = FALSE;
    $form['theme_settings_apply'] = array(
      '#type' => 'submit',
      '#value' => t('Apply theme settings'),
      '#prefix' => '<div class="clear-block"></div>',
    );

    return $form;
  }

  /**
   * Frontend form submit.
   */
  public function sweaver_form_submit($form, &$form_state) {

    $values = $form_state['values'];
    $theme_key = $values['var'];
    $clicked_button = $form_state['clicked_button']['#value'];

    // Save style.
    if ($clicked_button == t('Save and continue') || $clicked_button == t('Save and publish') || $clicked_button == t('Publish style') || $clicked_button == t('Apply theme settings')) {

      // Style id is not always set.
      $style_id = isset($form_state['style_id']) ? $form_state['style_id'] : 'temp';

      // General theme settings.
      $theme_values = array();
      $theme_settings_form = $form['sweaver_plugin_themesettings']['form']['theme_settings'];
      $theme_form_keys = element_children($theme_settings_form);

      // Logo and favicon.
      if (isset($form['sweaver_plugin_themesettings']['form']['logo'])) {
        $theme_form_keys = array_merge($theme_form_keys, array('default_logo', 'logo_path', 'logo_upload'));
      }
      if (isset($form['sweaver_plugin_themesettings']['form']['favicon'])) {
        $theme_form_keys = array_merge($theme_form_keys, array('default_favicon', 'favicon_path', 'favicon_upload'));
      }

      // Theme specific settings.
      if (isset($form['sweaver_plugin_themesettings']['form']['theme_specific'])) {
        $theme_specific_keys = array();
        $fapi_types = array('select', 'checkbox', 'checkboxes', 'textfield', 'textarea', 'value', 'hidden', 'radio', 'weight', 'radios');
        $this->sweaver_get_theme_specific_keys($form['sweaver_plugin_themesettings']['form']['theme_specific'], $theme_specific_keys, $fapi_types);
        $theme_form_keys = array_merge($theme_form_keys, $theme_specific_keys);
      }

      // Other variables which are set by other form alters.
      // All keys must be put in a $form['#sweaver_other_themesettings'];
      $theme_form_keys = array_merge($theme_form_keys, $form['sweaver_plugin_themesettings']['form']['#sweaver_other_themesettings']);

      // Only save the necessary theme values.
      foreach ($values as $fkey => $fvalue) {
        if (in_array($fkey, $theme_form_keys)) {
          $theme_values[$fkey] = $fvalue;
        }
      }

      // Rename logo / favicon when needed.
      foreach (array('logo_path', 'favicon_path') as $file) {

        $type = str_replace('_path', '', $file);
        $theme_name = $form['#current_theme'];

        // Rename when just uploaded.
        if (isset($form['sweaver_plugin_themesettings']['form']['#'. $file])) {
          $source_path = file_directory_path() .'/'. $form['sweaver_plugin_themesettings']['form']['#'. $file];
          $dest_draft = 'sweaver/'. $type .'_'. $theme_name .'_'. $style_id .'_draft.'. $form['sweaver_plugin_themesettings']['form']['#'. $file .'_extension'];
          file_move($source_path, $dest_draft, FILE_EXISTS_REPLACE);
          $theme_values[$file] = file_directory_path() .'/'. $dest_draft;
        }

        // Create the default variable for this file.
        $default = 'default_'. str_replace('_path', '', $file);

        // Move temporary if needed.
        if ($style_id != 'temp' && !$theme_values[$default] && !empty($theme_values[$file]) && strpos($theme_values[$file], 'temp_draft') !== FALSE) {
          $parts = pathinfo($theme_values[$file]);
          $temp_path = $theme_values[$file];
          $dest_draft = 'sweaver/'. $type .'_'. $theme_name .'_'. $style_id .'_draft.'. $parts['extension'];
          file_move($temp_path, $dest_draft, FILE_EXISTS_REPLACE);
          $theme_values[$file] = file_directory_path() .'/'. $dest_draft;
        }

        // Copy to live if save_live is found. Can either be directly after the upload
        // or when setting a style live after the uploads were done already.
        if (isset($form_state['publish']) && $form_state['publish'] && !$theme_values[$default] && !empty($theme_values[$file])) {
          $source_path = $theme_values[$file];
          $dest_live = str_replace('_draft', '_live', $theme_values[$file]);
          file_copy($source_path, $dest_live, FILE_EXISTS_REPLACE);
          $theme_values[$file] = $dest_live;
        }
      }

      // Save when style_id is found. Always save the draft version. If the
      // save_live key is found also update the live table.
      if ($style_id != 'temp') {
        $theme_values_serialized = serialize($theme_values);
        db_query("UPDATE {sweaver_style_draft} set themesettings = '%s' WHERE style_id = %d", $theme_values_serialized, $style_id);
        if ($form_state['publish']) {
          variable_set($theme_key, $theme_values);
          db_query("UPDATE {sweaver_style} set themesettings = '%s' WHERE style_id = %d", $theme_values_serialized, $style_id);
        }

        // Fire other submit functions on the theme settings form.
        $submit_handlers = isset($form['sweaver_plugin_themesettings']['form']['#submit']) ? $form['sweaver_plugin_themesettings']['form']['#submit'] : array();
        foreach ($submit_handlers as $key => $function) {
          if (function_exists($function)) {
            $function($form['sweaver_plugin_themesettings']['form'], $form_state);
          }
        }
      }
      else {
        // Save to CTools object cache.
        $sweaver = Sweaver::get_instance();
        ctools_include('object-cache');
        $style = $sweaver->get_current_style();
        if (!isset($style->style_id)) {
          $style = new stdClass;
          $style->style_id = 0;
          $style->style = t('Temporary');
          $style->css = '';
          $style->customcss = '';
          $style->palette = '';
        }
        $style->themesettings = serialize($theme_values);
        ctools_object_cache_set('sweaver-styling', 'sweaver-styling', $style);
        sweaver_session(t('The theme settings have been applied.'));
        sweaver_session(TRUE, 'sweaver_temp');
      }
    }

    // Delete style.
    if (isset($form_state['style_to_delete'])) {
      $style = $form_state['style_to_delete'];

      // Reset theme settings when active.
      if ($form_state['style_active']) {
        variable_del($theme_key);
      }
    }
  }

  /**
   * Frontend css and js.
   */
  public function sweaver_form_css_js(&$inline_settings) {
    drupal_add_js('misc/collapse.js');
  }

  /**
   * Get theme specific keys.
   */
  public function sweaver_get_theme_specific_keys($theme_specific_form, &$theme_specific_keys, $fapi_types) {
    $children = element_children($theme_specific_form);
    foreach ($children as $element) {
      if (in_array($theme_specific_form[$element]['#type'], $fapi_types)) {
        $theme_specific_keys[] = $element;
      }
      else {
        $this->sweaver_get_theme_specific_keys($theme_specific_form[$element], $theme_specific_keys, $fapi_types);
      }
    }
  }

  /**
   * Get theme settings form.
   * We basically copy the form from system.admin.inc. This makes it easer to
   * copy the uploads of the favicon & logo to revision versions of the style
   * and getting the right settings for the theme.
   *
   * People altering form and having also uploads wishing to work with sweaver must
   * handle the revisioning themeselves.
   *
   * @param $key
   *   The name of the theme.
   * @param $revision_theme_settings
   *   Revisions theme settings.
   */
  public function sweaver_get_theme_settings_form($key, $revision_theme_settings) {
    $has_theme = FALSE;

    // Default settings are defined in theme_get_settings() in includes/theme.inc
    if ($key) {
      $settings = theme_get_settings($key);
      $var = str_replace('/', '_', 'theme_'. $key .'_settings');
      $themes = sweaver_get_all_themes();
      if (isset($themes[$key]->info['features'])) {
        $has_theme = TRUE;
        $features = $themes[$key]->info['features'];
      }
    }

    if (!$has_theme) {
      $settings = theme_get_settings('');
      $var = 'theme_settings';
    }
    if (!empty($revision_theme_settings)) {
      $settings = $revision_theme_settings;
    }

    $form['var'] = array('#type' => 'hidden', '#value' => $var);

    // Check for a new uploaded logo. Put it in the form
    // so we can give it the right filename in the submit function.
    if ($file = file_save_upload('logo_upload', array('file_validate_is_image' => array()))) {
      $parts = pathinfo($file->filename);
      $filename = 'sweaver/temp_logo.'. $parts['extension'];
      $form['#logo_path'] = $filename;
      $form['#logo_path_extension'] = $parts['extension'];

      // The image was saved using file_save_upload() and was added to the
      // files table as a temporary file. We'll make a copy and let the garbage
      // collector delete the original upload.
      if (file_copy($file, $filename, FILE_EXISTS_REPLACE)) {
        $_POST['default_logo'] = 0;
        $_POST['logo_path'] = $file->filepath;
        $_POST['toggle_logo'] = 1;
      }
    }

    // Check for a new uploaded favicon. Put it in the form
    // so we can give it the right filename in the submit function.
    if ($file = file_save_upload('favicon_upload')) {
      $parts = pathinfo($file->filename);
      $filename = 'sweaver/temp_favicon.'. $parts['extension'];
      $form['#favicon_path'] = $filename;
      $form['#favicon_path_extension'] = $parts['extension'];

      // The image was saved using file_save_upload() and was added to the
      // files table as a temporary file. We'll make a copy and let the garbage
      // collector delete the original upload.
      if (file_copy($file, $filename)) {
        $_POST['default_favicon'] = 0;
        $_POST['favicon_path'] = $file->filepath;
        $_POST['toggle_favicon'] = 1;
      }
    }

    // Toggle settings
    $toggles = array(
      'logo'                 => t('Logo'),
      'name'                 => t('Site name'),
      'slogan'               => t('Site slogan'),
      'mission'              => t('Mission statement'),
      'node_user_picture'    => t('User pictures in posts'),
      'comment_user_picture' => t('User pictures in comments'),
      'search'               => t('Search box'),
      'favicon'              => t('Shortcut icon'),
      'primary_links'        => t('Primary links'),
      'secondary_links'      => t('Secondary links'),
    );

    // Some features are not always available
    $disabled = array();
    if (!variable_get('user_pictures', 0)) {
      $disabled['toggle_node_user_picture'] = TRUE;
      $disabled['toggle_comment_user_picture'] = TRUE;
    }
    if (!module_exists('search')) {
      $disabled['toggle_search'] = TRUE;
    }

    $form['theme_settings'] = array(
      '#type' => 'fieldset',
      '#title' => t('Toggle display'),
      '#description' => t('Enable or disable the display of certain page elements.'),
    );
    foreach ($toggles as $name => $title) {
      if ((!$key) || in_array($name, $features)) {
        $form['theme_settings']['toggle_'. $name] = array('#type' => 'checkbox', '#title' => check_plain($title), '#default_value' => $settings['toggle_'. $name]);
        // Disable checkboxes for features not supported in the current configuration.
        if (isset($disabled['toggle_'. $name])) {
          $form['theme_settings']['toggle_'. $name]['#disabled'] = TRUE;
        }
      }
    }

    // System wide only settings.
    if (!$key) {
      // Create neat 2-column layout for the toggles
      $form['theme_settings'] += array(
        '#prefix' => '<div class="theme-settings-left">',
        '#suffix' => '</div>',
      );

      // Toggle node display.
      $node_types = node_get_types('names');
      if ($node_types) {
        $form['node_info'] = array(
          '#type' => 'fieldset',
          '#title' => t('Display post information on'),
          '#description' => t('Enable or disable the <em>submitted by Username on date</em> text when displaying posts of the following type.'),
          '#prefix' => '<div class="theme-settings-right">',
          '#suffix' => '</div>',
        );
        foreach ($node_types as $type => $name) {
          $form['node_info']["toggle_node_info_$type"] = array('#type' => 'checkbox', '#title' => check_plain($name), '#default_value' => $settings["toggle_node_info_$type"]);
        }
      }
    }
    elseif (!element_children($form['theme_settings'])) {
      // If there is no element in the theme settings fieldset then do not show
      // it -- but keep it in the form if another module wants to alter.
      $form['theme_settings']['#access'] = FALSE;
    }

    // Logo settings
    if ((!$key) || in_array('logo', $features)) {
      $form['logo'] = array(
        '#type' => 'fieldset',
        '#title' => t('Logo image settings'),
        '#description' => t('If toggled on, the following logo will be displayed.'),
        '#attributes' => array('class' => 'theme-settings-bottom'),
      );
      $form['logo']['default_logo'] = array(
        '#type' => 'checkbox',
        '#title' => t('Use the default logo'),
        '#default_value' => $settings['default_logo'],
        '#tree' => FALSE,
        '#description' => t('Check here if you want the theme to use the logo supplied with it.')
      );
      $form['logo']['logo_path'] = array(
        '#type' => 'textfield',
        '#title' => t('Path to custom logo'),
        '#default_value' => $settings['logo_path'],
        '#description' => t('The path to the file you would like to use as your logo file instead of the default logo.'));

      $form['logo']['logo_upload'] = array(
        '#type' => 'file',
        '#title' => t('Upload logo image'),
        '#maxlength' => 40,
        '#description' => t("If you don't have direct file access to the server, use this field to upload your logo.")
      );
    }

    if ((!$key) || in_array('favicon', $features)) {
      $form['favicon'] = array(
        '#type' => 'fieldset',
        '#title' => t('Shortcut icon settings'),
        '#description' => t("Your shortcut icon, or 'favicon', is displayed in the address bar and bookmarks of most browsers.")
      );
      $form['favicon']['default_favicon'] = array(
        '#type' => 'checkbox',
        '#title' => t('Use the default shortcut icon.'),
        '#default_value' => $settings['default_favicon'],
        '#description' => t('Check here if you want the theme to use the default shortcut icon.')
      );
      $form['favicon']['favicon_path'] = array(
        '#type' => 'textfield',
        '#title' => t('Path to custom icon'),
        '#default_value' => $settings['favicon_path'],
        '#description' => t('The path to the image file you would like to use as your custom shortcut icon.')
      );

      $form['favicon']['favicon_upload'] = array(
        '#type' => 'file',
        '#title' => t('Upload icon image'),
        '#description' => t("If you don't have direct file access to the server, use this field to upload your shortcut icon.")
      );
    }

    if ($key) {
      // Include the theme's theme-settings.php file
      $filename = './'. str_replace("/$key.info", '', $themes[$key]->filename) .'/theme-settings.php';
      if (!file_exists($filename) and !empty($themes[$key]->info['base theme'])) {
        // If the theme doesn't have a theme-settings.php file, use the base theme's.
        $base = $themes[$key]->info['base theme'];
        $filename = './'. str_replace("/$base.info", '', $themes[$base]->filename) .'/theme-settings.php';
      }
      if (file_exists($filename)) {
        require_once $filename;
      }

      // Call engine-specific settings.
      $function = $themes[$key]->prefix .'_engine_settings';
      if (function_exists($function)) {
        $group = $function($settings);
        if (!empty($group)) {
          $form['engine_specific'] = array('#type' => 'fieldset', '#title' => t('Theme-engine-specific settings'), '#description' => t('These settings only exist for all the templates and styles based on the %engine theme engine.', array('%engine' => $themes[$key]->prefix)));
          $form['engine_specific'] = array_merge($form['engine_specific'], $group);
        }
      }
      // Call theme-specific settings.
      $function = $key .'_settings';
      if (!function_exists($function)) {
        $function = $themes[$key]->prefix .'_settings';
      }
      if (function_exists($function)) {
        $group = $function($settings);
        if (!empty($group)) {
          $form['theme_specific'] = array('#type' => 'fieldset', '#title' => t('Theme-specific settings'), '#description' => t('These settings only exist for the %theme theme and all the styles based on it.', array('%theme' => $themes[$key]->info['name'])));
          $form['theme_specific'] = array_merge($form['theme_specific'], $group);
        }
      }
    }

    return $form;
  }
}
