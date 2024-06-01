#ifndef TILE_H
#define TILE_H

#include "BearLibTerminal.h"

typedef struct {
    color_t fg_color;
    color_t bg_color;
    wchar_t glyph;
} Tile;

// Entity
extern Tile entity_player;
extern Tile entity_player_jump;

// Terrain
extern Tile terrain_grass;

// Item
extern Tile item_iron_sword;

#endif