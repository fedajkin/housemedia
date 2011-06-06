/* $Id: README.txt,v 1.2.2.1 2010/04/02 14:42:51 b3n Exp $

-- SUMMARY --

Provides an autocomplete form element based on the jquery.autocomplete (http://bassistance.de/jquery-plugins/jquery-plugin-autocomplete/)

By default, the default Drupal autocomplete form elements will switch to using this plugin. This can be turned off in the modules admin settings: admin/settings/autocomplete_element   

  To submit bug reports and feature suggestions, or to track changes:

  http://drupal.org/project/issues/autocomplete_element


-- REQUIREMENTS --

jQuery 1.2.6+


-- INSTALLATION --

* Install as usual, see http://drupal.org/node/70151 for further information.

-- CONFIGURATION --

Has one admin setting (admin/settings/autocomplete_element) where you can toggle on / off using this plugin for all autocomplete form elements.  

-- USAGE --

You can create a new autocomplete form element with:

$form['autocomplete_element'] = array(
  '#type' => 'autocomplete',
  '#data' => array(),
  '#plugin_options' => array()
);

#data can be either an array or a URL to look up data. 

#options - an associative array of corresponding to the autocomplete plugin's options. 
See http://docs.jquery.com/Plugins/Autocomplete/autocomplete#url_or_dataoptions for more info.


-- CONTACT --

Current maintainers:
* Ben Scott (ben.scott) - http://drupal.org/user/149339
  Brighton Digital Ltd.

This project has been sponsored by:
* Comic Relief
