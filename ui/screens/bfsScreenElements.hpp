#ifndef BFS_ELEMENTS_HPP
#define BFS_ELEMENTS_HPP

#include "bfsScreen.hpp"

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
};

#endif