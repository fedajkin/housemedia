<?php
// $Id: sweaver_plugin_images.inc,v 1.1.2.16 2010/10/02 02:03:33 swentel Exp $

/**
 * @file
 * Images plugin.
 */
class sweaver_plugin_images extends sweaver_plugin {

  /**
   * Menu registry.
   */
  public function sweaver_menu(&$weight, $page_arguments, $base) {

    $items = array();

    $items['admin/settings/sweaver/images'] = $base + array(
      'title' => 'Images',
      'page arguments' => array($page_arguments),
      'type' => MENU_LOCAL_TASK,
      'weight' => $weight++,
    );
    $page_arguments['callback_method'] = 'sweaver_images_backend_form';
    $items['admin/settings/sweaver/images/add'] = $base + array(
      'title' => 'Add new image',
      'page arguments' => array($page_arguments),
      'type' => MENU_CALLBACK,
    );
    $page_arguments['callback_method'] = 'sweaver_images_backend_form';
    $items['admin/settings/sweaver/images/edit'] = $base + array(
      'title' => 'Edit image',
      'page arguments' => array($page_arguments),
      'type' => MENU_CALLBACK,
    );
    $page_arguments['callback_method'] = 'sweaver_images_confirm_form_delete';
    $items['admin/settings/sweaver/images/delete'] = $base + array(
      'title' => 'Add new image',
      'page arguments' => array($page_arguments),
      'type' => MENU_CALLBACK,
    );

    return $items;
  }

  /**
   * Frontend form: add image form.
   */
  public function sweaver_form() {
    $form = array();

    if (variable_get('sweaver_plugin_images_tab', TRUE)) {
      $form['image_form']['image_description'] = array(
        '#type' => 'textfield',
        '#title' => t('Description'),
        '#description' => t('Description of the image used in the select box for files.')
      );
      $form['image_form']['image_image'] = array(
        '#type' => 'file',
        '#title' => t('Image'),
        '#size' => '40',
        '#description' => t('Upload images which you can use as background images. Extensions are limited to jpg, jpeg, png and gif.<br />Note: there is no scaling on the images on upload.'),
      );
      $form['image_form']['image_submit'] = array(
        '#type' => 'submit',
        '#value' => t('Save image'),
      );
    }

    return $form;
  }

  /**
   * Frontend form submit handler.
   */
  public function sweaver_form_submit($form, &$form_state) {

    if ($form_state['clicked_button']['#value'] == t('Save image')) {

      $validators = array(
        'file_validate_is_image' => array(),
      );

      $path = file_create_path('sweaver');
      file_check_directory($path, FILE_CREATE_DIRECTORY);
      $image = file_save_upload('image_image', $validators, file_directory_path() .'/sweaver');

      if ($image && !empty($form_state['values']['image_description'])) {
        $image->description = $form_state['values']['image_description'];
        $image_parts = explode('.', $image->filepath);
        $extension = array_pop($image_parts);
        $new_image_name = file_directory_path() .'/sweaver/sweaver_image_'. $image->fid .'.'. $extension;
        rename($image->filepath, $new_image_name);

        db_query("UPDATE {files} set filepath = '%s' WHERE fid = %d", $new_image_name, $image->fid);
        file_set_status($image, FILE_STATUS_PERMANENT);
        drupal_write_record('sweaver_image', $image);
        sweaver_session(t('Image @image has been uploaded.', array('@image' => t($image->description))));
      }
      else {

        // Reset error messages.
        $errors = form_get_errors();
        if (!empty($errors)) {
          // Reset messages error.
          unset($_SESSION['messages']['error']);
        }

        // Messages for Sweaver.
        if (empty($form_state['values']['image_description'])) {
          sweaver_session(t('You need to enter a description for the image.'));
        }
        if (!empty($errors)) {
          sweaver_session(t('The image is invalid. Only JPG, PNG and GIF images are allowed.'));
        }
        elseif (!$image) {
          sweaver_session(t('The image is empty.'));
        }
      }
    }
  }

