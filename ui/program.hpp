#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <SFML/Graphics.hpp>

enum class Screen {

    Menu,
    Graph,
    BFS,
    Exit
};

void updateBorderRing(sf::RenderWindow &window, sf::RectangleShape &rectRing);

#endif