#ifndef MENU_ELEMENTS_HPP
#define MENU_ELEMENTS_HPP

#include "screens.hpp"
#include "styles.hpp"

struct MenuUIElements
{
        Label title;
        Button graphButton;
        Button bfsButton;
        Button dfsButton;
        Button settingsButton;

        MenuUIElements(const sf::Font &font)
                :
                title(
                        "Graph Algorithm Visualizer",
                        font,
                        titleStyle,
                        sf::Vector2f(40.0f, 30.f)
                ),
                graphButton(
                        "Graph Editor",
                        sf::Vector2f(250.0f, 70.0f),
                        sf::Vector2f(0.0f, 0.0f),
                        font,
                        defaultButton,
                        hoverDefaultButton
                ),
                bfsButton(
                        "Run BFS",
                        sf::Vector2f(250.0f, 70.0f),
                        sf::Vector2f(0.0f, 0.0f),
                        font,
                        defaultButton,
                        hoverDefaultButton
                ),
                dfsButton(
                        "Run DFS",
                        sf::Vector2f(250.0f, 70.0f),
                        sf::Vector2f(0.0f, 0.0f),
                        font,
                        defaultButton,
                        hoverDefaultButton
                ),
                settingsButton(
                        "Settings",
                        sf::Vector2f(250.0f, 70.0f),
                        sf::Vector2f(0.0f, 0.0f),
                        font,
                        defaultButton,
                        hoverDefaultButton
                )
        {

        }

        void drawUI(sf::RenderWindow &window)
        {
                title.drawLabel(window);
                graphButton.drawButton(window);
                bfsButton.drawButton(window);
                dfsButton.drawButton(window);
                settingsButton.drawButton(window);
        }

        bool hoverCheck(sf::Vector2f mousePosition)
        {
                bool graphEditorHover = graphButton.hoverState(mousePosition);
                bool bfsHover = bfsButton.hoverState(mousePosition);
                bool dfsHover = dfsButton.hoverState(mousePosition);
                bool settingsHover = settingsButton.hoverState(mousePosition);

                if (graphEditorHover || bfsHover || dfsHover || settingsHover)
                        return true;

                return false;
        }
};


#endif