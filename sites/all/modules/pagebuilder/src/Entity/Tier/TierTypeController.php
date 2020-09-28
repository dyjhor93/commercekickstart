<?php

/**
 * @file
 * Contains class \Drupal\pagebuilder\Entity\Tier\TierTypeController.
 */

namespace Drupal\pagebuilder\Entity\Tier;

class TierTypeController extends \EntityAPIControllerExportable {

  /**
   * {@inheritdoc}
   */
  public function create(array $values = array()) {
    $values += array(
      'label' => '',
      //'description' => '',
      'type' => '',
    );
    return parent::create($values);
  }

  /**
   * {@inheritdoc}
   */
  public function save($entity, \DatabaseTransaction $transaction = NULL) {
    parent::save($entity, $transaction);
    // Rebuild menu registry. We do not call menu_rebuild directly, but set
    // variable that indicates rebuild in the end.
    // @see http://drupal.org/node/1399618
    variable_set('menu_rebuild_needed', TRUE);
  }

}
