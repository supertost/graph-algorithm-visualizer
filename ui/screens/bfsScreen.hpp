#ifndef BFSSCREEN_HPP
#define BFSSCREEN_HPP

#include "screens.hpp"
#include "bfsScreenElements.hpp"

#include <vector>
#include <unordered_set>
#include <queue>

struct BfsStuffTest
{
        std::vector<int> traversal;
        std::unordered_set<int> visited;
        std::queue<int> queue;
        int lastNode;
        bool firstIteration;
        bool play;
        bool quit;
};

Screen displayBfsScreen(sf::RenderWindow &window, const sf::Font &font, VisualGraph vgraph, sf::RectangleShape &rectRing);

#endif