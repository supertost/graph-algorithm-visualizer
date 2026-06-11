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

        Button(sf::Vector2f size, sf::Vector2f position, sf::Color buttonCol, const std::string &text, const sf::Font &textFont, int textPunto, sf::Color textColor);
        ~Button();

        void drawButton(sf::RenderWindow &window);
        bool isClicked(sf::Vector2f mousePosition) const;

};


#endif