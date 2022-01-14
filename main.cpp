#include <spdlog/spdlog.h>
#include <SFML/Graphics.hpp>

void sfmlWindow() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test Window");
    while (window.isOpen())
    {
        window.clear(sf::Color(0, 0, 0, 255));
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.display();
    }
}

int main() {
    spdlog::info("Program start");
    sfmlWindow();
    return 0;
}
