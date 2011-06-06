/* $Id: README.txt,v 1.1.2.29 2010/11/04 09:39:36 swentel Exp $ */

-- SUMMARY --

The Sweaver module makes it possible to theme you website directly
on the front end.

For a full description of the module, visit the project page:
  http://drupal.org/project/sweaver
  
To submit bug reports and feature suggestions, or to track changes:
  http://drupal.org/project/issues/sweaver

-- REQUIRED --

CTools - http://drupal.org/project/ctools
jQuery UI - http://drupal.org/project/jquery_ui

Make sure you install jquery.ui 1.6 from
http://code.google.com/p/jquery-ui/downloads/list

-- PLUGINS --

1) Style
This plugin can't be disabled. This gives you the editor
on the front end which you can use to style your theme.
The plugin creates a few configuration screens where you
can configure the selectors, properties & types.

2) Custom CSS
Adds a tab on the front end to add custom CSS.

3) Manage styles
Save, load and delete styles directly from the front end.
The back end screen has a checkbox to load the active style for
the theme if the editor itself is disabled.

4) Images
Upload images in the editor or in the back end. With imagecache
enabled, the images are also available as their derivatives.

5) Switch theme
Switch themes on the front end. When saving a style, the current
selected theme will also be set as the default theme.

6) Theme settings
Save theme settings like logo, favicon and other theme settings.

7) Font face
You need the fontyourface module (http://drupal.org/project/fontyourface)
It will add the selected fonts in the font family dropdown.

8) Theme styles
This is a tricky plugin. Only enable it if you have classes defined
in your theme info file. The tab on the frontend will show you
the styles found on the page you're looking at.
The backend screen gives you the option to define groups in your
info file to look for classes.

9) Key bindings
Use the keyboard to popup save, load, publish, delete screens.

10) Palettes
Define color palettes from your theme info file. More info
is found in API.txt.

-- MAINTAINERS --

swentel - http://drupal.org/user/107403
jyve - http://drupal.org/user/591438
