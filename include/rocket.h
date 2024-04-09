#pragma once

#include "entity.h"

class Rocket : Entity{
    static sf::Texture texture;
    float x, y;
public:
    Rocket();
    void reset();
    void move_right();
    void move_left();
    float get_x();
    float get_y();
    void draw(sf::RenderWindow &) override;
};