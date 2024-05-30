#pragma once

#include "Tile.h"
#include "Point.h"

class GameObject {
    public:
        Tile& tile;
        Point position;

        GameObject(Tile& tile, Point position) : tile(tile), position(position) {};

        // Events
        virtual void onInteract();
        virtual void onCollision();
};