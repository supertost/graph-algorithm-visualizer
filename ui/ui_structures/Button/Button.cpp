#include "Button.hpp"

Button::Button()
{
}

Button::Button(
                const std::string &buttonText, 
                sf::Vector2f size, 
                sf::Vector2f position, 
                const sf::Font &textFont,
                const ButtonStyle &defaultStyle,
                const ButtonStyle &hoverStyle
        ) : defaultStyle(defaultStyle), hoverStyle(hoverStyle)
{     
        shape.setSize(size);
        shape.setPosition(position);
        
        text.setFont(textFont);
        text.setString(buttonText);

        setStyle(defaultStyle);
}

void Button::setStyle(const ButtonStyle &buttonStyle)
{
        shape.setFillColor(buttonStyle.backgroundColor);
        shape.setOutlineColor(buttonStyle.outlineColor);
        shape.setOutlineThickness(buttonStyle.outlineThickness);

        text.setFillColor(buttonStyle.textColor);
        text.setCharacterSize(buttonStyle.textPunto);

        centerText();
}

void Button::centerText()
{
        const sf::FloatRect buttonBounds = shape.getGlobalBounds();
        const sf::FloatRect textBounds = text.getLocalBounds();

        text.setOrigin(
                textBounds.left + textBounds.width / 2.0f, 
                textBounds.top + textBounds.height / 2.0f
        );

        text.setPosition(
                buttonBounds.left + buttonBounds.width / 2.0f, 
                buttonBounds.top + buttonBounds.height / 2.0f
        );
}

bool Button::isClicked(sf::Vector2f mousePosition) const
{    
        return shape.getGlobalBounds().contains(mousePosition);
}

bool Button::hoverState(sf::Vector2f mousePosition)
{
        bool currentHovered = shape.getGlobalBounds().contains(mousePosition);

        if (currentHovered == hovered)
                return currentHovered;

        hovered = currentHovered;

        if (hovered)
                setStyle(hoverStyle);
        else
                setStyle(defaultStyle);

        return hovered;
}

void Button::drawButton(sf::RenderWindow &window) const
{
        window.draw(shape);
        window.draw(text);
}

// Getters
unsigned int Button::getTextPunto()
{
        return defaultStyle.textPunto;
}

// Setter Functions
void Button::setOriginCenter()
{
        sf::FloatRect bounds = shape.getLocalBounds();
        shape.setOrigin(
                bounds.left + bounds.width / 2.0f, 
                bounds.top + bounds.height / 2.0f
        );
        
        centerText();
}

void Button::setSize(sf::Vector2f size)
{
        shape.setSize(size);
        centerText();
}

void Button::setPosition(sf::Vector2f position)
{
        shape.setPosition(position);
        centerText();
}

void Button::setTextPunto(unsigned int textPunto)
{
        defaultStyle.textPunto = textPunto;
        hoverStyle.textPunto = textPunto;
        text.setCharacterSize(textPunto);
        centerText();
}

void Button::setText(const std::string &newText)
{
        text.setString(newText);
        centerText();
}

void Button::adjustScaling(
                sf::Vector2f size, 
                sf::Vector2f position, 
                unsigned int textPunto
        )
{
        setSize(size);
        setPosition(position);
        setTextPunto(textPunto);
}