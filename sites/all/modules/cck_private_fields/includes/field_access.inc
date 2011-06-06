<?php
// $Id: field_access.inc,v 1.1.2.6 2009/11/11 20:19:22 markuspetrux Exp $

/**
 * @file
 * Implementation of hook_field_access() related code for CCK Private Fields.
 */

/**
 * Implementation of hook_field_access('view').
 *
 * hook_field_access() gets a $node argument from everywhere it is invoked
 * by content_access(), except when invoked from the 'access callback' option
 * of CCK fields integration in views. This invocation is used by views to
 * decide which field can really be included or removed from the view before
 * the query itself is executed, and it is impossible to guess a $node from
 * here. However, views will invoke content_access() again for each field
 * that is about to be rendered. This happens indirectly, as a result of
 * using content_format() in the render() method of the views field handlers
 * provided by CCK, and this time, this invocation of content_access() comes
 * with the $node that we need here.
 *
 * @see cck_private_fields_field_access()
 */
function _cck_private_fields_field_view_access($field, $account, $node) {
  // Ok, so if we don't have a $node, this means we have been invoked by
  // views when checking for field access to build the query, so we just
  // ignore these requests.
  if (!isset($node)) {
    return;
  }

  // Ignore the request if this field does not have privacy options enabled.
  if (cck_private_fields_get_content_field_privacy($field['field_name']) === FALSE) {
    return;
  }

  // If the caller has not supplied a particular user account, then check
  // for view permissions against current user.
  if (!isset($account)) {
    $account = $GLOBALS['user'];
  }

  // Clone the node to ensure our changes do not affect the caller's object.
  $cloned_node = drupal_clone($node);

  // Retrieve the uid of the node or node_revision if not supplied. This may
  // happend when the field is about to be rendered on a view.
  if (!isset($cloned_node->uid)) {
    if (!empty($cloned_node->vid)) {
      $cloned_node->uid = db_result(db_query('SELECT uid FROM {node_revisions} WHERE vid = %d', $cloned_node->vid));
    }
    elseif (!empty($cloned_node->nid)) {
      $cloned_node->uid = db_result(db_query('SELECT uid FROM {node} WHERE nid = %d', $cloned_node->nid));
    }
    else {
      // This is an incomplete node object that do not even have nid/vid
      // properties. Deny access to view the field for safety.
      return FALSE;
    }
    if (!is_numeric($cloned_node->uid)) {
      // Deny access if we have been unable to retrieve the uid (safety).
      return FALSE;
    }
  }

  // Grant access if the user account is the owner of the node.
  if ($cloned_node->uid == $account->uid) {
    return TRUE;
  }

  // Grant access if the user account has permission to
  // 'view private data for field' (this field).
  if (user_access(cck_private_fields_build_permission_name('view', $field['field_name']), $account)) {
    return TRUE;
  }

  // Get the privacy status of the field.
  $field_privacy_status = cck_private_fields_get_field_privacy_status($cloned_node->vid, $field['field_name']);

  if ($field_privacy_status == CCK_FIELDS_PRIVACY_STATUS_HIDDEN) {
    return FALSE;
  }
  elseif ($field_privacy_status == CCK_FIELDS_PRIVACY_STATUS_PRIVATE) {
    return cck_private_fields_invoke_view_access($field, $cloned_node, $account);
  }

  // Reached this point, field is public.
  return TRUE;
}
