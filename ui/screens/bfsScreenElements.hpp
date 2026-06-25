#ifndef BFS_ELEMENTS_HPP
#define BFS_ELEMENTS_HPP

#include "bfsScreen.hpp"

struct BfsViews
{
        sf::View graphView;
        sf::View uiView;
        sf::View borderView;
};

struct BfsUIElements
{
        Button playpause;
        Button skipOneIteration;
        Button stepForward;
        Button stepBack;
        Button stepBackOneIteration;

        Button exitButton;

        BfsUIElements(const sf::Font &font)
                :
                playpause(
                        "Play",
                        sf::Vector2f(0.0f, 0.0f),
                        sf::Vector2f(0.0f, 0.0f),
                        font,
                        defaultButton,
                        hoverDefaultButton
                ),
                skipOneIteration(
                        "Skip",
                        sf::Vector2f(0.0f, 0.0f),
                        sf::Vector2f(0.0f, 0.0f),
                        font,
                        defaultButton,
                        hoverDefaultButton
                ),
                exitButton(
                        "<- Menu",
                        sf::Vector2f(0.0f, 0.0f),
                        sf::Vector2f(0.0f, 0.0f),
                        font,
                        compactButton,
                        hoverCompactButton
                )
        {
                playpause.setOriginCenter();
                skipOneIteration.setOriginCenter();
        }

        void drawUI(sf::RenderWindow &window)
        {
                playpause.drawButton(window);
        }
};


#endif