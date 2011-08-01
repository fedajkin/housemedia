<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function hm_investment_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_in_d_cenymetraze
  $groups['inw_detal-group_in_d_cenymetraze'] = array(
    'group_type' => 'standard',
    'type_name' => 'inw_detal',
    'group_name' => 'group_in_d_cenymetraze',
    'label' => 'Ceny i metraże',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '10',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'description' => '',
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
    'weight' => '10',
    'fields' => array(
      '0' => 'field_in_d_minmetr',
      '1' => 'field_in_d_maxmetr',
      '2' => 'field_in_d_minmetraz',
      '3' => 'field_in_d_maxmetraz',
    ),
  );

  // Exported group: group_in_d_dodatkowe
  $groups['inw_detal-group_in_d_dodatkowe'] = array(
    'group_type' => 'standard',
    'type_name' => 'inw_detal',
    'group_name' => 'group_in_d_dodatkowe',
    'label' => 'Informacje dodatkowe',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '8',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'description' => '',
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
    'weight' => '8',
    'fields' => array(
      '0' => 'field_in_d_pietra',
      '1' => 'field_in_d_start',
      '2' => 'field_in_d_end',
      '3' => 'field_in_d_stan',
      '4' => 'field_in_d_wykonczenie',
      '5' => 'field_in_d_rodzaj',
    ),
  );

  // Exported group: group_in_d_mieszkania
  $groups['inw_detal-group_in_d_mieszkania'] = array(
    'group_type' => 'standard',
    'type_name' => 'inw_detal',
    'group_name' => 'group_in_d_mieszkania',
    'label' => 'Stan mieszkań',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '9',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'description' => '',
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
    'weight' => '9',
    'fields' => array(
      '0' => 'field_in_d_ilmieszkan',
      '1' => 'field_in_d_sprzedane',
      '2' => 'field_in_d_zarezerwowane',
      '3' => 'field_in_d_wolne',
    ),
  );

  // Exported group: group_in_d_mscpostojowe
  $groups['inw_detal-group_in_d_mscpostojowe'] = array(
    'group_type' => 'standard',
    'type_name' => 'inw_detal',
    'group_name' => 'group_in_d_mscpostojowe',
    'label' => 'Miejsca postojowe',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '11',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'description' => '',
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
    'weight' => '11',
    'fields' => array(
      '0' => 'field_in_d_garaz',
      '1' => 'field_in_d_postzew',
      '2' => 'field_in_d_cenagaraz',
      '3' => 'field_in_d_cenazewmsc',
    ),
  );

  // Exported group: group_in_d_podstawowe
  $groups['inw_detal-group_in_d_podstawowe'] = array(
    'group_type' => 'standard',
    'type_name' => 'inw_detal',
    'group_name' => 'group_in_d_podstawowe',
    'label' => 'Dane podstawowe',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '7',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'description' => '',
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
    'weight' => '7',
    'fields' => array(
      '0' => 'field_in_d_nazwa',
      '1' => 'field_in_d_deweloper',
      '2' => 'field_in_d_wojewodztwo',
      '3' => 'field_in_d_miasto',
      '4' => 'field_in_d_dzielnica',
      '5' => 'field_in_d_kodpocztowy',
      '6' => 'field_in_d_ulica',
      '7' => 'field_in_d_nrdomu',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Ceny i metraże');
  t('Dane podstawowe');
  t('Informacje dodatkowe');
  t('Miejsca postojowe');
  t('Stan mieszkań');

  return $groups;
}
