#include "Node.hpp"

Node::Node(int key, sf::Vector2f position, float radius, sf::Color nodeColorActive, sf::Color nodeColorUnactive, float outlineThickness, const sf::Font &font) {

    this->key = key;
    this->radius = radius;
    this->shape.setRadius(radius);
    this->shape.setOrigin(radius, radius);
    this->shape.setPosition(position);
    this->shape.setFillColor(nodeColorUnactive);
    this->shape.setOutlineColor(nodeColorActive);
    this->shape.setOutlineThickness(outlineThickness);

    this->position = position;

    setText(font);
}

void Node::setText(const sf::Font &font) {

    this->text.setFont(font);
    this->text.setString(std::to_string(this->key));
    this->text.setTextPunto(this->radius);
    this->text.setFillColor(sf::Color(237, 98, 28));
    centerText();
}

void Node::centerText() {

    sf::FloatRect textBounds = this->text.getLocalBounds();

    this->text.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    this->text.setPosition(this->shape.getPosition());
}

void Node::drawNode(sf::RenderWindow &window) const {

    window.draw(this->shape);
    window.draw(this->text);
}

// Getters

sf::Vector2f Node::getPosition() const {

    return this->position;
}

const sf::FloatRect Node::getGlobalBounds() const {

    return this->shape.getGlobalBounds();
}


// Setters

void Node::setPosition(sf::Vector2f position) {

    this->position = position;
    this->shape.setPosition(position);
    centerText();
}