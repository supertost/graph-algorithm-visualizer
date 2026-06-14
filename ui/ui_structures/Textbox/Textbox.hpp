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

        sf::Color activeTextboxColor = sf::Color::Black;
        sf::Color activeTextColor = sf::Color::Blue;
        sf::Color activeOutlineColor = sf::Color::Blue;

        bool active = false;

        sf::Color textboxColor;
        sf::Color outlineColor;
        sf::Color textColor;

        void positionText();

    public:
        // UPDATE FUNCTIONS FOR ALL CONSTRUCTOR TYPES
        Textbox(sf::Vector2f size, sf::Vector2f position, const sf::Font &font, unsigned int characterSize, sf::Color textboxColor, sf::Color outlineColor, float outlineThickness, sf::Color textColor);
        Textbox(sf::Vector2f size, sf::Vector2f position, const sf::Font &font, unsigned int characterSize, sf::Color textboxColor, sf::Color outlineColor, float outlineThickness, sf::Color textColor, std::string placeholder);
        Textbox(sf::Vector2f size, sf::Vector2f position, const sf::Font &font, unsigned int characterSize, sf::Color textboxColor, sf::Color outlineColor, float outlineThickness, sf::Color textColor, std::string placeholder, sf::Color activeTextboxColor, sf::Color activeTextColor, sf::Color activeOutlineColor);
        ~Textbox();

        void handleEvent(const sf::Event &event, const sf::RenderWindow &window, const sf::View &view);
        void setActive(sf::Color textboxColor, sf::Color outlineColor, sf::Color textColor);

        void setSize(sf::Vector2f size);
        void setPosition(sf::Vector2f position);
        void setCharacterSize(unsigned int size);
        void adjustScaling(sf::Vector2f size, sf::Vector2f position, int charSize);

        void drawTextbox(sf::RenderWindow &window);

        void setOriginCenter();

        // Getters
        sf::Color getTextboxColor();
        sf::Color getOutlineColor();
        sf::Color getTextColor();
        std::string getTextContent();

        unsigned int characterSize;
};

#endif