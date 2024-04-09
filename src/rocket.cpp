#include "rocket.h"

sf::Texture Rocket::texture;

Rocket::Rocket() {
    reset();
}

void Rocket::reset() {
    texture.loadFromFile(constants::ROCKET_IMAGE_PATH);
    sprite.setTexture(texture);
    auto size = texture.getSize();
    sprite.setScale(float(constants::ROCKET_WIDTH) / size.x, float(constants::ROCKET_HEIGHT) / size.y);
    x = constants::WINDOW_WIDTH / 2. - constants::ROCKET_WIDTH / 2.;
    y = constants::WINDOW_HEIGHT - constants::ROCKET_HEIGHT - constants::MARGIN_BOTTOM;
    sprite.setPosition(x, y);
}

void Rocket::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Rocket::move_right() {
    if (x + constants::ROCKET_WIDTH + constants::ROCKET_STEP > constants::WINDOW_WIDTH)
        return;
    x += constants::ROCKET_STEP;
    sprite.setPosition(x, y);
}

void Rocket::move_left() {
    if (x < constants::ROCKET_STEP)
        return;
    x -= constants::ROCKET_STEP;
    sprite.setPosition(x, y);
}

float Rocket::get_x() {
    return sprite.getPosition().x;
}

float Rocket::get_y() {
    return sprite.getPosition().y;
}
