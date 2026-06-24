#ifndef UPDATE_LAYOUTS_HPP
#define UPDATE_LAYOUTS_HPP

#include "screens.hpp"
#include "graphEditorElements.hpp"

void updateGraphEditorLayout(sf::RenderWindow &window, EditorUIElements &ui);

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