#pragma once

#include "entity.h"

class Ball : public Entity {
    static sf::Texture texture;
    float x, y;
public:
    Ball(float x, float y);
    bool update();
    void draw(sf::RenderWindow& window) override;
    float get_x();
    float get_y();
};