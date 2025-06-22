#include <SFML/Graphics.hpp>
#include "Headers/generator.hpp"
#include <iostream>

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
        grid(window);
        window.display();
    }

    for(int i = 0; i < cells.size(); i++){
        for(int x = 0; x < cells[i].size(); x++){
        std::cout << cells[i][x] << " ";
        }
    }
    std::cout << "\n";
}