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


void Label::setPosition(sf::Vector2f position) {

    this->text.setPosition(position);
}

void Label::setCharacterSize(unsigned int charSize) {

    this->text.setCharacterSize(charSize);
}

void Label::adjustScaling(sf::Vector2f position, unsigned int charSize) {

    setPosition(position);
    setCharacterSize(charSize);
}

const sf::FloatRect Label::getLocalBounds() const {

    return this->text.getLocalBounds();
}

Label::~Label() {


}