  /**
   * Images handler.
   */
  public function sweaver_images_handler(&$images) {
    $imagecache_presets = array();
    if (variable_get('sweaver_plugin_images_imagecache', FALSE) && function_exists('imagecache_presets')) {
      $imagecache_presets = imagecache_presets();
    }

    $query = 'SELECT ti.fid, ti.description, f.filepath FROM {sweaver_image} ti
              INNER JOIN {files} f on f.fid = ti.fid order by description ASC';
    $result = db_query($query);
    while ($image = db_fetch_object($result)) {
      $images[$GLOBALS['base_url'] .'/'. $image->filepath] = $image->description;

      // Imagecache presets.
      foreach ($imagecache_presets as $preset_key => $preset) {
        $images[$GLOBALS['base_url'] .'/'. imagecache_create_url($preset['presetname'], $image->filepath)] = $image->description .' ('. $preset['presetname'] .')';
      }
    }
  }

  /**
   * Menu callback.
   */
  public function sweaver_menu_callback() {
    $form = array();

    $form['sweaver_plugin_images_tab'] = array(
      '#type' => 'checkbox',
      '#title' => t('Editor tab'),
      '#description' => t('Toggle this checkbox if you want to enable the images tab on the editor.'),
      '#default_value' => variable_get('sweaver_plugin_images_tab', TRUE),
    );

    // Use imagecache on images ?
    if (function_exists('imagecache_presets')) {
      $form['sweaver_plugin_images_imagecache'] = array(
        '#type' => 'checkbox',
        '#title' => t('Allow to see imagecached version of images'),
        '#description' => t('Toggle this checkbox if you want to create imagecached versions of the images uploaded by the Images plugin.'),
        '#default_value' => variable_get('sweaver_plugin_images_imagecache', FALSE),
      );
    }
    else {
      $form['imagecache_disabled'] = array(
        '#type' => 'markup',
        '#value' => '<p>'. t('If you enable the imagecache module, all images can be made available with all imagecache preset variants.') .'</p>',
      );
      $form['sweaver_plugin_images_imagecache'] = array(
        '#type' => 'value',
        '#value' => 0,
      );
    }

    $form['sweaver_plugin_handle_images'] = array(
      '#type' => 'hidden',
      '#value' => variable_get('sweaver_plugin_handle_images', 'sweaver_plugin_images'),
    );

    $form = system_settings_form($form);

    // Images list
    $rows = array();
    $output = '<p>'. l(t('Add new image'), 'admin/settings/sweaver/images/add') .'</p>';

    $query = 'SELECT ti.fid, ti.description, f.filepath FROM {sweaver_image} ti
              INNER JOIN {files} f on f.fid = ti.fid order by description ASC';
    $result = db_query($query);
    while ($image = db_fetch_object($result)) {
      $row = array();
      $row[] = check_plain($image->description);
      $operations = l(t('View'), file_create_url($image->filepath)) .' - ';
      $operations .= l(t('Edit'), 'admin/settings/sweaver/images/edit/'. $image->fid, array('alias' => TRUE)) .' - ';
      $operations .= l(t('Delete'), 'admin/settings/sweaver/images/delete/'. $image->fid, array('alias' => TRUE));
      $row[] = $operations;
      $rows[] = $row;
    }

    if (!empty($rows)) {

      // Output table.
      $header = array(
        t('Image'),
        t('Operations'),
      );

      $output .= theme('table', $header, $rows);
    }
    else {
      $output .= '<p>'. t('No images uploaded.') .'</p>';
    }

    $form['images_list'] = array(
      '#type' => 'markup',
      '#value' => $output,
    );

    return $form;
  }

  /**
   * Menu callback submit.
   */
  public function sweaver_menu_callback_submit($form, &$form_state) {
    variable_set('sweaver_plugin_images_imagecache', $form_state['values']['sweaver_plugin_images_imagecache']);
    variable_set('sweaver_plugin_images_tab', $form_state['values']['sweaver_plugin_images_tab']);
    variable_set('sweaver_plugin_handle_images', 'sweaver_plugin_images');
    drupal_set_message(t('The configuration options have been saved.'));
  }

