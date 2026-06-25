#ifndef BFSSCREEN_HPP
#define BFSSCREEN_HPP

#include "screens.hpp"
#include "bfsScreenElements.hpp"

Screen displayBfsScreen(sf::RenderWindow &window, const sf::Font &font, VisualGraph &vgraph, sf::RectangleShape &rectRing);

#endif