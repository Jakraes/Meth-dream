#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "array.h"
#include "entity.h"
#include "terrain.h"
#include "item.h"

#include <stdlib.h>

typedef enum {
    GAMEMAP_TEST
} GameMapType;

typedef struct {
    size_t width;
    size_t height;
    Array* entities;
    Array* terrains;
    Array* items;
    GameMapType type;
    Entity* player;
} GameMap;

GameMap* gamemap_new(size_t width, size_t height, GameMapType type);
void gamemap_free(void* map);

void gamemap_generate(GameMap* map);

void gamemap_add_entity(GameMap* map, Entity* entity);
void gamemap_add_player(GameMap* map, Entity* entity);
void gamemap_add_terrain(GameMap* map, Terrain* terrain);
void gamemap_add_item(GameMap* map, Item* item);

Entity* gamemap_get_entity_position(GameMap* map, Point position);
Terrain* gamemap_get_terrain_position(GameMap* map, Point position);
Item* gamemap_get_item_position(GameMap* map, Point position);

void gamemap_remove_entity(GameMap* map, Entity* entity);
void gamemap_remove_terrain(GameMap* map, Terrain* terrain);
void gamemap_remove_item(GameMap* map, Item* item);

void gamemap_move_all(GameMap* map);

bool gamemap_is_solid(GameMap* map, Point position);

#endif