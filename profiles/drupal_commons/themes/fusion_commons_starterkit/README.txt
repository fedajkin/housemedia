Fusion - Starter Theme for Drupal Commons Sites

For basic sub-theming instructions, please refer to http://fusiondrupalthemes.com/support/theme-developers/subtheming-quickstart

If you need help building your Fusion sub-theme for Drupal Commons, you may have success finding help at http://fusiondrupalthemes.com/forum or http://commons.acquia.com/

There are a few small differences between creating a standard Fusion sub-theme and creating a Fusion sub-theme for Drupal Commons.  Your theme will be a direct sub-theme of Fusion Core, not a sub-theme of Acquia Commons.  Because of this, The Fusion Commons Starter theme re-creates some of the features found in the Acquia Commons theme that ships with the Drupal Commons distro.  Thus, the customizations you will need to make to Fusion Commons Starter will be mostly through CSS.

The extra steps not covered by the general Fusion sub-theming documentation are as follows.

//--Theme Functions Need to be Renamed--//

In addition to the steps necessary to create any other sub-theme of Fusion, you will also need to edit all functions found in the following files:

  template.php
  panels/twocol_30_70.inc
  panels/twocol_70_30.inc

Functions in these files need to be renamed to replace 'fusion_commons_starter' with the machine-readable name of your custom theme.  For example, if you theme were called "My Commons Theme" and your machine readable name were "my_commons_theme" then the function in panesl/twocol_30_70.inc: 

  function MYTHEME_twocol_30_70_panels_layouts() {

would be renamed to match:

  function my_commons_theme_twocol_30_70_panels_layouts() {
  

//--Additional CSS File--//

  fusion-commons-style.css

Since the Drupal Commons distro requires quite a bit of custom CSS to keep all the content in panels, views, tables, etc. organized, we have separated this CSS off into its own CSS file for your convenience.  If you ever upgrade the Drupal Commons distro, you will be able to easily replace this file with a copy from the newer version of Fusion Commons Starter, and gain the benefits of future updates to the distro without losing your own custom styling.  In order to keep this convenience, it is important to not include any custom modifications to the theme within this CSS file.  It is advisable to keep all custom styles within fusion-starter-style.css.