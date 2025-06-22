#include "SFML/Graphics.hpp"
#include "Headers/generator.hpp"
#include <vector>
//using Randomized Kruskals Algo to draw Maze
// Step one: Draw a grid
//Step 2:

//might move later to different file idk
std::vector<std::vector<float>> cells = {};
void grid(sf::RenderWindow& window){
    //row and cols const for now. will change when ui introduced
    //why did i decide to use c++? do i hate myself?
    const int rows = 500;
    const int cols = 200;
    const float cellLength = 50;
    const float cellWidth  = 50;
    sf::RectangleShape cellRect(sf::Vector2f(cellLength-1, cellWidth-1));

    cellRect.setFillColor(sf::Color::White);

    for(int r = 0; r < rows; ++r){
        for(int c = 0; c < cols; ++c){
            cellRect.setPosition({c * cellLength, r * cellWidth});
            cells.push_back({c * cellLength, r * cellWidth});

            window.draw(cellRect);
        }
    }
    
}

//need to redraw each state
void redraw_grid(){

}
//for when we will implement button to make maze generate or not type shit
void button(){

}