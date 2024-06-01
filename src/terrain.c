#include "terrain.h"

void _create_terrain_grass(Point position, Terrain* terrain) {
    terrain->object = gameobject_new(position, &terrain_grass, false);
}

void _create_terrain(Point position, Terrain* terrain) {
    switch (terrain->type) {
        case TERRAIN_GRASS:
            _create_terrain_grass(position, terrain);
            break;

        default:
            break;
    }
}

Terrain* terrain_new(Point position, TerrainType type) {
    Terrain* result = malloc(sizeof(Terrain));

    result->type = type;

    _create_terrain(position, result);

    return result;
}

void terrain_free(void* obj) {
    Terrain* ptr = (Terrain*) obj;

    if (ptr) {
        gameobject_free(ptr->object);
        free(ptr);
    }
}