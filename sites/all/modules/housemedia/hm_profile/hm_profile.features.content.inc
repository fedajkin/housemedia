<?php

/**
 * Implementation of hook_content_default_fields().
 */
function hm_profile_content_default_fields() {
  $fields = array();

  // Exported field: field_dew_kierunkowy
  $fields['deweloper-field_dew_kierunkowy'] = array(
    'field_name' => 'field_dew_kierunkowy',
    'type_name' => 'deweloper',
    'display_settings' => array(
      'weight' => '45',
      'parent' => 'group_dew_telefony',
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
    'type' => 'number_integer',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '0-',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_dew_kierunkowy][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Numer kierunkowy',
      'weight' => '22',
      'description' => 'Wprowadź numer kierunkowy w postaci 2 cyfr bez 0. Np 71...',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_dew_kod
  $fields['deweloper-field_dew_kod'] = array(
    'field_name' => 'field_dew_kod',
    'type_name' => 'deweloper',
    'display_settings' => array(
      'weight' => '40',
      'parent' => 'group_dew_adres',
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_dew_kod][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Kod pocztowy',
      'weight' => '25',
      'description' => 'Kod pocztowy',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_dew_miejscowosc
  $fields['deweloper-field_dew_miejscowosc'] = array(
    'field_name' => 'field_dew_miejscowosc',
    'type_name' => 'deweloper',
    'display_settings' => array(
      'weight' => '41',
      'parent' => 'group_dew_adres',
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_dew_miejscowosc][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Miejscowość',
      'weight' => '24',
      'description' => 'Miejscowość',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_dew_nazwa
  $fields['deweloper-field_dew_nazwa'] = array(
    'field_name' => 'field_dew_nazwa',
    'type_name' => 'deweloper',
    'display_settings' => array(
      'weight' => '34',
      'parent' => 'group_dew_podst_dane',
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_dew_nazwa][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Nazwa dewelopera',
      'weight' => '7',
      'description' => 'Nazwa dewelopera',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_dew_nr_domu
  $fields['deweloper-field_dew_nr_domu'] = array(
    'field_name' => 'field_dew_nr_domu',
    'type_name' => 'deweloper',
    'display_settings' => array(
      'weight' => '39',
      'parent' => 'group_dew_adres',
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_dew_nr_domu][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Nr domu',
      'weight' => '23',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_dew_telefony
  $fields['deweloper-field_dew_telefony'] = array(
    'field_name' => 'field_dew_telefony',
    'type_name' => 'deweloper',
    'display_settings' => array(
      'weight' => '46',
      'parent' => 'group_dew_telefony',
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
    'multiple' => '5',
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
          '_error_element' => 'default_value_widget][field_dew_telefony][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Numery telefonów',
      'weight' => '23',
      'description' => 'Wprowadź numery telefonów',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_dew_ulica
  $fields['deweloper-field_dew_ulica'] = array(
    'field_name' => 'field_dew_ulica',
    'type_name' => 'deweloper',
    'display_settings' => array(
      'weight' => '38',
      'parent' => 'group_dew_adres',
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_dew_ulica][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Ulica',
      'weight' => '8',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_dor_firma
  $fields['doradca-field_dor_firma'] = array(
    'field_name' => 'field_dor_firma',
    'type_name' => 'doradca',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
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
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => 'b|Brak
AZ|AZ Finanse
Notus|Dom Kredytowy Notus
D24|Doradcy 24
Ex|Expander
GF|Gold Finance
Gegg|Goldenegg
ME|Money Expert
OF|Open Finance
WS|Wealth Solutions
PDK|Powszechny Dom Kredytowy
HB|Home Broker',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Firma doradztwa finansowego',
      'weight' => '37',
      'description' => 'Firma doradztwa kredytowego, w której pracuje dany doradca.',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_dor_imie
  $fields['doradca-field_dor_imie'] = array(
    'field_name' => 'field_dor_imie',
    'type_name' => 'doradca',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
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
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '35',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_dor_imie][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Imię',
      'weight' => '34',
      'description' => 'Imię doradcy kredytowego',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_dor_nazwisko
  $fields['doradca-field_dor_nazwisko'] = array(
    'field_name' => 'field_dor_nazwisko',
    'type_name' => 'doradca',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
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
    'required' => '1',
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
          '_error_element' => 'default_value_widget][field_dor_nazwisko][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Nazwisko',
      'weight' => '35',
      'description' => 'Nazwisko doradcy kredytowego',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_dor_telefon
  $fields['doradca-field_dor_telefon'] = array(
    'field_name' => 'field_dor_telefon',
    'type_name' => 'doradca',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
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
    'type' => 'pl_phone',
    'required' => '0',
    'multiple' => '0',
    'module' => 'phone',
    'active' => '1',
    'phone_country_code' => 0,
    'widget' => array(
      'size' => '20',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_dor_telefon][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Telefon',
      'weight' => '36',
      'description' => 'Numer telefonu.',
      'type' => 'phone_textfield',
      'module' => 'phone',
    ),
  );

  // Exported field: field_imie
  $fields['uzytkownik-field_imie'] = array(
    'field_name' => 'field_imie',
    'type_name' => 'uzytkownik',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
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
    'required' => '1',
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
          '_error_element' => 'default_value_widget][field_imie][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Imię',
      'weight' => '34',
      'description' => 'Wprowadź swoje imię.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_nazwisko
  $fields['uzytkownik-field_nazwisko'] = array(
    'field_name' => 'field_nazwisko',
    'type_name' => 'uzytkownik',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
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
    'required' => '1',
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
          '_error_element' => 'default_value_widget][field_nazwisko][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Nazwisko',
      'weight' => '35',
      'description' => 'Wprowadź swoje nazwisko. Pole domyślnie jest widoczne tylko dla Twoich znajomych. Ustawienia widoczności można edytować w profilu użytkownika.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_plec
  $fields['uzytkownik-field_plec'] = array(
    'field_name' => 'field_plec',
    'type_name' => 'uzytkownik',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
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
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => 'Kobieta
Mężczyzna',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Płeć',
      'weight' => '36',
      'description' => 'Wybierz swoją płeć.',
      'type' => 'optionwidgets_buttons',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_rok_urodzenia
  $fields['uzytkownik-field_rok_urodzenia'] = array(
    'field_name' => 'field_rok_urodzenia',
    'type_name' => 'uzytkownik',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
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
      'input_format' => 'j M Y - H:i:s',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-80:+0',
      'label_position' => 'above',
      'label' => 'Rok urodzenia',
      'weight' => '37',
      'description' => '',
      'type' => 'date_select',
      'module' => 'date',
    ),
  );

  // Exported field: field_status
  $fields['uzytkownik-field_status'] = array(
    'field_name' => 'field_status',
    'type_name' => 'uzytkownik',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
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
    'allowed_values' => 'kupic|Chcę kupić mieszkanie
sprzedac|Chcę sprzedać mieszkanie
wynajac|Chcę wynająć mieszkanie
najac|Chcę znaleźć najemcę
nabyte|Już kupiłem(-am)
brak|Rozglądam się',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => 'brak',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Status',
      'weight' => '36',
      'description' => 'Status użytkownika.',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_telefon
  $fields['uzytkownik-field_telefon'] = array(
    'field_name' => 'field_telefon',
    'type_name' => 'uzytkownik',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
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
    'type' => 'pl_phone',
    'required' => '0',
    'multiple' => '0',
    'module' => 'phone',
    'active' => '1',
    'phone_country_code' => 0,
    'widget' => array(
      'size' => '20',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_telefon][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Telefon',
      'weight' => '37',
      'description' => 'Numer telefonu.',
      'type' => 'phone_textfield',
      'module' => 'phone',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Firma doradztwa finansowego');
  t('Imię');
  t('Kod pocztowy');
  t('Miejscowość');
  t('Nazwa dewelopera');
  t('Nazwisko');
  t('Nr domu');
  t('Numer kierunkowy');
  t('Numery telefonów');
  t('Płeć');
  t('Rok urodzenia');
  t('Status');
  t('Telefon');
  t('Ulica');

  return $fields;
}
