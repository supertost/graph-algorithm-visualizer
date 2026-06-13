#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include <SFML/Graphics.hpp>
#include <string>

class Textbox {
    
    private:

        sf::Text text;
        std::string placeholder;
        std::string input = "";
        sf::RectangleShape shape;

        bool active = false;

        sf::Color textboxColor;
        sf::Color outlineColor;
        sf::Color textColor;

        unsigned int characterSize;

        void positionText();

    public:
        Textbox(sf::Vector2f size, sf::Vector2f position, const sf::Font &font, unsigned int characterSize, sf::Color textboxColor, sf::Color outlineColor, float outlineThickness, sf::Color textColor);
        Textbox(sf::Vector2f size, sf::Vector2f position, const sf::Font &font, unsigned int characterSize, sf::Color textboxColor, sf::Color outlineColor, float outlineThickness, sf::Color textColor, std::string placeholder);
        ~Textbox();

        void handleEvent(const sf::Event &event, const sf::RenderWindow &window);
        void setActive(sf::Color textboxColor, sf::Color outlineColor, sf::Color textColor);

        void drawTextbox(sf::RenderWindow &window);
};

#endif