#include "Button.hpp"

Button::Button(sf::Vector2f size, sf::Vector2f position, sf::Color buttonCol, const std::string &text, const sf::Font &textFont, int textPunto, sf::Color textColor) {

    this->size = size;
    this->position = position;
    
    this->shape.setFillColor(buttonCol);
    this->shape.setSize(size);
    this->shape.setPosition(position);
    
    this->text.setFont(textFont);
    this->text.setString(text);
    this->text.setFillColor(textColor);
    this->text.setCharacterSize(textPunto);

    centerText();
}

void Button::centerText() {

    sf::FloatRect buttonBounds = this->shape.getGlobalBounds();
    sf::FloatRect textBounds = this->text.getLocalBounds();

    this->text.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    this->text.setPosition(buttonBounds.left + buttonBounds.width / 2.0f, buttonBounds.top + buttonBounds.height / 2.0f);
}

void Button::drawButton(sf::RenderWindow &window) {

    window.draw(this->shape);
    window.draw(this->text);
}

bool Button::isClicked(sf::Vector2f mousePosition) const {
    
    return shape.getGlobalBounds().contains(mousePosition);
}

Button::~Button()
{
}