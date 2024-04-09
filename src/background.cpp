#include "background.h"

sf::Texture Background::texture;

Background::Background() {
    texture.loadFromFile(constants::BACKGROUND_IMAGE_PATH);
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
    auto bg_size = texture.getSize();
    sprite.setScale((1.f * constants::WINDOW_WIDTH) / bg_size.x, (1.f * constants::WINDOW_HEIGHT) / bg_size.y);
}

void Background::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}