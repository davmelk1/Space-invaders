#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <chrono>
#include <iostream>
#include <thread>
#include <mutex>

#include "background.h"
#include "rocket.h"
#include "simple_enemy.h"
#include "ball.h"
#include "utils.h"

using namespace std::chrono_literals;

class Game {
    std::vector<std::vector<Enemy*>> enemies;
    std::vector<Ball*> balls;
    Rocket rocket;
    Background bg;
    sf::RenderWindow window;

    void reset();

public:
    Game();
    void run();

    void display();

    bool detect_key_interaction();

    void check_enemy_destruction();

    bool check_lose();

    bool check_win();
};