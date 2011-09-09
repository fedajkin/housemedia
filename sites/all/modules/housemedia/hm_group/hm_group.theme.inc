<?php 

/**
 * Theme handler for the group members and managers block
 */
function theme_hm_group_members_block($managers, $residents, $guests, $link) {
  $content = '';
  if ($managers) {
    $content .= '<div class="group-managers-label">' . t('Moderators:') . '</div>';
    $content .= '<div class="group-managers">' . $managers . '</div>';
  }
  if ($residents) {
    $content .= '<div class="group-members-label">' . t('Residents:') . '</div>';
    $content .= '<div class="group-members">' . $residents . '</div>';
  }
  if ($guests) {
    $content .= '<div class="group-members-label">' . t('Guests:') . '</div>';
    $content .= '<div class="group-members">' . $guests . '</div>';
  }
  if ($link) {
    $content .= '<div class="group-members-link">' . $link . '</div>';
  }
  return $content;
}