  /**
   * Images form.
   */
  public function sweaver_images_backend_form() {
    $form = array();

    $description = '';
    $check_upload = TRUE;
    $image = $this->sweaver_get_image(arg(5));
    if ($image) {
      $check_upload = FALSE;
      $description = $image->description;
      $fid = $image->fid;
    }
    else {
      $fid = NULL;
    }

    $form['#attributes'] = array('enctype' => 'multipart/form-data');
    $form['#fid'] = $fid;
    $form['#check_upload'] = $check_upload;

    $form['image_form']['description'] = array(
      '#type' => 'textfield',
      '#title' => t('Description'),
      '#required' => TRUE,
      '#default_value' => $description,
      '#description' => t('Description of the image used in the select box for files.')
    );
    if (!$fid) {
      $form['image_form']['image'] = array(
        '#type' => 'file',
        '#title' => t('Image'),
        '#description' => t('Upload images which you can use as background images. Extensions are limited to jpg, jpeg, png and gif.<br />Note: there is no scaling on the images on upload.'),
      );
    }
    $form['image_form']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save image'),
    );

    return $form;
  }

  /**
   * Images validate.
   */
  public function sweaver_images_backend_form_validate($form, &$form_state) {
    $validators = array(
      'file_validate_is_image' => array(),
    );

    $path = file_create_path('sweaver');
    file_check_directory($path, FILE_CREATE_DIRECTORY);
    $image = file_save_upload('image', $validators, file_directory_path() .'/sweaver');
    if ($image) {
      $form_state['image'] = $image;
    }
    elseif ($form['#check_upload']) {
      form_set_error('image', t('Image is required'));
    }
  }

  /**
   * Images add submit.
   */
  public function sweaver_images_backend_form_submit(&$form, &$form_state) {
    $image = new stdClass;

    if (isset($form_state['image'])) {
      $image_uploaded = $form_state['image'];
      $image->fid = $image_uploaded->fid;
      $image_parts = explode('.', $image_uploaded->filepath);
      $extension = array_pop($image_parts);
      $new_image_name = file_directory_path() .'/sweaver/sweaver_image_'. $image->fid .'.'. $extension;
      rename($image_uploaded->filepath, $new_image_name);
      db_query("UPDATE {files} set filepath = '%s' WHERE fid = %d", $new_image_name, $image->fid);
      file_set_status($image_uploaded, FILE_STATUS_PERMANENT);
    }

    if (!isset($image->fid)) $image->fid = $form['#fid'];
    $update = (!$form['#check_upload']) ? array('fid') : array();
    $image->description = $form_state['values']['description'];
    drupal_write_record('sweaver_image', $image, $update);

    drupal_set_message(t('Image %description has been saved.', array('%description' => $image->description)));
    $form_state['redirect'] = 'admin/settings/sweaver/images';
  }

  /**
   * Image delete form.
   */
  public function sweaver_images_confirm_form_delete() {
    $image = $this->sweaver_get_image(arg(5));
    if ($image) {
      $form['#image'] = $image;
      return confirm_form($form, t('Are you sure you want to delete image %description?', array('%description' => $image->description)), 'admin/settings/sweaver/images');
    }
    else {
      drupal_set_message(t('Image not found'));
      drupal_goto('admin/settings/sweaver/images');
    }
  }

  /**
   * Image delete submit callback.
   */
  public function sweaver_images_confirm_form_delete_submit(&$form, &$form_state) {
    $image = $form['#image'];
    file_delete($image->filepath);
    db_query("DELETE FROM {files} where fid = %d", $image->fid);
    db_query("DELETE FROM {sweaver_image} where fid = %d", $image->fid);
    drupal_set_message(t('Image %description has been deleted.', array('%description' => $image->description)));
    $form_state['redirect'] = 'admin/settings/sweaver/images';
  }

  /**
   * Helper function to get image.
   *
   * @param $fid
   *   The file id.
   * @return
   *   False or image object.
   */
  public function sweaver_get_image($fid) {
    if (!empty($fid)) {
      $query = 'SELECT ti.fid, ti.description, f.filepath FROM {sweaver_image} ti
                INNER JOIN {files} f on f.fid = ti.fid WHERE f.fid = %d';
      $image = db_fetch_object(db_query($query, $fid));
      if ($image->fid) {
        return $image;
      }
    }
    return FALSE;
  }
}
