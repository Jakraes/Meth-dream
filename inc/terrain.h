#ifndef TERRAIN_H
#define TERRAIN_H

#include "gameobject.h"

typedef enum {
    TERRAIN_GRASS
} TerrainType;

typedef struct {
    GameObject* object;
    TerrainType type;
} Terrain;

Terrain* terrain_new(Point position, TerrainType type);
void terrain_free(void* obj);

#endif