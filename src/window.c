#include "window.h"

const char *config = "window: title='The Meth Wizards', size=60x30; font: ./res/font_20x20.png, size=20x20";
int window_key = 0;

void window_open() {
    terminal_open();
    terminal_set(config);
}

void window_close() {
    terminal_close();
}

void window_draw(GameMap* map) {
    for (size_t i = 0; i < map->terrains->length; i++) {
        Terrain* terrain = array_get(map->terrains, i);
        terminal_color(terrain->object->tile->fg_color);
        terminal_bkcolor(terrain->object->tile->bg_color);
        terminal_put(terrain->object->position.x, terrain->object->position.y, terrain->object->tile->glyph);
    }

    for (size_t i = 0; i < map->items->length; i++) {
        Item* item = array_get(map->items, i);
        terminal_color(item->object->tile->fg_color);
        terminal_bkcolor(item->object->tile->bg_color);
        terminal_put(item->object->position.x, item->object->position.y, item->object->tile->glyph);
    }

    for (size_t i = 0; i < map->entities->length; i++) {
        Entity* entity = array_get(map->entities, i);
        terminal_color(entity->object->tile->fg_color);
        terminal_bkcolor(entity->object->tile->bg_color);
        terminal_put(entity->object->position.x, entity->object->position.y, entity->object->tile->glyph);
    }
}

void window_clear() {
    terminal_clear();
}

void window_refresh() {
    terminal_refresh();
}

void window_get_input() {
    window_key = terminal_read();
}