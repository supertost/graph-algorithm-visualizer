#include "Label.hpp"

Label::Label(
                const std::string &labelText, 
                const sf::Font &font, 
                LabelStyle &style, 
                sf::Vector2f position
        )
{

        text.setFont(font);
        text.setString(labelText);
        text.setPosition(position);
        
        setStyle(style);
}

void Label::drawLabel(sf::RenderWindow &window)
{
        window.draw(text);
}

// Setters
void Label::setStyle(LabelStyle &newStyle)
{
        style = newStyle;
        text.setCharacterSize(style.textPunto);
        text.setStyle(style.textStyle);
        text.setFillColor(style.textColor);
}

void Label::setPosition(sf::Vector2f position)
{
        text.setPosition(position);
}

void Label::setTextPunto(unsigned int newTextPunto)
{
        style.textPunto = newTextPunto;
        text.setCharacterSize(newTextPunto);
}

void Label::adjustScaling(sf::Vector2f position, unsigned int charSize)
{
        setPosition(position);
        setTextPunto(charSize);
}

// Getters
const sf::FloatRect Label::getLocalBounds() const
{        
        return text.getLocalBounds();
}