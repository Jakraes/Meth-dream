#include "gameobject.h"

GameObject* gameobject_new(Point position, Tile* tile, bool solid) {
    GameObject* result = malloc(sizeof(GameObject));

    result->position = position;
    result->tile = tile;
    result->solid = solid;

    return result;
}

void gameobject_free(void* obj) {
    GameObject* ptr = (GameObject*) obj;

    if (ptr) {
        free(ptr);
    }
}