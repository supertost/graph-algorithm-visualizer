#ifndef UINODE_HPP
#define UINODE_HPP

#include "SFML/Graphics.hpp"

struct Node {

    int key;
    sf::Vector2f position;
    sf::CircleShape shape;
};

#endif