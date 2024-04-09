#include "game.h"

Game::Game(): window{{constants::WINDOW_WIDTH, constants::WINDOW_HEIGHT}, constants::WINDOW_TITLE},
                enemies(constants::NUMBER_OF_ROWS) {
    window.setFramerateLimit(100);
    window.setKeyRepeatEnabled(true);
    reset();
}

void Game::run() {
    while (window.isOpen()) {
        reset();
        int ball_count{-1};
        int attack_count{0};
        const auto start_time = std::chrono::steady_clock::now();
        while (window.isOpen()) {
            sf::Event event{};

            while (window.pollEvent(event))
                if (event.type == sf::Event::Closed)
                    window.close();

            if (detect_key_interaction())
                break;

            auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::steady_clock::now() - start_time).count();
            if (delta / constants::NEW_BALL_FREQUENCY > ball_count) {
                ++ball_count;
                balls.emplace_back(new Ball(rocket.get_x() + constants::ROCKET_WIDTH / 2.f - constants::BALL_WIDTH / 2.f, rocket.get_y()));
            }
            if (delta / constants::ENEMY_ATTACK_TIME > attack_count) {
                for (auto &enemy_row: enemies)
                    for (auto &enemy: enemy_row)
                        if (enemy)
                            enemy->attack();
                ++attack_count;
            }

            check_enemy_destruction();

            if (check_lose() || check_win())
                break;

            display();
        }
    }
}

void Game::reset() {
    rocket.reset();
    for (auto& row : enemies)
        row.clear();
    float x{constants::ENEMY_MARGIN_SIDE}, y{constants::MARGIN_BOTTOM};
    for (int i{0}; i < constants::NUMBER_OF_ROWS; ++i) {
        for (int j{0}; j < constants::NUMBER_OF_COLUMNS; ++j) {
            enemies[i].emplace_back(new SimpleEnemy(x, y));
            x += constants::ENEMY_WIDTH + constants::ENEMY_PADDING;
        }
        x = constants::ENEMY_MARGIN_SIDE;
        y += constants::ENEMY_HEIGHT;
    }
    auto it = balls.begin();
    while (it != balls.end()) {
        delete (*it);
        it = balls.erase(it);
    }
}

void Game::display() {
    window.clear();
    bg.draw(window);
    rocket.draw(window);
    for (auto &enemy_row: enemies)
        for (auto &enemy: enemy_row)
            if (enemy)
                enemy->draw(window);
    auto it = balls.begin();
    while (it != balls.end() && *it) {
        if ((*it)->update()) {
            delete (*it);
            it = balls.erase(it);
        }
        else {
            (*it)->draw(window);
            ++it;
        }
    }

    window.display();
}

bool Game::detect_key_interaction() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        window.close();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        rocket.move_right();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        rocket.move_left();
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
        reset();
        return true;
    }
    return false;
}

void Game::check_enemy_destruction() {
    auto row = enemies.begin();
    while (row != enemies.end()) {
        auto enemy = row->begin();
        while (enemy < row->end()) {
            auto itit = balls.begin();
            while (itit != balls.end()) {
                if (handle_interaction(*enemy, *itit)) {
                    enemy = row->erase(enemy);
                    balls.erase(itit);
                    break;
                }
                else {
                    ++itit;
                }
            }
            ++enemy;
        }
        ++row;
    }
}

bool Game::check_lose() {
    bool lose = false;
    for (auto& row : enemies) {
        for (auto & enemy : row) {
            if (enemy->get_y() + constants::ENEMY_HEIGHT > rocket.get_y()) {
                enemy->set_red();
                lose = true;
            }
        }
    }
    if (lose) {
        display();
        auto a = std::chrono::steady_clock::now();
        while (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - a).count() < 2)
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                window.close();
        reset();
    }
    return lose;
}

bool Game::check_win() {
    for (const auto& row : enemies)
        for (const auto& enemy : row)
            if (enemy)
                return false;
    display();
    auto a = std::chrono::steady_clock::now();
    while (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - a).count() < 2)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            window.close();
    return true;
}
