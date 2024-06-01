#include "gamemap.h"

void _gamemap_generate_test(GameMap* map) {
    for (size_t y = 0; y < map->height; y++) {
        for (size_t x = 0; x < map->width; x++) {
            Terrain* terrain = terrain_new(point(x, y), TERRAIN_GRASS);
            gamemap_add_terrain(map, terrain);
        }
    }

    Entity* entity = entity_new(point(0, 0), ENTITY_PLAYER);
    gamemap_add_entity(map, entity);

    Item* item = item_new(point(4, 6), ITEM_IRON_SWORD);
    gamemap_add_item(map, item);
}

GameMap* gamemap_new(size_t width, size_t height, GameMapType type) {
    GameMap* result = malloc(sizeof(GameMap));

    result->width = width;
    result->height = height;
    result->entities = array_new(entity_free);
    result->terrains = array_new(terrain_free);
    result->items = array_new(item_free);
    result->type = type;

    return result;
}

void gamemap_free(void* map) {
    GameMap* ptr = (GameMap*) map;

    if (ptr) {
        array_free(ptr->entities);
        array_free(ptr->terrains);
        array_free(ptr->items);
        free(ptr);
    }
}

void gamemap_generate(GameMap* map) {
    switch (map->type) {
        case GAMEMAP_TEST:
            _gamemap_generate_test(map);
            break;

        default:
            break;
    }
}

void gamemap_add_entity(GameMap* map, Entity* entity) {
    array_push(map->entities, entity);    
}

void gamemap_add_terrain(GameMap* map, Terrain* terrain) {
    array_push(map->terrains, terrain);
}

void gamemap_add_item(GameMap* map, Item* item) {
    array_push(map->items, item);
}

Entity* gamemap_get_entity_position(GameMap* map, Point position) {
    Entity* result = NULL;

    for (size_t i = 0; i < map->entities->length; i++) {
        Entity* entity = array_get(map->entities, i);
        if (point_eq(entity->object->position, position)) {
            result = entity;
            break;
        }
    }

    return result;
}

Terrain* gamemap_get_terrain_position(GameMap* map, Point position) {
    Terrain* result = NULL;

    for (size_t i = 0; i < map->terrains->length; i++) {
        Terrain* terrain = array_get(map->terrains, i);
        if (point_eq(terrain->object->position, position)) {
            result = terrain;
            break;
        }
    }

    return result;
}

Item* gamemap_get_item_position(GameMap* map, Point position) {
    Item* result = NULL;

    for (size_t i = 0; i < map->items->length; i++) {
        Item* item = array_get(map->items, i);
        if (point_eq(item->object->position, position)) {
            result = item;
            break;
        }
    }

    return result;
}

void gamemap_remove_entity(GameMap* map, Entity* entity) {
    array_remove_ptr(map->entities, entity);
}

void gamemap_remove_terrain(GameMap* map, Terrain* terrain) {
    array_remove_ptr(map->terrains, terrain);
}

void gamemap_remove_item(GameMap* map, Item* item) {
    array_remove_ptr(map->items, item);
}

void gamemap_add_player(GameMap* map, Entity* entity) {
    map->player = entity;

    gamemap_add_entity(map, entity);
}

bool gamemap_is_solid(GameMap* map, Point position) {
    for (size_t i = 0; i < map->terrains->length; i++) {
        Terrain* terrain = array_get(map->terrains, i);
        if (terrain->object->solid) {
            if (point_eq(terrain->object->position, position)) {
                return true;
            }
        }
    }

    for (size_t i = 0; i < map->entities->length; i++) {
        Entity* entity = array_get(map->entities, i);
        if (entity->object->solid) {
            if (point_eq(entity->object->position, position)) {
                return true;
            }
        }
    }

    for (size_t i = 0; i < map->items->length; i++) {
        Item* item = array_get(map->items, i);
        if (item->object->solid) {
            if (point_eq(item->object->position, position)) {
                return true;
            }
        }
    }

    return false;
}