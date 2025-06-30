#ifndef MAZEDRAWER_HPP
#define MAZEDRAWER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
extern sf::Color purple;
extern sf::Color gray;
extern sf::Color darker_purple;
//for drawing borders im so tired ngl poooooooo and idrk c++ and am learning it and ts pmo
//coordinate of each border. also 2d list prob.
extern double top;
extern double bottom;
extern double left;
extern double right;
extern std::vector<std::vector<float>> cells;
extern std::vector<std::vector<bool>> borders;
extern void grid(sf::RenderWindow& window);
extern int region_hit(int x, int y, int width, int height,sf::RenderWindow& window);
extern int button(int id, int x, int y,sf::RenderWindow& window);
extern void finish();


#endif


