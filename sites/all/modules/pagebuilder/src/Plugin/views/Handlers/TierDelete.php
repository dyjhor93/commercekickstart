<?php

/**
 * @file
 * Contains \Drupal\entity_boilerplate\Plugin\Views\Handlers\TierDelete.
 */

namespace Drupal\entity_boilerplate\Plugin\views\Handlers;

class TierDelete extends TierLink {

  /**
   * Renders the link.
   */
  function render_link($entity, $values) {
    // Ensure user has access to delete this node.
    if (!tier_access('delete', $entity)) {
      return;
    }

    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['path'] = "admin/content/tier/$entity->tier_id/delete";
    $this->options['alter']['query'] = drupal_get_destination();

    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
    return $text;
  }
}
