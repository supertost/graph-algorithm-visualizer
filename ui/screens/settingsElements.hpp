#ifndef SETTINGS_ELEMENTS_HPP
#define SETTINGS_ELEMENTS_HPP

#include "screens.hpp"
#include "styles.hpp"

struct SettingsUIElements
{
        Label title;
        Button exitButton;
        Label smoothScroll;
        Button smoothScrollButton;
        Button saveButton;

        SettingsUIElements(const sf::Font &font, const std::string &smoothState)
                :
                title(
                        "Settings",
                        font,
                        titleStyle,
                        sf::Vector2f(40.0f, 30.f)
                ),
                exitButton(
                        "<- Menu", 
                        sf::Vector2f(0.0f, 0.0f),
                        sf::Vector2f(0.0f, 0.0f),
                        font,
                        compactButton,
                        hoverCompactButton
                ),
                smoothScroll(
                        "Smooth Scroll",
                        font,
                        subtitleStyle,
                        sf::Vector2f(0.0f, 0.0f)
                ),
                smoothScrollButton(
                        smoothState,
                        sf::Vector2f(0.0f, 0.0f),
                        sf::Vector2f(0.0f, 0.0f),
                        font,
                        compactButton,
                        hoverCompactButton
                ),
                saveButton(
                        "Save",
                        sf::Vector2f(0.0f, 0.0f),
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

                smoothScroll.drawLabel(window);
                smoothScrollButton.drawButton(window);
                
                exitButton.drawButton(window);
                saveButton.drawButton(window);
        }

        bool checkHover(sf::Vector2f mousePosition)
        {
                bool smoothScrollHover = smoothScrollButton.hoverState(mousePosition);
                bool exitHover = exitButton.hoverState(mousePosition);
                bool saveHover = saveButton.hoverState(mousePosition);

                if (exitHover || smoothScrollHover || saveHover)
                        return true;

                return false;
        }
};


#endif