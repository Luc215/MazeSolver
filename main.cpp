#include <SFML/Graphics.hpp>
#include "Headers/generator.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({1000, 1000}), "Maze", sf::Style::Titlebar | sf::Style::Close);
    sf::CircleShape shape(100.f);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        drawGrid(window);
        window.display();
    }
}