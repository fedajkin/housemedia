README for og_reg_keys.module:

Compatible with Drupal 6.x. Requires the Organic Groups module.

This module is an add-on for the Organic Groups module, designed to restrict user
access to groups.  Group owners (creator/manager) will be able to give the
registration key to site members.  By using the registration key, site members
will be granted access to the group in question.

When creating a new group, the group creator will be prompted with an additional
form field to set a group registration key.  If the group registration key is set
it will effectively restrict access to the group.  By leaving the group registration
key field empty the additional functionality will be disabled.

The following rules will be followed when a user attempts to join a group via 
registration codes:

* open - subscription requests are accepted immediately (default)
* moderated - subscription via registration key bypasses moderation mechanisms (modified)
* invite only - subscription must be created by an administrator (default)
* closed - subscriptions are administered by and administrator registration key bypasses closure (modified)


All the settings may be controlled at the settings page at /admin/og/og-reg-keys.

---
written by Jeff Graham of FunnyMonkey
