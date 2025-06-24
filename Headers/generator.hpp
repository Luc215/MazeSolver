#ifndef MAZEDRAWER_HPP
#define MAZEDRAWER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
//for drawing borders im so tired ngl poooooooo and idrk c++ and am learning it and ts pmo
//coordinate of each border. also 2d list prob.
extern double top;
extern double bottom;
extern double left;
extern double right;
extern std::vector<std::vector<float>> cells;
extern std::vector<std::vector<float>> borders;
void grid(sf::RenderWindow& window);


#endif


