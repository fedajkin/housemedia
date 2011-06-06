// $Id: README.txt,v 1.1.2.1 2009/03/06 09:37:20 marktheunissen Exp $

Slider module creates a scrollable jQuery node display effect called the "coda slider", which was made famous by the site:

http://www.panic.com/coda/

Each panel of the Slider is an individual node. You can have any node you like appear inside a slider.

Usage
---------------------

This module depends on CCK (Content Creation Kit). A "slider" is actually a node type of your choice with a nodereference field called "field_slider_content". So before you can start using Slider, you need to install CCK module and choose a node type that will have the "field_slider_content" field. Add the field as a nodereference type, with "Multiple values" ticked so that you can have multiple panels in your slider!

In the Slider settings (admin/settings/slider), you should see a list of all node types that have a "field_slider_content" field. You can use the checkboxes to choose which node types the Slider module will operate on. Also select whether the tabs should appear above or below the panels.

Now, create a new node of the type you've selected, and set the nodereference field to reference the nodes you would like to be shown in the slider. Any nodes can be inside slider panels!

Don't forget that in the CCK settings for the node type, you have to configure the nodereference field and select which nodes you will allow it to reference.

When displaying the slider node, the nodereference data is removed from the display and instead you will see the nodes presented as a coda slider.

If you need to change the width and height or any other properties of the slider, you can do so in your theme's CSS file (overriding the styles in this module's css/slider.css).

Ordering your slides
---------------------

To order your nodes, you'll need to create the list of nodes in Views. However, you'll have a LOT of nodes to choose from, so you'll need to find a way to filter out the nodes that are intended to be on your slider.

Create a new node type, a "Slider Panel", and make it just like a page. You'll need to add one CCK field, an integer field, that will be your "Panel Order".

Create a few pages of content with your "Slider Panel" node type. In the "Panel Order" field of each node, set a number to define the node's order in the slider. 1 will be first, 99 will be last.

Now, create a view:
Under Fields add Node ID and Node Title.
Under Sort Criteria add your CCK Panel Order (the integer field) and sort Ascending.
Under Filters add Node Type and select your Slider Panel Node Type.
Save the view & you're almost done.

Now, go and edit the Content Type of your Slider (the one that actually creates the slider). (It should be somewhere like admin/content/node-type/XXXX where XXXX is your node type). Right down the bottom, you'll see "Advanced - Nodes that can be referenced (View)", click and expand it, then select the view that you just created.

Finally, go and create a new node with the Node Type you just edited. You should be able to select the nodes from your view - and they'll be in order!

Credits
---------------------

This module was written by Mark Theunissen for Digital People Online, a London based Digital Agency that specialises in Drupal development.

It uses several jQuery plugins: scrollTo, localScroll, serialScroll.

The jQuery code in slider.js was created by Remy Sharp and is explained in detail on his blog at: http://jqueryfordesigners.com/coda-slider-effect/
