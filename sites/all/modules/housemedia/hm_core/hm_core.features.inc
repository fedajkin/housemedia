<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function hm_core_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function hm_core_imagecache_default_presets() {
  $items = array(
    'Wyszukiwanie_nieruchomosci_64x46' => array(
      'presetname' => 'Wyszukiwanie_nieruchomosci_64x46',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '64px',
            'height' => '46px',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'crop_102x73' => array(
      'presetname' => 'crop_102x73',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '102',
            'height' => '73',
          ),
        ),
      ),
    ),
    'crop_140x100' => array(
      'presetname' => 'crop_140x100',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '140',
            'height' => '100',
          ),
        ),
      ),
    ),
    'crop_40x40' => array(
      'presetname' => 'crop_40x40',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '40',
            'height' => '40',
          ),
        ),
      ),
    ),
    'image_thumb_30' => array(
      'presetname' => 'image_thumb_30',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '30px',
            'height' => '30px',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'scale_150x' => array(
      'presetname' => 'scale_150x',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '150',
            'height' => '',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'showcase_original' => array(
      'presetname' => 'showcase_original',
      'actions' => array(),
    ),
    'showcase_scale' => array(
      'presetname' => 'showcase_scale',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '60%',
            'height' => '60%',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}
