#include "ball.h"

sf::Texture Ball::texture;

Ball::Ball(float x, float y) : x{x}, y{y} {
    texture.loadFromFile(constants::BALL_IMAGE_PATH);
    sprite.setTexture(texture);
    auto size = texture.getSize();
    sprite.setScale(float(constants::BALL_WIDTH) / size.x, float(constants::BALL_WIDTH) / size.y);
    sprite.setPosition(x, y);
}

void Ball::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

bool Ball::update() {
    if (y < constants::MARGIN_BOTTOM)
        return true;
    y -= constants::BALL_STEP;
    sprite.setPosition(x, y);
    return false;
}

float Ball::get_x() {
    return sprite.getPosition().x;
}

float Ball::get_y() {
    return sprite.getPosition().y;
}
