#ifndef LABEL_HPP
#define LABEL_HPP

#include <SFML/Graphics.hpp>
#include <string>

class Label {

    private:
        sf::Text text;

    public:
        Label(const std::string &text, const sf::Font &font, int punto, const sf::Text::Style &style, sf::Color color, sf::Vector2f position);
        ~Label();

        void drawLabel(sf::RenderWindow &window);

        // For Scaling when resizing window
        void setPosition(sf::Vector2f position);
        void setCharacterSize(unsigned int charSize);

        void adjustScaling(sf::Vector2f position, unsigned int charSize);
};


#endif