#include "utils.h"

bool handle_interaction(Enemy* enemy, Ball* ball) {
    if (enemy == nullptr || ball == nullptr)
        return false;
    if (ball->sprite.getGlobalBounds().intersects(enemy->sprite.getGlobalBounds())) {
        delete ball;
        delete enemy;
        return true;
    }
    return false;
}