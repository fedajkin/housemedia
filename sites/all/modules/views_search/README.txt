
Views Search for Drupal 6.x
---------------------------
The Views Search module transforms views with exposed filters into search
form / search results pages. This module is useful for sites that require 
custom search forms with the look and feel of a traditional search.

Exposed filters in the Views module work like true filters, where a list of 
nodes is limited down to the intended results using a combination of several 
filters. In contrast to this approach, a more traditional search form allows 
users to define all criteria first (before seeing any results) and then click 
on a "Search" button to see the results. This module allows site administrators 
to easily use the behavior of a traditional search for selected views.

Here's an overview of the feature set:
- Separates the search form and results: selected views show a search form without 
  showing the results on the first page and the search results without showing the 
  search form/filters on the following pages
- Allows users to start over with a search (using a button on search results page)
- Allows users to modify the search criteria (using a button on the search results 
  page that expands search criteria using jQuery)
- Allows users to save a set of search criteria for later usage (only Non-Ajax views)
- Allows users to modify/overwrite the name and search criteria for a saved search
- Provides a default view that allows the current user to manage saved searches
- Provides a block showing a drop-down with saved searches for the current user
- Enables site administrators to select views that should act like "search views"
- Enables site administrators to limit the number of saved searches for certain user 
  roles & set saved search limits per rule
- Enables site administrators to batch-delete all saved searches for a specific view

Views Search was primarily created for page views (i.e. views that are displayed on
a page only, not in a block). See "Views Search Block Usage" further below for
setup instructions.


Installation
------------
To install the Views Search module, copy it to the modules directory of your site and 
visit the Module administration page ('admin/build/modules') to enable it.



Views Search Block Usage
------------------------
A number of users want to show a "search block" instead of a "search page".
To accomplish this, follow these instructions:
Instead of setting up a view with a block display, create a view with a page display. 
Setup all exposed filters that should be available to users. Under "Basic settings", 
set "Exposed form in block" to "Yes" (this is set to "no" by default). After you've
saved your view, go to the blocks configuration page. Views created a block that
will show all exposed filters. Place that block into a region of your choice. When
you execute the search this way, please note that the "search results" still show
up in the content section of a new page, not the block itself.



Views Search Setup / Administration
-----------------------------------
The Views Search module provides its own administration page at 'admin/settings/views_search'. 
On this page, site administrators can:
- Select the views that should be converted into search views (only views with at least 
  one exposed filter can be used)
- Set limits for saved searches per user role (each role needs to have the "save views search" 
  permission first)
- Delete all saved searches for a specific view



Hooks
-----
The Views Search module provides several hooks:
                                
- hook_views_search_pre_view($view)
  This hook gets executed for all "search views" at the beginning of any views processing. 
  If another module returns   "array('prevent_execution' => TRUE)", it invalidates the 
  execution of this view, i.e.: If another module implements this hook and returns 
  "array('prevent_execution' => TRUE)", the results of the view will not be displayed.
  Example for the implementation of this hook: Let's assume only certain roles have the 
  permissions to save a search. If a user loses that permission, he/she would still be 
  able to execute previously saved searches. This hook allows other modules to prevent this.

- hook_views_search_pre_render($view)
  This hook gets executed for all "search views" on the search results page, i.e. on the 
  page that actually shows   the list of nodes for a search view. Other modules can use 
  the full $view object.

- hook_views_search_content($op)
  $op = 'saved_search_limit' => If a user has reached his saved search limit, Views Search 
                                displays default text to indicate that the user has reached 
                                his limit. Other modules can react on this hook and return 
                                content that can be displayed instead of the default text.
  
- hook_views_search_block_empty_text($op)
  $op = 'views_search_ss_dd' => Allows other modules to define a custom empty text for the 
                                Saved Search block in the case that the current user has no 
                                saved searches. If there is no custom empty text set in the 
                                block administration or no custom module implements this hook, 
                                the block will be hidden if the user has no saved searches.



Maintainers
-----------
haagendazs (Daniel Hanold, danny@danielhanold.com)