#ifndef POPUP_HPP
#define POPUP_HPP

#include <SFML/Graphics.hpp>
#include "../button/Button.hpp"

class PopUp {

    private:
        
        sf::RectangleShape bgShade;
        sf::RectangleShape errorPopUp;

        Button dismissButton;

        sf::Text title;
        sf::Text description;

        void positionPopUpWindow(float windowWidth, float windowHeight);
        void setSizePopUpWindow(float windowWidth, float windowHeight);
        void centerTitle();
        void centerDescription();
        void centerButton();
    public:
        //PopUp(const std::string &title, const std::string &description, const sf::Font &font, unsigned int textPunto, sf::Vector2f size, sf::Color popUpBg, sf::Color popUpOutline, float popUpOutlineThickness, sf::Color errorBgShadeColor);
        PopUp(const std::string &title, const std::string &description, const std::string &buttonText, sf::Color titleColor, sf::Color descriptionColor, sf::Color buttonColorText, const sf::Font &fontBold, const sf::Font &fontLight, unsigned int textPunto, sf::Vector2f size, sf::Color popUpBg, sf::Color popUpOutline, float popUpOutlineThickness, sf::Color errorBgShadeColor, sf::Color buttonBgColor, sf::RenderWindow &window);
        void drawPopUp(sf::RenderWindow &window);
        void adjustScaling();
        bool isDismissed(sf::Vector2f &mousePosition);
        bool dismissHoverState(sf::Vector2f &mousePosition, sf::Color dismissBackgroundColor, sf::Color dismissTextColor);

};

#endif