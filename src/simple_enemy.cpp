#include "simple_enemy.h"

sf::Texture SimpleEnemy::texture;

SimpleEnemy::SimpleEnemy(float x, float y) : x{x}, y{y} {
    texture.loadFromFile(constants::SIMPLE_ENEMY_IMAGE_PATH);
    sprite.setTexture(texture);
    auto size = texture.getSize();
    sprite.setScale(float(constants::ENEMY_WIDTH) / size.x, float(constants::ENEMY_HEIGHT) / size.y);
    sprite.setPosition(x, y);
}

float SimpleEnemy::get_x() {
    return sprite.getPosition().x;
}

float SimpleEnemy::get_y() {
    return sprite.getPosition().y;
}

void SimpleEnemy::attack() {
    y += constants::ENEMY_HEIGHT;
    sprite.setPosition(x, y);
}