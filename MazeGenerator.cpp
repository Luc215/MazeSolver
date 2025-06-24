#include "SFML/Graphics.hpp"
#include "Headers/generator.hpp"
#include <vector>
//using Randomized Kruskals Algo to draw Maze
// Step one: Draw a grid
//Step 2:

//might move later to different file idk
std::vector<std::vector<float>> cells = {};
// {top,bottom,left, right}
std::vector<std::vector<int>> borders = {};
void grid(sf::RenderWindow& window){
    //row and cols const for now. will change when ui introduced. defines how many cells.
    //why did i decide to use c++? do i hate myself?
    //would we need to make sure only one wall is printed between cells? yes.
    const int rows = 10;
    const int cols = 10;
    const float cellLength = 800/rows;
    const float cellWidth  = 800/cols;
    
    sf::RectangleShape cellRect(sf::Vector2f(cellLength, cellWidth));
    sf::RectangleShape borderTop(sf::Vector2f(cellLength,5));
    sf::RectangleShape borderBottom(sf::Vector2f(cellLength,5));
    sf::RectangleShape borderLeft(sf::Vector2f(5,cellWidth));
    sf::RectangleShape borderRight(sf::Vector2f(5,cellWidth));
    cellRect.setFillColor(sf::Color::White);
    borderTop.setFillColor(sf::Color::Black);
    borderBottom.setFillColor(sf::Color::Black);
    borderLeft.setFillColor(sf::Color::Black);
    borderRight.setFillColor(sf::Color::Black);

    cellRect.setFillColor(sf::Color::White);
        for(int r = 0; r < rows*rows; r++){
        for(int c = 0; c < cols; c++){
            cells.push_back({c * cellLength, r * cellWidth});
            cellRect.setPosition({cells[r][0], cells[r][1]});
            borderLeft.setPosition({cells[r][0],cells[r][1]});
            borderRight.setPosition({cells[r][0]* 2,cells[r][1]});
            borderTop.setPosition({cells[r][0],cells[r][1]});
            borderBottom.setPosition({cells[r][0],cells[r][1]*2});

            window.draw(cellRect);
            window.draw(borderRight);
            window.draw(borderLeft);
            window.draw(borderBottom);
            window.draw(borderTop);
        }
    }

}


//need to redraw each state
void redraw_grid(){

}
//for when we will implement button to make maze generate or not type shit
void button(){

}