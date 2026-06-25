#ifndef POPUP_HPP
#define POPUP_HPP

#include <SFML/Graphics.hpp>
#include "../Button/Button.hpp"

struct PopUpStyle
{
        sf::Color titleColor = sf::Color::Black;
        unsigned int titlePunto = 30;
        sf::Text::Style titleStyle = sf::Text::Style::Bold;
        
        sf::Color descriptionColor = sf::Color::Black;
        unsigned int descriptionPunto = 20;
        sf::Text::Style descriptionStyle = sf::Text::Style::Regular;

        sf::Color backgroundColor = sf::Color::White;
        sf::Color outlineColor = sf::Color::Black;
        float outlineThickness = 2.0f;

        sf::Color bgShadeColor = sf::Color(0, 0, 0, 200);

        ButtonStyle defaultStyle;
        ButtonStyle hoverStyle;
};

class PopUp
{
        private:
        
                sf::RectangleShape bgShade;
                sf::RectangleShape errorPopUp;

                Button dismissButton;

                sf::Text title;
                sf::Text description;

                PopUpStyle style;

                void positionPopUpWindow(float windowWidth, float windowHeight);
                void centerTitle();
                void centerDescription();
                void centerButton();
                void setSizePopUpWindow(float windowWidth, float windowHeight);
                void setStyle(const PopUpStyle &newStyle);
                void setFont(const sf::Font &font);
    public:
                PopUp(
                        const std::string &title, 
                        const std::string &description, 
                        const std::string &buttonText,
                        const sf::Font &font, 
                        sf::Vector2f size,
                        const PopUpStyle &style,
                        sf::RenderWindow &window
                );

                void drawPopUp(sf::RenderWindow &window);
                void adjustScaling();
                bool isDismissed(const sf::Vector2f &mousePosition);
                bool dismissHoverState(const sf::Vector2f &mousePosition);
};

#endif