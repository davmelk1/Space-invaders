#include "enemy.h"

void Enemy::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Enemy::set_red() {
    sprite.setColor(sf::Color::Red);
}
