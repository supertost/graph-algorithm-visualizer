#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <string>

class Button {
    private:
        sf::RectangleShape shape;
        sf::Text text;
        sf::Color buttonColor;
        sf::Color textColor;
        
        bool hovered = false;
        bool clicked = false;

        void centerText();

    
    public:
        sf::Vector2f size;
        sf::Vector2f position;
        unsigned int textPunto;

        Button(sf::Vector2f size, sf::Vector2f position, sf::Color buttonCol, const std::string &text, const sf::Font &textFont, unsigned int textPunto, sf::Color textColor);
        Button(sf::Vector2f size, sf::Vector2f position, sf::Color buttonCol, sf::Color outlineCol, float outlineThickness, const std::string &text, const sf::Font &textFont, unsigned int textPunto, sf::Color textColor);
        ~Button();

        void drawButton(sf::RenderWindow &window);
        bool isClicked(sf::Vector2f mousePosition) const;
        void hoverState(sf::Vector2f mousePosition, sf::Color backgroundCol, sf::Color textColor);
        void clickState(sf::Vector2f mousePosition, sf::Color backgroundCol, sf::Color textColor);

        // For real time scaling of the program
        void setSize(sf::Vector2f size);
        void setPosition(sf::Vector2f position);
        void setCharacterSize(unsigned int charSize);

        void setOriginCenter();

        void adjustScaling(sf::Vector2f size, sf::Vector2f position, int charSize);

};


#endif