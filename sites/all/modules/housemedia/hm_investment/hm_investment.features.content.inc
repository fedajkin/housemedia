<?php

/**
 * Implementation of hook_content_default_fields().
 */
function hm_investment_content_default_fields() {
  $fields = array();

  // Exported field: field_in_d_cenagaraz
  $fields['inw_detal-field_in_d_cenagaraz'] = array(
    'field_name' => 'field_in_d_cenagaraz',
    'type_name' => 'inw_detal',
    'display_settings' => array(
      'weight' => '14',
      'parent' => 'group_in_d_mscpostojowe',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => 'zł',
    'min' => '0',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '0',
          '_error_element' => 'default_value_widget][field_in_d_cenagaraz][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Cena miejsca w garażu podziemnym',
      'weight' => '14',
      'description' => 'Cena za miejsce postojowe w garażu podziemnym.',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_in_d_cenazewmsc
  $fields['inw_detal-field_in_d_cenazewmsc'] = array(
    'field_name' => 'field_in_d_cenazewmsc',
    'type_name' => 'inw_detal',
    'display_settings' => array(
      'weight' => '15',
      'parent' => 'group_in_d_mscpostojowe',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => 'zł',
    'min' => '0',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '0',
          '_error_element' => 'default_value_widget][field_in_d_cenazewmsc][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Cena zewnętrznego miejsca postojowego',
      'weight' => '15',
      'description' => 'Cena zewnętrznego miejsca postojowego.',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_in_d_deweloper
  $fields['inw_detal-field_in_d_deweloper'] = array(
    'field_name' => 'field_in_d_deweloper',
    'type_name' => 'inw_detal',
    'display_settings' => array(
      'weight' => '32',
      'parent' => 'group_in_d_podstawowe',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => 0,
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'size' => '60',
      'autocomplete_match' => 'contains',
      'autocomplete_case' => '0',
      'i18n_flddata' => 0,
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_in_d_deweloper][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Deweloper',
      'weight' => '32',
      'description' => '',
      'type' => 'autocomplete_widgets_flddata',
      'module' => 'autocomplete_widgets',
    ),
  );

  // Exported field: field_in_d_dzielnica
  $fields['inw_detal-field_in_d_dzielnica'] = array(
    'field_name' => 'field_in_d_dzielnica',
    'type_name' => 'inw_detal',
    'display_settings' => array(
      'weight' => '35',
      'parent' => 'group_in_d_podstawowe',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_in_d_dzielnica][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Dzielnica',
      'weight' => '35',
      'description' => 'Dzielnica, w której realizowana jest inwestycja.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_in_d_end
  $fields['inw_detal-field_in_d_end'] = array(
    'field_name' => 'field_in_d_end',
    'type_name' => 'inw_detal',
    'display_settings' => array(
      'weight' => '40',
      'parent' => 'group_in_d_dodatkowe',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'date',
    'required' => '0',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
    ),
    'timezone_db' => '',
    'tz_handling' => 'none',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'd.m.Y',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-3:+5',
      'label_position' => 'above',
      'label' => 'Termin zakończenia',
      'weight' => '40',
      'description' => '',
      'type' => 'date_popup',
      'module' => 'date',
    ),
  );

  // Exported field: field_in_d_garaz
  $fields['inw_detal-field_in_d_garaz'] = array(
    'field_name' => 'field_in_d_garaz',
    'type_name' => 'inw_detal',
    'display_settings' => array(
      'weight' => '12',
      'parent' => 'group_in_d_mscpostojowe',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '0',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '0',
          '_error_element' => 'default_value_widget][field_in_d_garaz][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Ilość miejsc w garażu podziemnym',
      'weight' => '12',
      'description' => 'Ilość miejsc postojowych w garażu podziemnym.',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_in_d_ilmieszkan
  $fields['inw_detal-field_in_d_ilmieszkan'] = array(
    'field_name' => 'field_in_d_ilmieszkan',
    'type_name' => 'inw_detal',
    'display_settings' => array(
      'weight' => '7',
      'parent' => 'group_in_d_mieszkania',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '1',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '1',
          '_error_element' => 'default_value_widget][field_in_d_ilmieszkan][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Ilość mieszkań',
      'weight' => '7',
      'description' => 'Ilość mieszkań dostępnych w inwestycji.',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_in_d_kodpocztowy
  $fields['inw_detal-field_in_d_kodpocztowy'] = array(
    'field_name' => 'field_in_d_kodpocztowy',
    'type_name' => 'inw_detal',
    'display_settings' => array(
      'weight' => '36',
      'parent' => 'group_in_d_podstawowe',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_in_d_kodpocztowy][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Kod pocztowy',
      'weight' => '36',
      'description' => 'Kod pocztowy.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_in_d_maxmetr
  $fields['inw_detal-field_in_d_maxmetr'] = array(
    'field_name' => 'field_in_d_maxmetr',
    'type_name' => 'inw_detal',
    'display_settings' => array(
      'weight' => '9',
      'parent' => 'group_in_d_cenymetraze',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => 'zł',
    'min' => '1',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '1',
          '_error_element' => 'default_value_widget][field_in_d_maxmetr][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Maksymalna cena metra',
      'weight' => '9',
      'description' => 'Najwyższa cena metra w inwestycji.',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_in_d_maxmetraz
  $fields['inw_detal-field_in_d_maxmetraz'] = array(
    'field_name' => 'field_in_d_maxmetraz',
    'type_name' => 'inw_detal',
    'display_settings' => array(
      'weight' => '11',
      'parent' => 'group_in_d_cenymetraze',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_float',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => 'm²',
    'min' => '1',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '1',
          '_error_element' => 'default_value_widget][field_in_d_maxmetraz][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Największy metraż',
      'weight' => '11',
      'description' => 'Największy dostępny metraż w inwestycji.',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_in_d_miasto
  $fields['inw_detal-field_in_d_miasto'] = array(
    'field_name' => 'field_in_d_miasto',
    'type_name' => 'inw_detal',
    'display_settings' => array(
      'weight' => '34',
      'parent' => 'group_in_d_podstawowe',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => 0,
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_in_d_miasto][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'autocomplete_match' => 'contains',
      'autocomplete_case' => '0',
      'i18n_flddata' => 0,
      'label' => 'Miasto',
      'weight' => '34',
      'description' => 'Miasto, w którym realizowana jest inwestycja.',
      'type' => 'autocomplete_widgets_flddata',
      'module' => 'autocomplete_widgets',
    ),
  );

  // Exported field: field_in_d_minmetr
  $fields['inw_detal-field_in_d_minmetr'] = array(
    'field_name' => 'field_in_d_minmetr',
    'type_name' => 'inw_detal',
    'display_settings' => array(
      'weight' => '8',
      'parent' => 'group_in_d_cenymetraze',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => 'zł',
    'min' => '1',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '1',
          '_error_element' => 'default_value_widget][field_in_d_minmetr][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Minimalna cena metra',
      'weight' => '8',
      'description' => 'Najniższa cena metra w danej inwestycji.',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_in_d_minmetraz
  $fields['inw_detal-field_in_d_minmetraz'] = array(
    'field_name' => 'field_in_d_minmetraz',
    'type_name' => 'inw_detal',
    'display_settings' => array(
      'weight' => '10',
      'parent' => 'group_in_d_cenymetraze',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_float',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => 'm²',
    'min' => '1',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '1',
          '_error_element' => 'default_value_widget][field_in_d_minmetraz][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Najmniejszy metraż',
      'weight' => '10',
      'description' => 'Najmniejszy dostępny metraż mieszkań w inwestycji.',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_in_d_nazwa
  $fields['inw_detal-field_in_d_nazwa'] = array(
    'field_name' => 'field_in_d_nazwa',
    'type_name' => 'inw_detal',
    'display_settings' => array(
      'weight' => '31',
      'parent' => 'group_in_d_podstawowe',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => 0,
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_in_d_nazwa][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'autocomplete_match' => 'contains',
      'autocomplete_case' => '0',
      'i18n_flddata' => 0,
      'label' => 'Nazwa inwestycji',
      'weight' => '31',
      'description' => 'Pełna dodatkowa nazwa inwestycji',
      'type' => 'autocomplete_widgets_flddata',
      'module' => 'autocomplete_widgets',
    ),
  );

  // Exported field: field_in_d_nrdomu
  $fields['inw_detal-field_in_d_nrdomu'] = array(
    'field_name' => 'field_in_d_nrdomu',
    'type_name' => 'inw_detal',
    'display_settings' => array(
      'weight' => '38',
      'parent' => 'group_in_d_podstawowe',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_in_d_nrdomu][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Numer domu',
      'weight' => '38',
      'description' => 'Nr domu',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_in_d_pietra
  $fields['inw_detal-field_in_d_pietra'] = array(
    'field_name' => 'field_in_d_pietra',
    'type_name' => 'inw_detal',
    'display_settings' => array(
      'weight' => '38',
      'parent' => 'group_in_d_dodatkowe',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '0',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '0',
          '_error_element' => 'default_value_widget][field_in_d_pietra][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Ilość pięter',
      'weight' => '38',
      'description' => 'Ilość pięter w inwestycji',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_in_d_postzew
  $fields['inw_detal-field_in_d_postzew'] = array(
    'field_name' => 'field_in_d_postzew',
    'type_name' => 'inw_detal',
    'display_settings' => array(
      'weight' => '13',
      'parent' => 'group_in_d_mscpostojowe',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '0',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '0',
          '_error_element' => 'default_value_widget][field_in_d_postzew][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Ilość zewnętrznych miejsc postojowych',
      'weight' => '13',
      'description' => 'Ilość zewnętrznych miejsc postojowych.',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_in_d_rodzaj
  $fields['inw_detal-field_in_d_rodzaj'] = array(
    'field_name' => 'field_in_d_rodzaj',
    'type_name' => 'inw_detal',
    'display_settings' => array(
      'weight' => '43',
      'parent' => 'group_in_d_dodatkowe',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => 'm|Mieszkania
d|Domy
b|Bliźniaki
s|Szeregówki',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => 'm',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Rodzaj inwestycji',
      'weight' => '43',
      'description' => 'Rodzaj inwestycji.',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_in_d_sprzedane
  $fields['inw_detal-field_in_d_sprzedane'] = array(
    'field_name' => 'field_in_d_sprzedane',
    'type_name' => 'inw_detal',
    'display_settings' => array(
      'weight' => '8',
      'parent' => 'group_in_d_mieszkania',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '0',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '0',
          '_error_element' => 'default_value_widget][field_in_d_sprzedane][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Mieszkania sprzedane',
      'weight' => '8',
      'description' => 'Ilość sprzedanych mieszkań.',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_in_d_stan
  $fields['inw_detal-field_in_d_stan'] = array(
    'field_name' => 'field_in_d_stan',
    'type_name' => 'inw_detal',
    'display_settings' => array(
      'weight' => '41',
      'parent' => 'group_in_d_dodatkowe',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '%',
    'min' => '0',
    'max' => '100',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '0',
          '_error_element' => 'default_value_widget][field_in_d_stan][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Stan realizacji',
      'weight' => '41',
      'description' => 'Stan realizacji inwestycji w %.',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_in_d_start
  $fields['inw_detal-field_in_d_start'] = array(
    'field_name' => 'field_in_d_start',
    'type_name' => 'inw_detal',
    'display_settings' => array(
      'weight' => '39',
      'parent' => 'group_in_d_dodatkowe',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'date',
    'required' => '0',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
    ),
    'timezone_db' => '',
    'tz_handling' => 'none',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'd.m.Y',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-5:+3',
      'label_position' => 'above',
      'label' => 'Termin rozpoczęcia',
      'weight' => '39',
      'description' => '',
      'type' => 'date_popup',
      'module' => 'date',
    ),
  );

  // Exported field: field_in_d_ulica
  $fields['inw_detal-field_in_d_ulica'] = array(
    'field_name' => 'field_in_d_ulica',
    'type_name' => 'inw_detal',
    'display_settings' => array(
      'weight' => '37',
      'parent' => 'group_in_d_podstawowe',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '3',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_in_d_ulica][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Ulica',
      'weight' => '37',
      'description' => 'Ulica(e), przy której(ych) realizowana jest inwestycja.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_in_d_uwagi
  $fields['inw_detal-field_in_d_uwagi'] = array(
    'field_name' => 'field_in_d_uwagi',
    'type_name' => 'inw_detal',
    'display_settings' => array(
      'weight' => '12',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_in_d_uwagi][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Uwagi',
      'weight' => '12',
      'description' => 'Uwagi odnośnie inwestycji.',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_in_d_wojewodztwo
  $fields['inw_detal-field_in_d_wojewodztwo'] = array(
    'field_name' => 'field_in_d_wojewodztwo',
    'type_name' => 'inw_detal',
    'display_settings' => array(
      'weight' => '33',
      'parent' => 'group_in_d_podstawowe',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => 'dl|dolnośląskie
kp|kujawsko-pomorskie
lb|lubelskie
lu|lubuskie
ld|łódzkie
mp|małopolskie
mz|mazowieckie
op|opolskie
pk|podkarpackie
pd|podlaskie
pm|pomorskie
sl|śląskie
sw|świętokrzyskie
wm|warmińsko-mazurskie
wk|wielkopolskie
zp|zachodniopomorskie',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'autocomplete_match' => 'contains',
      'autocomplete_case' => '1',
      'i18n_flddata' => 0,
      'label' => 'Województwo',
      'weight' => '33',
      'description' => 'Województwo, w którym realizowana jest inwestycja.',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_in_d_wolne
  $fields['inw_detal-field_in_d_wolne'] = array(
    'field_name' => 'field_in_d_wolne',
    'type_name' => 'inw_detal',
    'display_settings' => array(
      'weight' => '10',
      'parent' => 'group_in_d_mieszkania',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'computed',
    'required' => '0',
    'multiple' => '0',
    'module' => 'computed_field',
    'active' => '1',
    'code' => '$node_field[0][\'value\'] = $node->field_in_d_ilmieszkan[0][\'value\'] - ($node->field_in_d_sprzedane[0][\'value\'] + $node->field_in_d_zarezerwowane[0][\'value\']);',
    'display_format' => '$display = $node_field_item[\'value\'];',
    'store' => 1,
    'data_type' => 'int',
    'data_length' => '10',
    'data_size' => 'normal',
    'data_precision' => '10',
    'data_scale' => '2',
    'data_not_NULL' => 0,
    'data_default' => '',
    'data_sortable' => 1,
    'widget' => array(
      'default_value' => NULL,
      'default_value_php' => NULL,
      'label' => 'Mieszkania wolne',
      'weight' => '10',
      'description' => 'Ilość wolnych mieszkań.',
      'type' => 'computed',
      'module' => 'computed_field',
    ),
  );

  // Exported field: field_in_d_wykonczenie
  $fields['inw_detal-field_in_d_wykonczenie'] = array(
    'field_name' => 'field_in_d_wykonczenie',
    'type_name' => 'inw_detal',
    'display_settings' => array(
      'weight' => '42',
      'parent' => 'group_in_d_dodatkowe',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => 'dew|Deweloperski
pk|Pod klucz
pd|Podwyższony deweloperski',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '5',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => 'dew',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Standard wykończenia',
      'weight' => '42',
      'description' => 'Standard wykończenia mieszkań.',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_in_d_zarezerwowane
  $fields['inw_detal-field_in_d_zarezerwowane'] = array(
    'field_name' => 'field_in_d_zarezerwowane',
    'type_name' => 'inw_detal',
    'display_settings' => array(
      'weight' => '9',
      'parent' => 'group_in_d_mieszkania',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_integer',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '0',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '0',
          '_error_element' => 'default_value_widget][field_in_d_zarezerwowane][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Mieszkania zarezerwowane',
      'weight' => '9',
      'description' => 'Ilość mieszkań zarezerwowanych.',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Cena miejsca w garażu podziemnym');
  t('Cena zewnętrznego miejsca postojowego');
  t('Deweloper');
  t('Dzielnica');
  t('Ilość miejsc w garażu podziemnym');
  t('Ilość mieszkań');
  t('Ilość pięter');
  t('Ilość zewnętrznych miejsc postojowych');
  t('Kod pocztowy');
  t('Maksymalna cena metra');
  t('Miasto');
  t('Mieszkania sprzedane');
  t('Mieszkania wolne');
  t('Mieszkania zarezerwowane');
  t('Minimalna cena metra');
  t('Najmniejszy metraż');
  t('Największy metraż');
  t('Nazwa inwestycji');
  t('Numer domu');
  t('Rodzaj inwestycji');
  t('Stan realizacji');
  t('Standard wykończenia');
  t('Termin rozpoczęcia');
  t('Termin zakończenia');
  t('Ulica');
  t('Uwagi');
  t('Województwo');

  return $fields;
}
