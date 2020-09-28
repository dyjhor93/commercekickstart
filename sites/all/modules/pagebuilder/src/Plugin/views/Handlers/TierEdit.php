<?php

/**
 * @file
 * Contains \Drupal\entity_boilerplate\Plugin\Views\Handlers\TierEdit.
 */

namespace Drupal\entity_boilerplate\Plugin\views\Handlers;

class TierEdit extends TierLink {

  /**
   * Renders the link.
   */
  function render_link($entity, $values) {
    // Ensure user has access to edit this node.
    if (!tier_access('update', $entity)) {
      return;
    }

    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['path'] = "admin/content/tier/$entity->tier_id/edit";
    $this->options['alter']['query'] = drupal_get_destination();

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    return $text;
  }
}
