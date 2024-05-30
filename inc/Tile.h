#pragma once

#include "BearLibTerminal.h"

struct Tile {
    color_t fgColor;
    color_t bgColor;
    uint8_t glyph;

    Tile(color_t fgColor, color_t bgColor, uint8_t glyph): fgColor(fgColor), bgColor(bgColor), glyph(glyph){};
};

// Entities
const Tile TilePlayer = Tile(0xFF'FF'FF'FF, 0x00'00'00'00, '@');

// Terrain
const Tile TileGrass = Tile(0x00'FF'00'FF, 0x00'00'00'00, '.');

// Items