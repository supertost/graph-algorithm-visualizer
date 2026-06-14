#include "Textbox.hpp"

Textbox::Textbox(sf::Vector2f size, sf::Vector2f position, const sf::Font &font, unsigned int characterSize, sf::Color textboxColor, sf::Color outlineColor, float outlineThickness, sf::Color textColor) {

    this->shape.setSize(size);
    this->shape.setPosition(position);
    this->shape.setFillColor(textboxColor);
    this->shape.setOutlineColor(outlineColor);
    this->shape.setOutlineThickness(outlineThickness);

    this->text.setFont(font);
    this->text.setCharacterSize(characterSize);
    this->text.setFillColor(textColor);
    this->characterSize = characterSize;

    this->textboxColor = textboxColor;
    this->textColor = textColor;
    this->outlineColor = outlineColor;

    positionText();
}

Textbox::Textbox(sf::Vector2f size, sf::Vector2f position, const sf::Font &font, unsigned int characterSize, sf::Color textboxColor, sf::Color outlineColor, float outlineThickness, sf::Color textColor, std::string placeholder) {

    this->shape.setSize(size);
    this->shape.setPosition(position);
    this->shape.setFillColor(textboxColor);
    this->shape.setOutlineColor(outlineColor);
    this->shape.setOutlineThickness(outlineThickness);

    this->text.setFont(font);
    this->text.setCharacterSize(characterSize);
    this->text.setFillColor(textColor);
    this->characterSize = characterSize;

    this->placeholder = placeholder;
    this->text.setString(placeholder);

    this->textboxColor = textboxColor;
    this->textColor = textColor;
    this->outlineColor = outlineColor;

    positionText();
}

Textbox::Textbox(sf::Vector2f size, sf::Vector2f position, const sf::Font &font, unsigned int characterSize, sf::Color textboxColor, sf::Color outlineColor, float outlineThickness, sf::Color textColor, std::string placeholder, sf::Color activeTextboxColor, sf::Color activeTextColor, sf::Color activeOutlineColor) {

    this->shape.setSize(size);
    this->shape.setPosition(position);
    this->shape.setFillColor(textboxColor);
    this->shape.setOutlineColor(outlineColor);
    this->shape.setOutlineThickness(outlineThickness);

    this->text.setFont(font);
    this->text.setCharacterSize(characterSize);
    this->text.setFillColor(textColor);
    this->characterSize = characterSize;

    this->placeholder = placeholder;
    this->text.setString(placeholder);

    this->textboxColor = textboxColor;
    this->textColor = textColor;
    this->outlineColor = outlineColor;

    this->activeTextboxColor = activeTextboxColor;
    this->activeTextColor = activeTextColor;
    this->activeOutlineColor = activeOutlineColor;

    positionText();
}

void Textbox::positionText() {

    sf::FloatRect buttonBounds = this->shape.getGlobalBounds();
    sf::FloatRect textBounds = this->text.getLocalBounds();

    this->text.setOrigin(textBounds.left, textBounds.top + textBounds.height / 2.0f);
    this->text.setPosition(buttonBounds.left + 10.0f, buttonBounds.top + buttonBounds.height / 2.0f);
}

void Textbox::setSize(sf::Vector2f size) {

    this->shape.setSize(size);
    positionText();
}

void Textbox::setPosition(sf::Vector2f position) {

    this->shape.setPosition(position);
    positionText();
}

void Textbox::setCharacterSize(unsigned int size) {

    this->text.setCharacterSize(size);
    positionText();
}

void Textbox::adjustScaling(sf::Vector2f size, sf::Vector2f position, int charSize) {

    setSize(size);
    setPosition(position);
    setCharacterSize(charSize);
}

void Textbox::drawTextbox(sf::RenderWindow &window) {

    window.draw(this->shape);
    window.draw(this->text);
}


void Textbox::setActive(sf::Color textboxColor, sf::Color outlineColor, sf::Color textColor) {

    if (this->active) {

        this->shape.setFillColor(textboxColor);
        this->shape.setOutlineColor(outlineColor);
        this->text.setFillColor(textColor);
    }

    else {

        this->shape.setFillColor(this->textboxColor);
        this->shape.setOutlineColor(this->outlineColor);
        this->text.setFillColor(this->textColor);
    }
}


void Textbox::handleEvent(const sf::Event &event, const sf::RenderWindow &window, const sf::View &view) {

    switch (event.type) {

        case sf::Event::MouseButtonPressed:
            
            if (event.mouseButton.button == sf::Mouse::Left) {

                sf::Vector2i mousePixel(event.mouseButton.x, event.mouseButton.y);
                sf::Vector2f mousePosition = window.mapPixelToCoords(mousePixel, view);

                this->active = shape.getGlobalBounds().contains(mousePosition);
                setActive(this->activeTextboxColor, this->activeOutlineColor, this->activeTextColor);

                std::string currentText = this->text.getString();

                if (active)
                    if (!currentText.compare(placeholder))
                        this->text.setString("");
                
                if (!active)
                    if (!currentText.compare(""))
                        this->text.setString(placeholder);
            }

            break;

        case sf::Event::TextEntered:

            if (!this->active)
                break;

            if (event.text.unicode == 8) {

                
                if (!input.empty()) {
                    
                    input.pop_back();
                    this->text.setString(input);
                }

                if (input.empty())
                    this->text.setString(this->placeholder);
            }

            else if (this->active && (event.text.unicode >= '0' && event.text.unicode <= '9')) {

                input += static_cast<char>(event.text.unicode);
                this->text.setString(input);
            }

            break;
        
        default:
            break;
    }
}

void Textbox::setOriginCenter() {

    sf::FloatRect bounds = this->shape.getLocalBounds();

    this->shape.setOrigin(bounds.left + bounds.width / 2.0f, bounds.top + bounds.height / 2.0f);
    positionText();
}


// Getters and setters
sf::Color Textbox::getTextboxColor() {

    return this->textboxColor;
}
sf::Color Textbox::getOutlineColor() {

    return this->outlineColor;
}
sf::Color Textbox::getTextColor() {

    return this->textColor;
}
std::string Textbox::getTextContent() {
 
    return this->text.getString();
}

Textbox::~Textbox()
{
}
