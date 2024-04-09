#pragma once

#include "entity.h"

class Background : Entity {
    static sf::Texture texture;
public:
    Background();

    void draw(sf::RenderWindow& window) override;
};