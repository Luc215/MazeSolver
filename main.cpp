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
        //ID: 1 is for stopping and playing algorithms. 2 is for step by step of algorithm. 3 is for reinitializing maze
        button(1,820,75,window);
        button(2,820,175,window);
        button(3,820,275,window);
        // ID will be 4 for scroll.
        scroll(4,820,375,100,50,window);

        finish();
        window.display();
    }

}