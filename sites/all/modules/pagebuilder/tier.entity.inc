<?php

/**
 * @file
 * Specific form handlers for Tier entity.
 */

/**
 * Generates the Tier type editing form.
 */
function tier_type_form($form, &$form_state, $tier_type, $op = 'edit') {

  if ($op == 'clone') {
    $tier_type->label .= ' (cloned)';
    $tier_type->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $tier_type->label,
    '#description' => t('The human-readable name of this Tier type.'),
    '#required' => TRUE,
    '#size' => 30,
  );

  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => $tier_type->type,
    '#maxlength' => 32,
    '#disabled' => $tier_type->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'tier_type_load',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this Tier type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['description'] = array(
    '#type' => 'textarea',
    '#default_value' => isset($tier_type->description) ? $tier_type->description : '',
    '#description' => t('Description about the Tier type.'),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Tier type'),
    '#weight' => 40,
  );

  if (!$tier_type->isLocked() && $op != 'add' && $op != 'clone') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete Tier type'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('tier_type_form_submit_delete'),
    );
  }
  return $form;
}

/**
 * Submit handler for creating/editing Tier type.
 */
function tier_type_form_submit(&$form, &$form_state) {
  $tier_type = entity_ui_form_submit_build_entity($form, $form_state);
  // Save and go back.
  tier_type_save($tier_type);

  if ($form_state['op'] == 'edit') {
    drupal_set_message(t('Tier type @type updated', array('@type' => $tier_type->type)));
  }
  else {
    drupal_set_message(t('Tier type @type created', array('@type' => $tier_type->type)));
  }

  // Redirect user back to list of Tier types.
  $form_state['redirect'] = 'admin/structure/tier-types';
}

/**
 * Page to select Tier Type to add new Tier.
 */
function tier_admin_add_page() {
  $items = array();
  foreach (tier_types() as $tier_type_key => $tier_type) {
    $items[] = l(entity_label('tier_type', $tier_type), 'tier/add/' . $tier_type_key);
  }
  if (!empty($items)) {
    return array(
      'list' => array(
        '#theme' => 'item_list',
        '#items' => $items,
        '#title' => t('Select type of Tier to create.')
      )
    );
  }
  else {
    return t('You need to add Tier types before create Tier items. !link', array('!link' => l(t('You can add Tier types here.'), 'admin/structure/tier-types/add', array('query' => array('destination' => 'tier/add')))));
  }
}

/**
 * Tier Form.
 */
function tier_form($form, &$form_state, $tier, $parent_nid = NULL, $row_position = NULL, $js = NULL) {
  if ($parent_nid && is_numeric($parent_nid)) {
    $tier->parent_nid = $parent_nid;
  }

  if ($row_position && is_numeric($row_position)) {
    $tier->row_position = $row_position;
  }

  $entity_info   = entity_get_info('tier');

  // dpm($tier, 'The tier default sent to the form creation hook');

  $form_state['tier'] = $tier;

  // Basic tier information.
  // These elements are just values so they are not even sent to the client.
  foreach (array('tier_id', 'uid', 'created', 'type') as $key) {
    $form[$key] = array(
      '#type' => 'value',
      '#value' => isset($tier->$key) ? $tier->$key : NULL,
    );
  }

  $form['title'] = array(
    '#type' => 'textfield',
    '#required' => FALSE,
    '#title' => t('Heading/Title'),
    '#default_value' => $tier->title,
    '#description' => t('Optional: Create a heading for this segment. Leave blank for no heading.'),
    '#attributes' => array(
      // 'placeholder' => t('Monkey'),
    ),
  );

  //$form['description'] = array(
  //  '#type' => 'textarea',
  //  '#title' => t('Description'),
  //  '#default_value' => $tier->description,
  //);

  $form['uid'] = array(
    '#type' => 'value',
    '#value' => $tier->uid,
  );

  field_attach_form('tier', $tier, $form, $form_state);

  $submit = array();
  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions'] = array(
    '#weight' => 100,
  );

  // Match the non-machine name of the bundle and place it on the submit button
  $bundle_name = $form['#bundle'];
  // dpm($entity_info, '$entity info for this tier');

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save @type', array('@type' => strtolower($entity_info['bundles'][$bundle_name]['label']))),
    '#submit' => $submit + array('tier_form_submit'),
  );

  // Show Delete button if we edit Tier.
  $tier_id = entity_id('tier', $tier);
  if (!empty($tier_id) && tier_access('edit', $tier)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#submit' => array('tier_form_submit_delete'),
    );
  }

  // dpm($form, '$form of the tier');

  return $form;
}

/**
 * Tier validate callback.
 */
function tier_form_validate($form, &$form_state) {
  entity_form_field_validate('tier', $form, $form_state);
}

/**
 * Tier submit handler.
 */
function tier_form_submit($form, &$form_state) {
  $tier = $form_state['tier'];

  entity_form_submit_build_entity('tier', $tier, $form, $form_state);

  tier_save($tier);

  $tier_uri = entity_uri('tier', $tier);
  $node_uri = 'node/' . $tier->parent_nid;

  // AE: Redirect to the parent node instead
  // $form_state['redirect'] = $tier_uri['path'];
  $form_state['redirect'] = $node_uri;

  drupal_set_message(t('Tier %title saved.', array('%title' => entity_label('tier', $tier))));
}

/**
 * Tier delete submit handler.
 */
function tier_form_submit_delete($form, &$form_state) {
  $destination = array();
  if (isset($_GET['destination'])) {
    $destination = drupal_get_destination();
    unset($_GET['destination']);
  }
  $tier = $form_state['tier'];
  $tier_uri = entity_uri('tier', $tier);
  $form_state['redirect'] = array($tier_uri['path'] . '/delete', array('query' => $destination));

}

/**
 * Delete confirmation form.
 */
function tier_delete_form($form, &$form_state, $tier) {
  $form_state['tier'] = $tier;
  // Always provide entity id in the same form key as in the entity edit form.
  $form['tier_id'] = array('#type' => 'value', '#value' => entity_id('tier', $tier));
  $tier_uri = entity_uri('tier', $tier);
  return confirm_form($form,
    t('Are you sure you want to delete Tier %title?', array('%title' => entity_label('tier', $tier))),
    $tier_uri['path'],
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Delete form submit handler.
 */
function tier_delete_form_submit($form, &$form_state) {
  $tier = $form_state['tier'];
  tier_delete($tier);

  drupal_set_message(t('Tier %title deleted.', array('%title' => entity_label('tier', $tier))));

  $form_state['redirect'] = '<front>';
}
