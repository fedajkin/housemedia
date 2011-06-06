;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; CCK Private Fields
;; $Id: README.txt,v 1.1.2.10 2009/08/05 19:04:21 markuspetrux Exp $
;;
;; Module Author   : markus_petrux (http://drupal.org/user/39593)
;; Module co-author: pcambra       (http://drupal.org/user/122101)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

CONTENTS OF THIS FILE
=====================
- OVERVIEW
- REQUIREMENTS
- INSTALLATION
- DESCRIPTION
- DEVELOPMENT / API
- CREDITS


OVERVIEW
========

This module allows users to mark administrator selected CCK fields as Public
(visible to everyone), Hidden (visible to node author, hidden from everyone
else) or Private (visible to node author and "friends"; see requirements
section below).


REQUIREMENTS
============

- Content Construction Kit (CCK).
  http://drupal.org/project/cck

  Note: CCK version 2.5 or higher is required.
  See: http://drupal.org/node/514452

- To enable the "Private" status for fields, you need one of the following
  modules:

  * Flag Friend
    http://drupal.org/project/flag_friend

  * Friendlist API
    http://drupal.org/project/friendlist

  * User Relationships
    http://drupal.org/project/user_relationships

  The CCK Private Fields module includes ready to install mini-modules that
  provide builtin support for any of these friendship related modules.

- jQuery UI (either version 1.6.x or 1.7.x).
  http://drupal.org/project/jquery_ui


INSTALLATION
============

- Be sure to install all dependent modules.

- Copy all contents of this package to your modules directory preserving
  subdirectory structure.

- Go to Administer -> Site building -> Modules to install the CCK Private
  Fields module.

- To enable "Private" status for CCK fields, you should also install the
  module that integrates with the friendship related module in use in your
  site.


DESCRIPTION
===========

- The field settings screen provides a new option to enable privacy options
  for fields. This option is global and affects all content types where the
  given field is shared. The default privacy status can be specified.

- This module supports all kind of fields, and even fields in multigroups.
  http://drupal.org/node/494100

- In the node edit form, a new option to configure field privacy settings will
  be available as a small icon next to the fields where this feature has been
  enabled. This is only available to users with "edit privacy options for field
  %field_name" permission.

- Users with "view private data for field %field_name" permission are excluded
  from privacy restrictions. This feature combined with node revisions allows
  community managers and/or site moderators to monitor changes to privacy
  settings.

- Builtin support for node revisions and Diff module.
  http://drupal.org/project/diff


DEVELOPMENT / API
=================

You can create your own module to provide view access control to CCK Fields
with "Private" status. See the modules subdirectory for examples. The CCK
Private Fields module already provides integration with several friendship
related modules.

If you want to create your own, then you need to create 3 files minimum:

- your_module.info

  Format is standard for Drupal .info files. Just be sure to include the
  following line:

  dependencies[] = cck_private_fields


- your_module.install

  Here you should implement the following Drupal hooks minimum:

  - hook_requirements('install')

    Example:

    @code
    function your_module_requirements($phase) {
      if ($phase == 'install') {
        // Check installation requirements for this module.
        drupal_load('module', 'cck_private_fields');
        return cck_private_fields_check_install_requirements('your_module');
      }
    }
    @endcode

    Description:

    This is used to ensure only one "Private status provider" is enabled. This
    method allows the CCK Private Fields module to invoke your implementation
    of hook_cck_private_fields_view_access() quickly. Better performance than
    using module_invoke_all().


  - hook_enable()

    Example:

    @code
    function your_module_enable() {
      // Notify the CCK Private Fields module this one has been enabled.
      drupal_load('module', 'cck_private_fields');
      cck_private_fields_notify('enable', 'your_module');
    }
    @endcode

    Description:

    This is used to notify the CCK Private Fields module that your module
    is a "Private status provider", and then it will invoke your code when
    view access check is required for a particular CCK Field.


  - hook_disable()

    Example:

    @code
    function your_module_disable() {
      // Notify the CCK Private Fields module this one has been disabled.
      drupal_load('module', 'cck_private_fields');
      cck_private_fields_notify('disable', 'your_module');
    }
    @endcode

    Description:

    This is used to notify the CCK Private Fields module that your module
    is now disabled.


- your_module.module

  Here you should implement the following Drupal hook minimum:

  - hook_cck_private_fields_view_access($field, $node, $account)

    where:

      @param $field
        The cck field which is about to be checked.
      @param $node
        The node where this field is located.
      @param $account
        The user account to check (the requester).

    Example:

    @code
    function your_module_cck_private_fields_view_access($field, $node, $account) {
      if ( /* condition to check if access to view this field is allowed. */ ) {
        return TRUE;
      }
      // Otherwise, deny view access for privacy reasons.
      return FALSE;
    }
    @endcode


CREDITS
=======

- Original versions of the privacy icons can be found free from here:

  http://www.famfamfam.com/
