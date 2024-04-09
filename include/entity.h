#pragma once

#include <SFML/Graphics.hpp>
#include "constants.h"

class Entity{
public:
    sf::Sprite sprite;
    virtual void draw(sf::RenderWindow&) = 0;

    virtual ~Entity() = default;
};