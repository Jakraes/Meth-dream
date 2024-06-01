#include "gamemap_entity.h"
#include <stdio.h>

void _entity_player_move(Entity* entity, GameMap* map) {
    Point next_pos = point(0, 0);
    
    switch (window_key) {
        case TK_KP_8:
        case TK_UP:
            next_pos = point(0, -1);
            break;

        case TK_KP_2:
        case TK_DOWN:
            next_pos = point(0, 1);
            break;

        case TK_KP_4:
        case TK_LEFT:
            next_pos = point(-1, 0);
            break;

        case TK_KP_6:
        case TK_RIGHT:
            next_pos = point(1, 0);
            break;

        case TK_KP_7:
            next_pos = point(-1, -1);
            break;

        case TK_KP_9:
            next_pos = point(1, -1);
            break;

        case TK_KP_1:
            next_pos = point(-1, 1);
            break;

        case TK_KP_3:
            next_pos = point(1, 1);
            break;
    }

    if (!gamemap_is_solid(map, point_add(entity->object->position, next_pos))) {
        printf("Hello");
        entity->object->position = point_add(entity->object->position, next_pos);
    }
}

void entity_move(Entity* entity, GameMap* map) {
    switch (entity->type) {
        case ENTITY_PLAYER:
            _entity_player_move(entity, map);
            break;
    }
}

void gamemap_move_all(GameMap* map) {
    for (size_t i = 0; i < map->entities->length; i++) {
        entity_move((Entity*) array_get(map->entities, i), map);
    }
}