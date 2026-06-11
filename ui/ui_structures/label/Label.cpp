#include "Label.hpp"

Label::Label(const std::string &text, const sf::Font &font, int punto, const sf::Text::Style &style, sf::Color color, sf::Vector2f position) {

    this->text.setFont(font);
    this->text.setString(text);
    this->text.setCharacterSize(punto);
    this->text.setStyle(style);
    this->text.setFillColor(color);
    this->text.setPosition(position);
}

void Label::drawLabel(sf::RenderWindow &window) {

    window.draw(this->text);
}

Label::~Label() {

    
}