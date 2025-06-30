#include <SFML/Graphics.hpp>
#include "Headers/generator.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode({1005, 805}), "Maze", sf::Style::Titlebar | sf::Style::Close);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        grid(window);
        button(1,820,75,window);
        window.display();
    }

}