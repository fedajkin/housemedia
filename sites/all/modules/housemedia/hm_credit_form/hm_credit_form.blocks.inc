<?php

/**
 * Callback for hook_block_view()
 */
function _hm_credit_form_block($op = 'list', $delta = 0, $edit = array()) {
  switch ($op) {
    case 'list':
      $function = "_hm_credit_form_block_list";
      break;
    case 'view':
    case 'configure':
    case 'save':
      $function = "_hm_credit_form_{$delta}_block_{$op}";
      break;
  }
  
  if ($function && function_exists($function)) {
    return call_user_func($function, $edit); 
  }
}

/**
 * Declare a list of all the available blocks
 */
function _hm_credit_form_block_list() {
  $blocks = array();
  $blocks['request_link'] = array(
    'info' => t('Credit form request link'),
    'cache' => BLOCK_NO_CACHE,
  );
  $blocks['user_current'] = array(
    'info' => t('Current credit form'),
    'cache' => BLOCK_NO_CACHE,
  );
  return $blocks;
}

function _hm_credit_form_request_link_block_view() {
  global $user;
  
  $account = menu_get_object('user_uid_optional');
  $content = '';

  if (hm_credit_form_can_create_relationship($user, $account)) {
  
    $rtid = _hm_credit_form_rtid();
        
    $content = l(
      t('Request advisor'),
      "relationship/{$account->uid}/request/{$rtid}"
    );
  }
    
  return array(
    'subject' => '',
    'content' => $content
  );
}

function _hm_credit_form_user_current_block_view() {
  global $user;

  $content = '';

  $relationship = user_relationships_load(array(
    'requester_id' => $user->uid,
    'rtid' => _hm_credit_form_rtid(),
    'approved' => 1
  ));

  if (!empty($relationship)) {
    $relationship = array_shift($relationship);
    $advisor = user_load($relationship->requestee_id);

    $content .= '<div><label>'. t('Advisor') .':</label> '. l($advisor->name, 'user/'. $advisor->uid) .'</div>';
    $content .= '<div>'. l(t('Cancel the request'), 'user/'. $user->uid .'/relationships/'. $relationship->rid .'/remove') .'</div>';

    $sql = 'SELECT n.nid FROM {node} n INNER JOIN {content_type_credit_form} c ON n.vid = c.vid '
         . "WHERE n.type = 'credit_form' AND n.status = 1 AND n.sticky = 1 AND n.uid = %d "
         . 'AND c.field_credit_form_advisor_uid = %d ORDER BY nid DESC';

    $nid = db_result(db_query($sql, $relationship->requester_id, $relationship->requestee_id));     

    if ($node = node_load($nid)) {
      
      $content .= '<div><storng>'. t('Current credit form') .':</strong></div>'
                . '<div><label>'. t('Amount') .':</label> '. check_plain($node->field_credit_form_amount[0]['value']) .'</div>'
                . '<div><label>'. t('Status') .':</label> '. t('Unknown') .'</div>'
                . '<div>'. l(t('Show details'), 'node/'. $node->nid) .'</div>';
    }
  }

  return array(
    'subject' => t('Advisor'),
    'content' => $content
  );
}
