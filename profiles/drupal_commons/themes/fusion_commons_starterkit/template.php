<?php
// $Id: template.php 8349 2011-03-02 16:46:51Z sheena $

/**
 * Breadcrumb themeing
 */
function fusion_commons_starterkit_breadcrumb($breadcrumb) {
  if (!empty($breadcrumb)) {
    return '<div class="breadcrumb">'. implode(' > ', $breadcrumb) .'</div>';
  }
}

/**
 * Node preprocessing
 */
function fusion_commons_starterkit_preprocess_node(&$vars) {
  // Only build custom submitted information if it was first available
  // If it's not, that indicates that it's been turned off for this
  // node type
  if ($vars['submitted']) {
    // Load the node author
    $author = user_load($vars['node']->uid);
  
    // Author picture
    if (theme_get_setting('toggle_node_user_picture')) {
      $picture = $vars['picture'];
      unset($vars['picture']);
      $picture = ($author->uid && user_access('access user profiles')) ? l($picture, "user/{$author->uid}", array('html' => TRUE)) : $picture;
    }
    
    // Author information
    $authorinfo = '<span class="submitted-by">';
    $authorinfo .= t('Submitted by !name', array('!name' => theme('username', $author)));
    $authorinfo .= '</span>';
    
    // User points
    if ($author->uid && module_exists('userpoints')) {
      $points = userpoints_get_current_points($author->uid);
      $userpoints = '<span class="userpoints-value" title="' . t('!val user points', array('!val' => $points)) . '">';
      $userpoints .= "({$points})"; 
      $userpoints .= '</span>';
    }
    
    // User badges
    if ($author->uid && module_exists('user_badges')) {
      if (is_array($author->badges)) {
        foreach ($author->badges as $badge) {
          $badges[] = theme('user_badge', $badge, $author);
        }
      }
    
      if (!empty($badges)) {
        $userbadges = theme('user_badge_group', $badges);
      }
    }
    
    // Created time
    $createdtime = '<span class="submitted-on">';
    $createdtime .= format_date($vars['node']->created);
    $createdtime .= '</span>';
    
    $vars['submitted'] = $picture.$userbadges.$authorinfo.$userpoints.$createdtime;
  }
}

/**
 * Comment preprocessing
 */
function fusion_commons_starterkit_preprocess_comment(&$vars) {
  global $user;
  static $comment_odd = TRUE;                                                                             // Comment is odd or even

  // Build array of handy comment classes
  $comment_classes = array();
  $comment_classes[] = $comment_odd ? 'odd' : 'even';
  $comment_odd = !$comment_odd;
  $comment_classes[] = ($vars['comment']->status == COMMENT_NOT_PUBLISHED) ? 'comment-unpublished' : '';  // Comment is unpublished
  $comment_classes[] = ($vars['comment']->new) ? 'comment-new' : '';                                      // Comment is new
  $comment_classes[] = ($vars['comment']->uid == 0) ? 'comment-by-anon' : '';                             // Comment is by anonymous user
  $comment_classes[] = ($user->uid && $vars['comment']->uid == $user->uid) ? 'comment-mine' : '';         // Comment is by current user
  $node = node_load($vars['comment']->nid);                                                               // Comment is by node author
  $vars['author_comment'] = ($vars['comment']->uid == $node->uid) ? TRUE : FALSE;
  $comment_classes[] = ($vars['author_comment']) ? 'comment-by-author' : '';
  $comment_classes = array_filter($comment_classes);                                                      // Remove empty elements
  $vars['comment_classes'] = implode(' ', $comment_classes);                                              // Create class list separated by spaces

  // Date & author
  $ago =  t('!interval ago', array('!interval' => format_interval(time() - $vars['comment']->timestamp)));
  $submitted_by = '<span class="comment-name">' . theme('username', $vars['comment']) . '</span>';
  $submitted_by .= '<span class="comment-date">' . $ago . '</span>';     // Format date as small, medium, or large
  $vars['submitted'] = $submitted_by;
  
  // Picture
  if (theme_get_setting('toggle_comment_user_picture')) {
    if (!$vars['comment']->picture && (variable_get('user_picture_default', '') != '')) {
      $vars['comment']->picture = variable_get('user_picture_default', '');
    }
    if ($vars['comment']->picture) { 
      $picture = theme_imagecache('user_picture_meta', $vars['comment']->picture, $vars['comment']->name, $vars['comment']->name);
      if (user_access('access user profiles')) {
        $vars['comment']->picture = l($picture, "user/".$vars['comment']->uid, array('html' => TRUE));
      }
      else {
        $vars['comment']->picture = $picture; 
      }
    }
  }
  else {
    unset($vars['comment']); 
  }
}

/**
 * Profile preprocessing
 */
function fusion_commons_starterkit_preprocess_user_profile_item(&$vars) {
  // Separate userpoints value from the edit links
  if ($vars['title'] == 'Points') { 
    $userpoints = explode(' - ', $vars['value']);
    $vars['value'] = '<span class="points">' . $userpoints[0] . '</span><span class="edit-links">' . $userpoints[1] . '</span>';
    unset($vars['title']);
  }
}

/**
 * Implementation of theme_shoutbox_post()
 */
