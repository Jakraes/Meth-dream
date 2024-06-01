#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "tile.h"
#include "point.h"

#include <stdlib.h>

typedef struct {
    Point position;
    Tile* tile;
    bool solid;
} GameObject;

GameObject* gameobject_new(Point position, Tile* tile, bool solid);
void gameobject_free(void* obj);

#endif