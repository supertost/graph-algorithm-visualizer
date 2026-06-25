#include "Node.hpp"

Node::Node(
                int nodeKey,
                sf::Vector2f nodePosition,
                const NodeStyle &style,
                const sf::Font &font
        )
{
        key = nodeKey;

        setStyle(style);
        shape.setPosition(nodePosition);
        position = nodePosition;

        setText(font);
}

void Node::setStyle(const NodeStyle &newStyle)
{
        radius = newStyle.radius;
        
        shape.setRadius(radius);
        shape.setOrigin(radius, radius);
        shape.setFillColor(newStyle.inactiveColor);
        shape.setOutlineColor(newStyle.inactiveOutlineColor);
        shape.setOutlineThickness(newStyle.outlineThickness);

        if (active)
                text.setFillColor(newStyle.inactiveColor);
        else
                text.setFillColor(newStyle.activeColor);
}

void Node::setText(const sf::Font &font)
{
        text.setFont(font);
        text.setString(std::to_string(key));
        text.setCharacterSize(radius);
        centerText();
}

void Node::centerText()
{
        sf::FloatRect textBounds = text.getLocalBounds();

        text.setOrigin(
                textBounds.left + textBounds.width / 2.0f,
                textBounds.top + textBounds.height / 2.0f
        );
        text.setPosition(shape.getPosition());
}

void Node::drawNode(sf::RenderWindow &window) const
{
        window.draw(shape);
        window.draw(text);
}

// Getters

sf::Vector2f Node::getPosition() const
{
        return position;
}

sf::FloatRect Node::getGlobalBounds() const
{
        return shape.getGlobalBounds();
}


// Setters

void Node::setPosition(sf::Vector2f newPosition)
{
        position = newPosition;
        shape.setPosition(position);
        centerText();
}