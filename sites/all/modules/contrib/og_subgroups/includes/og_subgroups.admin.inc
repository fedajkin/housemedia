<?php

/**
 * @file
 * Administrative page callbacks for the subgroups module.
 */

/**
 * Menu callback; displays the subgroups configuration page.
 */
function og_subgroups_settings() {
  $form['propagte_content'] = array(
    '#type' => 'fieldset',
    '#title' => t('Group posts propagation'),
    '#description' => t('Content can be propagated through the subgroups tree.'),
    '#collapsible' => TRUE,
  );
  $form['propagte_content']['og_subgroups_propagate_content'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content propagation'),
    '#description' => t('Set the propagation type for posts which are group posts.'),
    '#options' => array(
      'up' => t('Parents'),
      'down' => t('Children'),
      'side' => t('Siblings'),
    ),
    '#default_value' => variable_get('og_subgroups_propagate_content', array()),
  );
  $form['propagte_user'] = array(
    '#type' => 'fieldset',
    '#title' => t('User propagation'),
    '#description' => t('Group members and admins can be propagated through the subgroups tree.'),
    '#collapsible' => TRUE,
  );
  $form['propagte_user']['og_subgroups_propagate_members'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Subscribing Members'),
    '#description' => t('Set the propagation type for group members (non-admin).'),
    '#options' => array(
      'up' => t('Parents'),
      'down' => t('Children'),
      'side' => t('Siblings'),
    ),
    '#default_value' => variable_get('og_subgroups_propagate_members', array()),
  );
  $form['propagte_user']['og_subgroups_propagate_members_unsubscribe'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Unsubscribing Members'),
    '#description' => t('Set the propagation type for group members (non-admin).'),
    '#options' => array(
      'up' => t('Parents'),
      'down' => t('Children'),
      'side' => t('Siblings'),
    ),
    '#default_value' => variable_get('og_subgroups_propagate_members_unsubscribe', array()),
  );
  $form['propagte_user']['og_subgroups_propagate_demote'] = array(
    '#type' => 'checkboxes',
    '#title' => t('User demotion'),
    '#description' => t("Determine if a demotion action should occur along the subgroups.
      Demotion referes to removing admin and completely unsubscribing a member/ admin from a group."),
    '#options' => array(
      'remove_admin' => t('Removing admin rights (user still remains a member)'),
      'unsubscribe' => t('Unsubscribing or denying membership of a user'),

    ),
    '#default_value' => variable_get('og_subgroups_propagate_demote', array()),
  );

  return system_settings_form($form);
}