#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window{{400, 500}, "Title", sf::Style::Titlebar | sf::Style::Close};
    sf::Event ev;

    while (window.isOpen()) {
        while (window.pollEvent(ev)) {
            if (ev.type == sf::Event::Closed)
                window.close();
            else if (ev.type == sf::Event::KeyPressed)
                if (ev.key.code == sf::Keyboard::Escape)
                    window.close();
        }

        window.clear(sf::Color::Red);
        window.display();
    }

    return 0;
}