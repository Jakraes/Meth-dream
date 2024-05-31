#include "gameobject.h"

GameObject* gameobject_new(Point position, Tile* tile) {
    GameObject* result = malloc(sizeof(GameObject));

    result->position = position;
    result->tile = tile;

    return result;
}

void gameobject_free(void* obj) {
    GameObject* ptr = (GameObject*) obj;

    if (ptr) {
        free(ptr);
    }
}