function fusion_commons_starterkit_shoutbox_post($shout, $links = array(), $alter_row_color=TRUE) {
  global $user;
  
  // Gather moderation links
  if ($links) {
    foreach ($links as $link) {
      $linkattributes = $link['linkattributes'];
      $link_html = '<img src="'. $link['img'] .'"  width="'. $link['img_width'] .'" height="'. $link['img_height'] .'" alt="'. $link['title'] .'" class="shoutbox-imglink"/>';
      $link_url = 'shout/'. $shout->shout_id .'/'. $link['action'];
      $img_links = l($link_html, $link_url, array('html' => TRUE, 'query' => array('destination' => drupal_get_path_alias($_GET['q'])))) . $img_links;
    }
  }
  
  // Generate user name with link
  $user_name = shoutbox_get_user_link($shout);

  // Generate title attribute
  $title = t('Posted !date at !time by !name', array('!date' => format_date($shout->created, 'custom', 'm/d/y'), '!time' => format_date($shout->created, 'custom', 'h:ia'), '!name' => $shout->nick));

  // Add to the shout classes
  $shout_classes = array();
  $shout_classes[] = 'shoutbox-msg';

  // Check for moderation
  if ($shout->moderate == 1) {
    $shout_classes[] = 'shoutbox-unpublished';
    $approval_message = '&nbsp;(' . t('This shout is waiting for approval by a moderator.') . ')';
  }
  
  // Check for specific user class
  $user_classes = array();
  $user_classes[] = 'shoutbox-user-name';
  if ($shout->uid == $user->uid) {
    $user_classes[] = 'shoutbox-current-user-name';
  }
  else if ($shout->uid == 0) {
    $user_classes[] = 'shoutbox-anonymous-user';  
  }
  
  // Load user image and format
  $author_picture ='';
  $shout_author =  user_load($shout->uid);
  if (!$shout_author->picture && variable_get('user_picture_default', '')) {
    $shout_author->picture = variable_get('user_picture_default', '');
  }
  if ($shout_author->picture) {
    $author_picture = theme_imagecache('user_picture_meta', $shout_author->picture, $shout_author->name, $shout_author->name);
  }
  
  // Time format
  $format = variable_get('shoutbox_time_format', 'ago');
  switch ($format) {
    case 'ago';
      $submitted =  t('!interval ago', array('!interval' => format_interval(time() - $shout->created)));
      break;
    case 'small':
    case 'medium':
    case 'large':
      $submitted = format_date($shout->created, $format);
      break;
  }
   
  // Build the post
  $post = '';
  $post .= '<div class="' . implode(' ', $shout_classes) . '" title="' . $title . '">';
  $post .= '<div class="shoutbox-admin-links">' . $img_links . '</div>';
  $post .= '<div class="shoutbox-post-info">' . $author_picture;
  $post .= '<span class="shoutbox-user-name ' . implode(' ', $user_classes) . '">'. $user_name . '</span>';
  $post .= '<span class="shoutbox-msg-time">' . $submitted . '</span>';
  $post .= '</div>';
  $post .= '<div class="shout-message">' . $shout->shout . $approval_message . '</div>';
  $post .= '</div>' . "\n";

  return $post;
}

function fusion_commons_starterkit_item_list($items = array(), $title = NULL, $type = 'ul', $attributes = NULL) {
  $output = '<div class="item-list">';
  if (isset($title)) {
    $output .= '<h3>'. $title .'</h3>';
  }

  if (!empty($items)) {
    $output .= "<$type". drupal_attributes($attributes) .'>';
    $num_items = count($items);
    $c = $num_items;
    foreach ($items as $i => $item) {
    $c--;
      $attributes = array();
      $children = array();
      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          elseif ($key == 'children') {
            $children = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
         $data = $item;
      }
      
      if (!is_numeric($i)) {
        if (count($children) > 0) {
          $data .= theme_item_list($children, NULL, $type, $attributes); // Render nested list
        }
        if ($c == $num_items - 1) {
          $attributes['class'] = empty($attributes['class']) ? 'first' : ($attributes['class'] .' first');
        }
        if ($c == 0) {
          $attributes['class'] = empty($attributes['class']) ? 'last' : ($attributes['class'] .' last');
        }
        
        $attributes['class'] .= ' ' . ($c % 2 ? 'even' : 'odd');
        $output .= '<li'. drupal_attributes($attributes) .'>'. $data ."</li>\n";
      } 
      else {
        if (count($children) > 0) {
          $data .= theme_item_list($children, NULL, $type, $attributes); // Render nested list
        }
        if ($i == 0) {
          $attributes['class'] = empty($attributes['class']) ? 'first' : ($attributes['class'] .' first');
        }
        if ($i == $num_items - 1) {
          $attributes['class'] = empty($attributes['class']) ? 'last' : ($attributes['class'] .' last');
        }
        
        $attributes['class'] .= ' ' . ($i % 2 ? 'even' : 'odd');
        $output .= '<li'. drupal_attributes($attributes) .'>'. $data ."</li>\n";
      }
    }
    
    $output .= "</$type>";
  }
  $output .= '</div>';
  return $output;
}

function fusion_commons_starterkit_preprocess_block($variables) {
  $variables['template_files'][] = 'block-'.$variables['block']->region.'-'.$variables['block']->module;
  $variables['template_files'][] = 'block-'.$variables['block']->region.'-'.$variables['block']->module.'-'.$variables['block']->delta;
}
