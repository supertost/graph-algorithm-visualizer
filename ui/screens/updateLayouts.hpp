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

void updateMenuLayout(
        sf::RenderWindow &window,
        Label &title,
        Button &graphButton,
        Button &bfsButton,
        Button &dfsButton,
        Button &settingsButton
);

void updateSettingsLayout(
        sf::RenderWindow &window,
        Button &exitButton,
        Label &title,
        Label &smoothScroll,
        Button &smoothScrollButton,
        Button &saveButton
);

#endif