#include "entity.h"

void _create_entity_player(Point position, Entity* entity) {
    entity->object = gameobject_new(position, &entity_player);
}

void _create_entity(Point position, Entity* entity) {
    switch (entity->type) {
        case ENTITY_PLAYER:
            _create_entity_player(position, entity);
            break;

        default:
            break;
    }
}

Entity* entity_new(Point position, EntityType type) {
    Entity* result = malloc(sizeof(Entity));

    result->type = type;

    _create_entity(position, result);

    return result;
}

void entity_free(void* obj) {
    Entity* ptr = (Entity*) obj;

    if (ptr) {
        gameobject_free(ptr->object);
        free(ptr);
    }
}