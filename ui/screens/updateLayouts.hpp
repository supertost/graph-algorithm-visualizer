#ifndef UPDATE_LAYOUTS_HPP
#define UPDATE_LAYOUTS_HPP

#include "screens.hpp"
#include "graphEditorElements.hpp"
#include "bfsScreenElements.hpp"
#include "settingsElements.hpp"
#include "menuElements.hpp"

void updateGraphEditorLayout(sf::RenderWindow &window, EditorUIElements &ui);

void updateMenuLayout(sf::RenderWindow &window, MenuUIElements &ui);

void updateSettingsLayout(sf::RenderWindow &window, SettingsUIElements &ui);

void updateBfsLayout(sf::RenderWindow &window, BfsUIElements &ui);

#endif