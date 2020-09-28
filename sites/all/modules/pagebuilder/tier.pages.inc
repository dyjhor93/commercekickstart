<?php

/**
 * Tier view callback.
 */
function tier_view($tier) {
  drupal_set_title(entity_label('tier', $tier));
  return entity_view('tier', array(entity_id('tier', $tier) => $tier), 'full');
}

/**
 * Add new Tier page callback.
 */
function tier_add($type, $parent_node = NULL, $row_position = NULL, $js = NULL) {
  $tier_type = tier_types($type);

  if ($parent_node != NULL) {
    $parent_nid = $parent_node->nid;
  }
  else {
    $parent_nid = 0;
  }

  $tier = entity_create('tier', array('type' => $type, 'parent_nid' => $parent_nid, 'row_position' => $row_position));
  drupal_set_title(t('Create Tier @name', array('@name' => entity_label('tier_type', $tier_type))));

  $form_state = array();
  $form_state['build_info']['args'] = array($tier);
  form_load_include($form_state, 'inc', 'pagebuilder', 'tier.entity');
  return drupal_build_form($type . '_tier_form', $form_state);
}

/**
 * Edit Tier page callback.
 */
function tier_edit($tier) {
  $tier_type = tier_types($tier->type);
  drupal_set_title(t('<em>Edit @type</em> @title', array('@type' => entity_label('tier_type', $tier_type), '@title' => entity_label('tier', $tier))), PASS_THROUGH);

  $form_state = array();
  $form_state['build_info']['args'] = array($tier);
  form_load_include($form_state, 'inc', 'pagebuilder', 'tier.entity');
  return drupal_build_form($tier->type . '_tier_form', $form_state);
}