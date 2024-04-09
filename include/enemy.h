#pragma once

#include "entity.h"

class Enemy : public Entity {
public:
    void draw(sf::RenderWindow& window) override;
    virtual float get_x() = 0;
    virtual float get_y() = 0;
    virtual void attack() = 0;
    virtual ~Enemy() = default;

    void set_red();
};