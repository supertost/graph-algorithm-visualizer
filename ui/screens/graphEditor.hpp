#ifndef GRAPHEDITOR_HPP
#define GRAPHEDITOR_HPP

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <string>

#include "screens.hpp"

Screen displayGraphEditor(sf::RenderWindow &window, VisualGraph &vgraph, sf::Font &font, sf::RectangleShape &rectRing);

#endif