#include "SFML/Graphics.hpp"
#include "Headers/generator.hpp"
#include <vector>
#include <random>
#include <algorithm>
//using Randomized Kruskals Algo to draw Maze
//need this for button
sf::Color purple(89,20,140);
sf::Color darker_purple(78,17,120);
sf::Color gray(90,96,102);
//sf::RenderWindow window(sf::VideoMode({1005, 805}), "Maze", sf::Style::Titlebar | sf::Style::Close);
//might move later to different file idk
std::vector<std::vector<float>> cells = {};

// {top,left,right,bottom}
std::vector<std::vector<bool>> borders = {};


struct Edge {
    int cell1, cell2;
};




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
    const int rows = 3;
    const int cols = 3;
    wallPopulation(rows,cols);
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
    for(int r = 0; r < rows; r ++){
        for(int c = 0; c < cols; c++){
            int cellIndex = r * cols + c;
            float xPos = c * cellLength;
            float yPos = r * cellWidth;
            cells.push_back({xPos,yPos});

            
            cellRect.setPosition(sf::Vector2f(xPos, yPos));
            window.draw(cellRect);
            if(borders[cellIndex][0]){
                borderTop.setPosition({xPos,yPos});
                window.draw(borderTop);

            }
            if(borders[cellIndex][1]){
                borderLeft.setPosition({xPos,yPos});
                window.draw(borderLeft);

            }
            if(borders[cellIndex][2]){
                borderRight.setPosition({xPos + cellLength,yPos});
                 window.draw(borderRight);

            }
            if(borders[cellIndex][3]){
                borderBottom.setPosition({xPos,yPos + cellWidth});
                window.draw(borderBottom);

            }


        }
    }

}


//to affect number of cells
void scroll_wheel(){

}

void kruskals_algo(){


}
//para checking if mouse on button (0 no  1 yes)
int region_hit(int x, int y, int width, int height,sf::RenderWindow& window){
    if(sf::Mouse::getPosition(window).x < x ||
       sf::Mouse::getPosition(window).y < y ||
       sf::Mouse::getPosition(window).x > x + width ||
        sf::Mouse::getPosition(window).y > y + height){
            return 0;

        }
    return 1;


}
//like in IMGUI but ima be using variables cus SFML aint like that
int hot_item = 0;
int active_item = 0;
int button(int id, int x, int y,sf::RenderWindow& window){
    if(region_hit(x, y, 100, 70, window)){
    hot_item = id;
        if (active_item == 0 && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
            active_item = id;
        }
    }
    sf::RectangleShape button(sf::Vector2f(100,70));
    sf::RectangleShape offset(sf::Vector2f(100,70));

    offset.setFillColor(gray);
    offset.setPosition(sf::Vector2f(x+8,y+8));
    window.draw(offset);
    if(hot_item == id){
        button.setFillColor(purple);
        //on button and pressed
        if(active_item == id){
            button.setFillColor(darker_purple);
            button.setPosition(sf::Vector2f(x+5,y+5));
            window.draw(button);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) == false){
            window.clear();
            grid(window);
            window.draw(offset);
            button.setFillColor(purple);
            button.setPosition(sf::Vector2f(x-2,y-2));
            window.draw(button);
            region_hit(x, y, 100, 70, window);
            }


        }
        else{
            button.setPosition(sf::Vector2f(x,y));
            window.draw(button);

        }
    }
    else{
        button.setFillColor(purple);
        button.setPosition(sf::Vector2f(x,y));
        window.draw(button);

        }
    //is the button active or nah when not pressed
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) == false && 
      hot_item == id && 
      active_item == id){
                return 1;

            }

    return 0;
    }
//for cleanliness
void finish()
{
  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) == false){
    active_item = 0;
  }
  else{
    if (active_item == 0)
      active_item = -1;
  }
}





