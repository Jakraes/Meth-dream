#pragma once

#include "../GameObject.h"

class Entity : public GameObject {
    public:
        int maxHp;
        int hp;

        Entity(Tile& tile, Point position, int maxHp, int hp) : GameObject(tile, position), maxHp(maxHp), hp(hp);
}