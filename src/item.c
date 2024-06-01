#include "item.h"

void _create_item_iron_sword(Point position, Item* item) {
    item->object = gameobject_new(position, &item_iron_sword, false);
}

void _create_item(Point position, Item* item) {
    switch (item->type) {
        case ITEM_IRON_SWORD:
            _create_item_iron_sword(position, item);
            break;

        default:
            break;
    }
}

Item* item_new(Point position, ItemType type) {
    Item* result = malloc(sizeof(Item));

    result->type = type;

    _create_item(position, result);

    return result;
}

void item_free(void* obj) {
    Item* ptr = (Item*) obj;

    if (ptr) {
        gameobject_free(ptr->object);
        free(ptr);
    }
}