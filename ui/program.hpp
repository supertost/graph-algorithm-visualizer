#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <SFML/Graphics.hpp>

enum class Screen {

    Menu,
    Graph,
    BFS,
    Settings,
    Exit
};

struct Config {

    int smoothScroll = 0; // 1 for on, 0 for off
    std::string filepath = "config/config.txt";
};

void updateBorderRing(sf::RenderWindow &window, sf::RectangleShape &rectRing);

#endif