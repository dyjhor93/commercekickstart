<?php

/**
 * @file
 * Contains class \Drupal\pagebuilder\Entity\Tier\TierType.
 */

namespace Drupal\pagebuilder\Entity\Tier;

class TierType extends \Entity {

  public function __construct($values = array()) {
    parent::__construct($values, 'tier_type');
  }

  function isLocked() {
    return isset($this->status) && empty($this->is_new) && (($this->status & ENTITY_IN_CODE) || ($this->status & ENTITY_FIXED));
  }

}
