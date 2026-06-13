#include "Button.hpp"

Button::Button(sf::Vector2f size, sf::Vector2f position, sf::Color buttonCol, const std::string &text, const sf::Font &textFont, unsigned int textPunto, sf::Color textColor) {

    this->size = size;
    this->position = position;
    
    this->buttonColor = buttonCol;
    this->textColor = textColor;

    this->shape.setFillColor(buttonCol);
    this->shape.setSize(size);
    this->shape.setPosition(position);
    
    this->textPunto = textPunto;
    this->text.setFont(textFont);
    this->text.setString(text);
    this->text.setFillColor(textColor);
    this->text.setCharacterSize(textPunto);

    centerText();
}

Button::Button(sf::Vector2f size, sf::Vector2f position, sf::Color buttonCol, sf::Color outlineCol, float outlineThickness, const std::string &text, const sf::Font &textFont, unsigned int textPunto, sf::Color textColor) {

    this->size = size;
    this->position = position;

    this->buttonColor = buttonCol;
    this->textColor = textColor;
    
    this->shape.setFillColor(buttonCol);
    this->shape.setSize(size);
    this->shape.setPosition(position);

    this->shape.setOutlineColor(outlineCol);
    this->shape.setOutlineThickness(outlineThickness);
    
    this->textPunto = textPunto;
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

void Button::hoverState(sf::Vector2f mousePosition, sf::Color backgroundCol, sf::Color textColor) {

    bool currentHovered = this->shape.getGlobalBounds().contains(mousePosition);

    if (currentHovered == this->hovered)
        return;

    this->hovered = currentHovered;

    if (this->hovered) {

        this->shape.setFillColor(backgroundCol);
        this->text.setFillColor(textColor);
    }

    else {
        
        this->shape.setFillColor(this->buttonColor);
        this->text.setFillColor(this->textColor);
    }
}

void Button::clickState(sf::Vector2f mousePosition, sf::Color backgroundCol, sf::Color textColor) {

    bool currentClicked = this->shape.getGlobalBounds().contains(mousePosition);

    if (currentClicked == this->clicked)
        return;

    this->clicked = currentClicked;

    if (this->clicked) {

        this->shape.setFillColor(backgroundCol);
        this->text.setFillColor(textColor);
    }

    else {
        
        this->shape.setFillColor(this->buttonColor);
        this->text.setFillColor(this->textColor);
    }
}


void Button::setSize(sf::Vector2f size) {

    this->size = size;
    this->shape.setSize(size);
    centerText();
}

void Button::setPosition(sf::Vector2f position) {

    this->position = position;
    this->shape.setPosition(position);
    centerText();
}

void Button::setCharacterSize(unsigned int size) {

    this->text.setCharacterSize(size);
    centerText();
}

void Button::adjustScaling(sf::Vector2f size, sf::Vector2f position, int charSize) {

    setSize(size);
    setPosition(position);
    setCharacterSize(charSize);
}

Button::~Button()
{
}