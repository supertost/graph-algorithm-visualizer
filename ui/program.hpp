#ifndef PROGRAM_HPP
#define PROGRAM_HPP

enum class Screen {

    Menu,
    Graph,
    BFS,
    Exit
};

void updateBorderRing(sf::RenderWindow &window, sf::RectangleShape &rectRing);

#endif