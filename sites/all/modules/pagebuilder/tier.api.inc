<?php

/**
 * @file
 * API functions related to Tier entity.
 */

/*******************************************************************************
 ********************************* Tier API's *******************************
 ******************************************************************************/

/**
 * Access callback for Tier.
 */
function tier_access($op, $tier, $account = NULL) {
  return pagebuilder_entity_access($op, $tier, $account, 'tier');
}

/**
 * Load a Tier.
 */
function tier_load($tier_id, $reset = FALSE) {
  $my_entities = tier_load_multiple(array($tier_id), array(), $reset);
  return reset($my_entities);
}

/**
 * Load multiple Tier based on certain conditions.
 */
function tier_load_multiple($tier_ids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('tier', $tier_ids, $conditions, $reset);
}

/**
 * Save Tier.
 */
function tier_save($tier) {
  entity_save('tier', $tier);
}

/**
 * Delete single Tier.
 */
function tier_delete($tier) {
  entity_delete('tier', entity_id('tier', $tier));
}

/**
 * Delete multiple Tiers.
 */
function tier_delete_multiple($tier_ids) {
  entity_delete_multiple('tier', $tier_ids);
}


/*******************************************************************************
 ****************************** Tier Type API's *****************************
 ******************************************************************************/

/**
 * Access callback for Tier Type.
 */
function tier_type_access($op, $entity = NULL, $account = NULL) {
  return user_access('administer tier_type entities', $account);
}

/**
 * Load Tier Type.
 */
function tier_type_load($tier_type) {
  return tier_types($tier_type);
}

/**
 * List of Tier Types.
 */
function tier_types($type_name = NULL) {
  $types = entity_load_multiple_by_name('tier_type', isset($type_name) ? array($type_name) : FALSE);
  return isset($type_name) ? reset($types) : $types;
}

/**
 * Save Tier Type entity.
 */
function tier_type_save($tier_type) {
  entity_save('tier_type', $tier_type);
}

/**
 * Delete single Tier type.
 */
function tier_type_delete($tier_type) {
  entity_delete('tier_type', entity_id('tier_type', $tier_type));
}

/**
 * Delete multiple Tier types.
 */
function tier_type_delete_multiple($tier_type_ids) {
  entity_delete_multiple('tier_type', $tier_type_ids);
}
