#include "SFML/Graphics.hpp"
#include "Headers/generator.hpp"
#include <vector>
#include <random>
#include <algorithm>
#include <string>
//using Randomized Kruskals Algo to draw Maze
//need this for button
sf::Color purple(89,20,140);
sf::Color darker_purple(78,17,120);
sf::Color gray(90,96,102);
sf::Color lighter_gray(176,174,172);
sf::Color darker_gray(80,80,80);
//might move later to different file idk
std::vector<std::vector<float>> cells = {};
//dictates number of cells (self explanatory)
int num_of_cells = 2;
// {top,left,right,bottom}
std::vector<std::vector<bool>> borders = {};

//dont worry bout it
int y_thumb = 383;

sf::Text make_text(std::string text){
    static sf::Font font;
    if(!font.openFromFile("PressStart2P-Regular.ttf")){
        // I doubt anything will go wrong...
    }
    sf::Text text_func(font,text,10);
    text_func.setPosition(sf::Vector2f(900,450));
    text_func.setFillColor(sf::Color::White);
    return text_func;
}

struct Edge {
    int cell1, cell2;
};





//here we will truly populate cells with walls. true equals wall should be present. else not
void wallPopulation(){
    int totalCells = num_of_cells * num_of_cells;
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
    const int rows = num_of_cells;
    const int cols = num_of_cells;
    wallPopulation();
    const float cellLength = 800/rows;
    const float cellWidth  = 800/cols;
    
    sf::RectangleShape cellRect(sf::Vector2f(cellLength, cellWidth));
    sf::RectangleShape borderTop(sf::Vector2f(cellLength,5));
    sf::RectangleShape borderBottom(sf::Vector2f(cellLength,5));
    sf::RectangleShape borderLeft(sf::Vector2f(5,cellWidth));
    sf::RectangleShape borderRight(sf::Vector2f(5,cellWidth));
    cellRect.setFillColor(purple);
    borderTop.setFillColor(sf::Color::White);
    borderBottom.setFillColor(sf::Color::White);
    borderLeft.setFillColor(sf::Color::White);
    borderRight.setFillColor(sf::Color::White);
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

void kruskals_algo(){


}
//para checking if mouse on button (0 no  1 yes)
int region_hit(int x, int y, int width, int height, sf::RenderWindow& window){
    if(sf::Mouse::getPosition(window).x < x ||
       sf::Mouse::getPosition(window).y < y ||
       sf::Mouse::getPosition(window).x > x + width ||
        sf::Mouse::getPosition(window).y > y + height){
            return 0;

        }
    return 1;


}
//like in IMGUI but ima be using variables cus SFML aint like that
int hot_item_button = 0;
int active_item_button = 0;
int button(int id, int x, int y,sf::RenderWindow& window){
    if(region_hit(x, y, 100, 70, window)){
    hot_item_button = id;
        if (active_item_button == 0 && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
            active_item_button = id;
        }
    }
    sf::RectangleShape button(sf::Vector2f(100,70));
    sf::RectangleShape offset(sf::Vector2f(100,70));

    offset.setFillColor(gray);
    offset.setPosition(sf::Vector2f(x+8,y+8));
    window.draw(offset);
    if(hot_item_button == id){
        button.setFillColor(purple);
        //on button and pressed
        if(active_item_button == id){
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
        //only on button
        else{
            button.setPosition(sf::Vector2f(x,y));
            window.draw(button);

        }
    }
    //not anything
    else{
        button.setFillColor(purple);
        button.setPosition(sf::Vector2f(x,y));
        window.draw(button);

        }
    //is the button active or nah when not pressed
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) == false && 
      hot_item_button == id && 
      active_item_button == id){
                return 1;

            }

    return 0;
    }

//time to make a slider to dictate how many rows and cols. also will be same number
int hot_item_scroll = 0;
int active_item_scroll = 0;
void scroll(int id, int x, int y, int max, int value,sf::RenderWindow& window){
    int ypos = ((256-16) * value) / max;
    int height = 16;



    if(region_hit(x+8,y_thumb, 16,height,window)){
        height = 255;
        hot_item_scroll = id;
        if(active_item_scroll == 0 && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
            active_item_scroll = id;
        }
    }
    else{
        hot_item_scroll = 0;
    }
    sf::RectangleShape scrollbar(sf::Vector2f(32,256+16));
    scrollbar.setFillColor(gray);
    sf::RectangleShape thumb(sf::Vector2f(16,16));
    thumb.setPosition(sf::Vector2f(x+8,y_thumb));
    scrollbar.setPosition(sf::Vector2f(x,y));
    if(hot_item_scroll == id || active_item_scroll == id){
        thumb.setFillColor(lighter_gray);
    }
    else{
        thumb.setFillColor(darker_gray);

    }
    if(active_item_scroll == id){
        int new_y_thumb = sf::Mouse::getPosition(window).y - 8;
        float current_val = 383;
        if(y_thumb < 375+16){
            y_thumb = 375+8;

        }
        if(y_thumb > 375+255-16){
            y_thumb = 375+255-8;

        }
        float val = 375/100;
        float normalized_pos = (float)(new_y_thumb - 375 - 8) / (255 - 16);
        float new_num_cells = 2 + (int)(normalized_pos * 49);
        if(new_num_cells < 2){
            new_num_cells = 2;
        }
        if (new_num_cells != num_of_cells) {
            num_of_cells = new_num_cells;
            y_thumb = new_y_thumb;
        }
        thumb.setPosition(sf::Vector2f(x+8,y_thumb));

        }
    std::string message = "("+ std::to_string(num_of_cells) + ", " + std::to_string(num_of_cells) + ")"; //message


    window.draw(make_text(message));
    window.draw(scrollbar);
    window.draw(thumb);




}
//for cleanliness
void finish()
{
  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) == false){
    active_item_button = 0;
    active_item_scroll = 0;

  }
  else{
    if (active_item_button == 0)
      active_item_button = -1;
    else if(active_item_scroll == 0){
        active_item_scroll = -1;
    }
  }
}
