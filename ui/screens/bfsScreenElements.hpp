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

        Textbox startNodeBox;
        Textbox destNodeBox;

        BfsUIElements(const sf::Font &font)
                :
                playpause(
                        "Start",
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
                ),
                startNodeBox(
                        sf::Vector2f(0.0f, 0.0f),
                        sf::Vector2f(3.0f, 3.0f),
                        font,
                        "Start Node",
                        defaultTextbox
                ),
                destNodeBox(
                        sf::Vector2f(0.0f, 0.0f),
                        sf::Vector2f(3.0f, 3.0f),
                        font,
                        "Destination Node",
                        defaultTextbox
                )
        {
                playpause.setOriginCenter();
                skipOneIteration.setOriginCenter();
        }

        void drawUI(sf::RenderWindow &window)
        {
                playpause.drawButton(window);
                startNodeBox.drawTextbox(window);
                destNodeBox.drawTextbox(window);
        }

        bool hoverCheck(sf::Vector2f mousePosition)
        {
                bool playpauseHover = playpause.hoverState(mousePosition);

                if (playpauseHover)
                        return true;

                return false;
        }
};

// Play Pause ikonu için sfml şekilleri ile struct ile bir şeyler yapabilirim


#endif