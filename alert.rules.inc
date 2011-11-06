<?php
/**
 * @file
 * Rules integration for the Alert module.
 */

/**
 * Implements hook_rules_action_info().
 */
function alert_rules_action_info() {
  return array(
    'alert_save_action' => array(
      'label' => t('Set an alert'),
      'group' => t('Alert'),
      'named parameter' => TRUE,
      'parameter' => array(
        'uid' => array(
          'label' => t('User'),
          'description' => t('The user who should see the alert. (If left empty, the anonymous user will be used. This is not recommended.)'),
          'type' => 'user',
          'optional' => TRUE,
        ),
        'reference' => array(
          'label' => t('Reference'),
          'description' => t('An arbitrary string modules can use as a reference to alerts of this type, so as to retrieve it later.'),
          'type' => 'text',
          'optional' => TRUE,
        ),
        'type' => array(
          'label' => t('Type'),
          'description' => t('The message type to use with drupal_set_message(). (If left empty, "status" will be used.)'),
          'type' => 'text',
          'optional' => TRUE,
        ),
        'repeat' => array(
          'label' => t('Repeat'),
          'description' => t('Whether to display the same message multiple times if it is set multiple times. (If left empty, it will be set to FALSE.)'),
          'type' => 'boolean',
          'optional' => TRUE,
        ),
        'message' => array(
          'label' => t('Message'),
          'description' => t('The message to display to the user.'),
          'type' => 'text',
        ),
      ),
    ),
  );
}

/**
 * Action: Save a new alert.
 *
 * @param $vars
 *   An array with the following keys:
 *   - uid (optional): A user object of the user who should see the alert. (If
 *     left empty, the anonymous user will be used. This is not recommended.)
 *   - reference (optional): An arbitrary string modules can use as a reference
 *     to alerts of this type, so as to retrieve it later.
 *   - type (optional): The message type to use with drupal_set_message(). (If
 *     left empty, "status" will be used.)
 *   - repeat (optional): Whether to display the same message multiple times if
 *     it is set multiple times. (If left empty, it will be set to FALSE.)
 *   - message: The message to display to the user.
 */
function alert_save_action($vars) {
  // Don't set an alert if the user wasn't logged in.
  if (!is_object($vars['uid'])) {
    return;
  }
  $vars['uid'] = $vars['uid']->uid;
  unset($vars['settings'], $vars['state']);
  alert_save($vars);
}