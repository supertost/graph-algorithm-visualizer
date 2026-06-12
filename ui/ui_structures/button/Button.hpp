#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <string>

class Button {
    private:
        sf::RectangleShape shape;
        sf::Text text;

        void centerText();

    
    public:
        sf::Vector2f size;
        sf::Vector2f position;
        unsigned int textPunto;

        Button(sf::Vector2f size, sf::Vector2f position, sf::Color buttonCol, const std::string &text, const sf::Font &textFont, unsigned int textPunto, sf::Color textColor);
        ~Button();

        void drawButton(sf::RenderWindow &window);
        bool isClicked(sf::Vector2f mousePosition) const;

        // For real time scaling of the program
        void setSize(sf::Vector2f size);
        void setPosition(sf::Vector2f position);
        void setCharacterSize(unsigned int charSize);

        void adjustScaling(sf::Vector2f size, sf::Vector2f position, int charSize);

};


#endif