#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "tile.h"
#include "point.h"

#include <stdlib.h>

typedef struct {
    Point position;
    Tile* tile;
} GameObject;

GameObject* gameobject_new(Point position, Tile* tile);
void gameobject_free(void* obj);

#endif
