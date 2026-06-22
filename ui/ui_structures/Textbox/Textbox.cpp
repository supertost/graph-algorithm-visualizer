#include "Textbox.hpp"

Textbox::Textbox(
                sf::Vector2f size,
                sf::Vector2f position,
                const sf::Font &font,
                const std::string &placeholderText,
                const TextboxStyle &style
        )
{
        shape.setSize(size);
        shape.setPosition(position);

        text.setFont(font);
        placeholder = placeholderText;
        text.setString(placeholder);

        setStyle(style);
        baseTextPunto = style.textPunto;

        positionText();
}

void Textbox::setStyle(const TextboxStyle &newStyle)
{
        style = newStyle;
        
        shape.setFillColor(style.inactivebackgroundColor);
        shape.setOutlineColor(style.inactiveOutlineColor);
        shape.setOutlineThickness(style.outlineThickness);

        text.setCharacterSize(style.textPunto);
        text.setFillColor(style.inactiveTextColor);
}

void Textbox::positionText()
{
        sf::FloatRect buttonBounds = shape.getGlobalBounds();
        sf::FloatRect textBounds = text.getLocalBounds();

        text.setOrigin(
                textBounds.left,
                textBounds.top + textBounds.height / 2.0f
        );
        text.setPosition(
                buttonBounds.left + 10.0f,
                buttonBounds.top + buttonBounds.height / 2.0f
        );
}

void Textbox::handleEvent(
                const sf::Event &event,
                const sf::RenderWindow &window,
                const sf::View &view
        )
{
        switch (event.type) {
        
        case sf::Event::MouseButtonPressed:    
                if (event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mousePixel(
                                event.mouseButton.x,
                                event.mouseButton.y
                        );
                        sf::Vector2f mousePosition = window.mapPixelToCoords(
                                mousePixel,
                                view
                        );

                        active = shape.getGlobalBounds().contains(mousePosition);

                        setActive();

                        std::string currentText = text.getString();

                        if (active && !currentText.compare(placeholder))
                                text.setString("");
                
                        if (!active && !currentText.compare(""))
                                text.setString(placeholder);
                }

                break;

        case sf::Event::TextEntered: {

                if (!active)
                        break;

                if (event.text.unicode == 8) {
                        if (input.empty()) {
                                text.setString(placeholder);
                        }
                        else {
                                input.pop_back();
                                text.setString(input);
                        }
                }

                const bool isDigit = event.text.unicode >= '0' && event.text.unicode <= '9';
                const bool allowedSymbols = event.text.unicode == ' ' || event.text.unicode == '-';

                if (active && (isDigit || allowedSymbols)) {
                        input += static_cast<char>(event.text.unicode);
                        text.setString(input);
                }

                break;
        }
        
        default:
            break;
    }
}

void Textbox::drawTextbox(sf::RenderWindow &window) const 
{
        window.draw(shape);
        window.draw(text);
}

// Setters
void Textbox::setActive()
{
        if (active) {
                shape.setFillColor(style.activeBackgroundColor);
                shape.setOutlineColor(style.activeOutlineColor);
                text.setFillColor(style.activeTextColor);
        }
        else {
                shape.setFillColor(style.inactivebackgroundColor);
                shape.setOutlineColor(style.inactiveOutlineColor);
                text.setFillColor(style.inactiveTextColor);
        }
}

void Textbox::setSize(sf::Vector2f newSize)
{
        shape.setSize(newSize);
        positionText();
}

void Textbox::setPosition(sf::Vector2f newPosition)
{
        shape.setPosition(newPosition);
        positionText();
}

void Textbox::setTextPunto(unsigned int newTextPunto)
{
        style.textPunto = newTextPunto;
        text.setCharacterSize(newTextPunto);
        positionText();
}

void Textbox::adjustScaling(sf::Vector2f size, sf::Vector2f position, int charSize)
{
        setSize(size);
        setPosition(position);
        setTextPunto(charSize);
}

void Textbox::setOriginCenter()
{
        sf::FloatRect bounds = shape.getLocalBounds();

        shape.setOrigin(
                bounds.left + bounds.width / 2.0f,
                bounds.top + bounds.height / 2.0f
        );
        positionText();
}

// Getters
unsigned int Textbox::getTextPunto() const
{
        return style.textPunto;
}
unsigned int Textbox::getBaseTextPunto() const
{
        return baseTextPunto;
}

std::string Textbox::getTextContent() const
{
        return text.getString();
}

bool Textbox::getActive() const
{
        return active;
}