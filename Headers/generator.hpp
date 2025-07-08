#ifndef MAZEDRAWER_HPP
#define MAZEDRAWER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
extern sf::Color purple;
extern sf::Color gray;
extern sf::Color darker_purple;
extern sf::Color lighter_gray;
extern sf::Color darker_gray;
//for drawing borders im so tired ngl poooooooo and idrk c++ and am learning it and ts pmo
//coordinate of each border. also 2d list prob.
extern double top;
extern double bottom;
extern double left;
extern double right;
extern int num_of_cells;
extern sf::Font font;
extern std::vector<std::vector<float>> cells;
extern std::vector<std::vector<bool>> borders;
extern void grid(sf::RenderWindow& window);
extern int region_hit(int x, int y, int width, int height,sf::RenderWindow& window);
extern int button(int id, int x, int y,sf::RenderWindow& window);
extern void finish();
extern void scroll(int id, int x, int y, int max, int value,sf::RenderWindow& window);

#endif


