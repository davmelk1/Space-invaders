#pragma once

namespace constants{
    constexpr int WINDOW_WIDTH{400};
    constexpr int WINDOW_HEIGHT{500};
    constexpr int MARGIN_BOTTOM{WINDOW_HEIGHT / 25};

    constexpr int ROCKET_WIDTH{60};
    constexpr int ROCKET_HEIGHT{50};
    constexpr int ROCKET_STEP{2};

    constexpr int BALL_WIDTH{7};
    constexpr int BALL_STEP{5};
    constexpr int NEW_BALL_FREQUENCY{300};

    constexpr int NUMBER_OF_ROWS{4};
    constexpr int NUMBER_OF_COLUMNS{7};
    constexpr int ENEMY_WIDTH{WINDOW_WIDTH / (NUMBER_OF_COLUMNS + 5)};
    constexpr int ENEMY_HEIGHT{ENEMY_WIDTH};
    constexpr int ENEMY_MARGIN_SIDE{ENEMY_WIDTH};
    constexpr int ENEMY_PADDING = (WINDOW_WIDTH - NUMBER_OF_COLUMNS * ENEMY_WIDTH - ENEMY_MARGIN_SIDE) / NUMBER_OF_COLUMNS;
    constexpr int ENEMY_ATTACK_TIME{1000};

    constexpr const char* WINDOW_TITLE{"Space Invaders"};
    constexpr const char* BACKGROUND_IMAGE_PATH{"/home/davit/Documents/SFML/space_invaders/img/cosmo.jpg"};
    constexpr const char* ROCKET_IMAGE_PATH{"/home/davit/Documents/SFML/space_invaders/img/rocket.png"};
    constexpr const char* SIMPLE_ENEMY_IMAGE_PATH{"/home/davit/Documents/SFML/space_invaders/img/white_bik.png"};
    constexpr const char* SMART_ENEMY_IMAGE_PATH{"/home/davit/Documents/SFML/space_invaders/img/white_bzik.png"};
    constexpr const char* BALL_IMAGE_PATH{"/home/davit/Documents/SFML/space_invaders/img/ball.png"};
}
