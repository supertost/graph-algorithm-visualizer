#ifndef UPDATE_LAYOUTS_HPP
#define UPDATE_LAYOUTS_HPP

#include "screens.hpp"

void updateGraphEditorLayout(
        sf::RenderWindow &window, 
        Button &exitButton, 
        Textbox &nodeBox, 
        Button &addNodeButton, 
        Textbox &edgeBox, 
        Button &addEdgeButton, 
        sf::RectangleShape &uibg, 
        Button &clearGraphButton, 
        Button &loadGraphButton, 
        Button &saveGraphButton, 
        Button &centerGraphButton
);

#endif