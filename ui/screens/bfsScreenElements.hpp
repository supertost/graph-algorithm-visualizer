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
        Button runButton;
        Button playPauseButton;
        Button skipOneButton;
        Button showTraversalButton;
        Button stepForward;
        Button stepBack;
        Button stepBackOneIteration;
        Button changeSecondsButton;

        Button exitButton;

        Textbox startNodeBox;
        Textbox destNodeBox;
        Textbox waitSecondBox;

        BfsUIElements(const sf::Font &font)
                :
                runButton(
                        "Run",
                        sf::Vector2f(0.0f, 0.0f),
                        sf::Vector2f(0.0f, 0.0f),
                        font,
                        defaultButton,
                        hoverDefaultButton
                ),
                playPauseButton(
                        "Play",
                        sf::Vector2f(0.0f, 0.0f),
                        sf::Vector2f(0.0f, 0.0f),
                        font,
                        defaultButton,
                        hoverDefaultButton
                ),
                skipOneButton(
                        "Skip",
                        sf::Vector2f(0.0f, 0.0f),
                        sf::Vector2f(0.0f, 0.0f),
                        font,
                        defaultButton,
                        hoverDefaultButton
                ),
                showTraversalButton(
                        "Traversal",
                        sf::Vector2f(0.0f, 0.0f),
                        sf::Vector2f(0.0f, 0.0f),
                        font,
                        defaultButton,
                        hoverDefaultButton
                ),
                changeSecondsButton(
                        "Change Wait Seconds",
                        sf::Vector2f(0.0f, 0.0f),
                        sf::Vector2f(0.0f, 0.0f),
                        font,
                        compactButton,
                        hoverCompactButton
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
                ),
                waitSecondBox(
                        sf::Vector2f(0.0f, 0.0f),
                        sf::Vector2f(3.0f, 3.0f),
                        font,
                        "Seconds",
                        defaultTextbox
                )
        {
                runButton.setOriginCenter();
                skipOneButton.setOriginCenter();
        }

        void drawUI(sf::RenderWindow &window)
        {
                runButton.drawButton(window);
                playPauseButton.drawButton(window);
                skipOneButton.drawButton(window);
                changeSecondsButton.drawButton(window);

                startNodeBox.drawTextbox(window);
                waitSecondBox.drawTextbox(window);
        }

        bool hoverCheck(sf::Vector2f mousePosition)
        {
                bool runButtonHover = runButton.hoverState(mousePosition);
                bool skipOneButtonHover = skipOneButton.hoverState(mousePosition);
                bool playPauseButtonHover = playPauseButton.hoverState(mousePosition);
                bool changeSecondsHover = changeSecondsButton.hoverState(mousePosition);

                if (runButtonHover 
                        || skipOneButtonHover
                        || playPauseButtonHover
                        || changeSecondsHover
                )
                        return true;

                return false;
        }
};

struct BfsPopUps
{
        PopUp traversal;

        /*BfsPopUps(const sf::Font &font, sf::RenderWindow &window)
        {

        }*/
};

// Play Pause ikonu için sfml şekilleri ile struct ile bir şeyler yapabilirim


#endif