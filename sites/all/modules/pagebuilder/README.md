#Page builder

Extends nodes to have multiple content tiers (a.k.a rows) of tier content (of different types). This is the basic framework that creates the entity type (tier).

Created by André Ellis for Rogerwilco (http://rogerwilco.co.za)
Initially built onto entity boilerplate  (https://github.com/plopesc/entity_boilerplate/blob/7.x-1.x/src/Entity/EntityInterface.php) by Pablo Lopez (https://github.com/plopesc)

## Usage

*  Go to /admin/modules and enable Page builder module.
*  Go to /admin/structure/tier-types/add and create at least one custom tier type (or install an existing tier type module/feature). Pagebuilder ships with an example "Paragraph" feature.
*  Go to /admin/structure/types, edit the content type that you want to have Page builder enabled.
*  Create content of the above content type
