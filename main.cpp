#include <SFML/Graphics.hpp>
#include "Headers/generator.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 800}), "Maze", sf::Style::Titlebar | sf::Style::Close);

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