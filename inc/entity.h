#ifndef ENTITY_H
#define ENTITY_H

#include "gameobject.h"

typedef enum {
    ENTITY_PLAYER
} EntityType;

typedef struct {
    GameObject* object;
    EntityType type;
} Entity;

Entity* entity_new(Point position, EntityType type);
void entity_free(void* obj);

#endif