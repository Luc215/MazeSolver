#include "SFML/Graphics.hpp"
#include "Headers/generator.hpp"
#include <vector>
//using Randomized Kruskals Algo to draw Maze
// Step one: Draw a grid
//Step 2:

//might move later to different file idk
std::vector<std::vector<float>> cells = {};

// {top,left,right,bottom}
std::vector<std::vector<bool>> borders = {};

//here we will truly populate cells with walls. true equals wall should be present. else not
void wallPopulation(int rows, int cols){
    int totalCells = rows * cols;
    borders.resize(totalCells);
    for(int index = 0; index < totalCells; index++){
        borders[index].resize(4,true);
    }



}
//when calling kruskals to remove walls
void removeWallBorders(int cell1,int cell2, int cols){
    //row of cell 1
    int r1 = cell1 / cols; 
    //column of cell 1
    int c1 = cell1 % cols;
    //row of cell 2
    int r2 = cell2 / cols; 
    //column of cell 2
    int c2 = cell2 % cols;

    //check if next to eachother (same row)
    if(r1 == r2){
        //cell1 on the right, cell2 on the left
        if(c1 > c2){
            borders[cell1][1] = false;
            borders[cell2][2] = false;

        }
        else{
            borders[cell1][2] = false;
            borders[cell2][1] = false;


        }

    }
    //looking horizontally

    else{
        //cell 1 below, cell 2 above
        if(r1 >r2){
            borders[cell1][0] = false;
            borders[cell2][3] = false;

        }
        else{
            borders[cell1][3] = false;
            borders[cell2][0] = false;

        }

    }


}
void grid(sf::RenderWindow& window){
    //row and cols const for now. will change when ui introduced. defines how many cells.
    //why did i decide to use c++? do i hate myself?
    //ok so algo wil go through and break two walls at a time thats what im thinking.
    const int rows = 50;
    const int cols = 50;
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

//for when we will implement button to make maze generate or not type shit
void button(){

}
