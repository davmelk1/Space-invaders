#pragma once

#include "enemy.h"

class SimpleEnemy : public Enemy {
    static sf::Texture texture;
    float x;
     float y;
public:
    SimpleEnemy(float x, float y);
    float get_x();
    float get_y();
    void attack() override;
    virtual ~SimpleEnemy() = default;
};
