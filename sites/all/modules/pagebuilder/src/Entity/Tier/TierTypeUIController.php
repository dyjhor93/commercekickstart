<?php

/**
 * @file
 * Contains class \Drupal\pagebuilder\Entity\Tier\TierTypeUIController.
 */

namespace Drupal\pagebuilder\Entity\Tier;

class TierTypeUIController extends \EntityDefaultUIController {

  /**
   * {@inheritdoc}
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = 'Manage Tier types.';
    return $items;
  }

}
