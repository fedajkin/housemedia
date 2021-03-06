<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function hm_profile_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_dew_adres
  $groups['deweloper-group_dew_adres'] = array(
    'group_type' => 'standard',
    'type_name' => 'deweloper',
    'group_name' => 'group_dew_adres',
    'label' => 'Szczegóły adresu',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '20',
    'fields' => array(
      '0' => 'field_dew_nr_domu',
      '1' => 'field_dew_miejscowosc',
      '2' => 'field_dew_kod',
    ),
  );

  // Exported group: group_dew_podstawowe
  $groups['deweloper-group_dew_podstawowe'] = array(
    'group_type' => 'standard',
    'type_name' => 'deweloper',
    'group_name' => 'group_dew_podstawowe',
    'label' => 'Podstawowe informacje',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '19',
    'fields' => array(
      '0' => 'field_dew_nazwa',
      '1' => 'field_dew_ulica',
    ),
  );

  // Exported group: group_dew_tel
  $groups['deweloper-group_dew_tel'] = array(
    'group_type' => 'standard',
    'type_name' => 'deweloper',
    'group_name' => 'group_dew_tel',
    'label' => 'Telefony',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '21',
    'fields' => array(
      '0' => 'field_dew_kierunkowy',
      '1' => 'field_dew_telefony',
    ),
  );

  // Exported group: group_dor_dane
  $groups['doradca-group_dor_dane'] = array(
    'group_type' => 'standard',
    'type_name' => 'doradca',
    'group_name' => 'group_dor_dane',
    'label' => 'Podstawowe dane',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '33',
    'fields' => array(
      '0' => 'field_dor_imie',
      '1' => 'field_dor_nazwisko',
      '2' => 'field_dor_telefon',
      '3' => 'field_dor_firma',
    ),
  );

  // Exported group: group_dane_osobowe
  $groups['uzytkownik-group_dane_osobowe'] = array(
    'group_type' => 'standard',
    'type_name' => 'uzytkownik',
    'group_name' => 'group_dane_osobowe',
    'label' => 'Dane osobowe',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset_vertical_tab',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'label' => 'above',
      ),
    ),
    'weight' => '35',
    'fields' => array(
      '0' => 'field_imie',
      '1' => 'field_nazwisko',
      '2' => 'field_plec',
      '3' => 'field_telefon',
    ),
  );

  // Exported group: group_dodatkowe
  $groups['uzytkownik-group_dodatkowe'] = array(
    'group_type' => 'standard',
    'type_name' => 'uzytkownik',
    'group_name' => 'group_dodatkowe',
    'label' => 'Informacje dodatkowe',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'description' => '',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '39',
    'fields' => array(
      '0' => 'field_status',
      '1' => 'field_rok_urodzenia',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Dane osobowe');
  t('Informacje dodatkowe');
  t('Podstawowe dane');
  t('Podstawowe informacje');
  t('Szczegóły adresu');
  t('Telefony');

  return $groups;
}
