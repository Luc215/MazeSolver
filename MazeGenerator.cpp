#include "SFML/Graphics.hpp"
#include "Headers/generator.hpp"
//using Randomized Kruskals Algo to draw Maze
// Step one: Draw a grid
//Step 2: 
void drawGrid(sf::RenderWindow& window){
    //row and cols const for now. will change when ui introduced
    //why did i decide to use c++? do i hate myself?
    const int rows = 500;
    const int cols = 200;
    const float cellLength = 50;
    const float cellWidth  = 50;
    sf::RectangleShape cell(sf::Vector2f(cellLength - 1, cellWidth - 1));
    cell.setFillColor(sf::Color::Blue);

    for(int r = 0; r < rows; ++r){
        for(int c = 0; c < cols; ++c){
            cell.setPosition({c * cellLength, r * cellWidth});
            window.draw(cell);
        }
    }

}