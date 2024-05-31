#ifndef ITEM_H
#define ITEM_H

#include "gameobject.h"

typedef enum {
    ITEM_IRON_SWORD
} ItemType;

typedef struct {
    GameObject* object;
    ItemType type;
} Item;

Item* item_new(Point position, ItemType type);
void item_free(void* obj);

#endif