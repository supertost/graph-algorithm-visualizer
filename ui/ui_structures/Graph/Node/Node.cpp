#include "Node.hpp"

Node::Node(int key, sf::Vector2f position, float radius, sf::Color nodeColorActive, sf::Color nodeColorUnactive, float outlineThickness) {

    this->key = key;
    this->shape.setPosition(position);
    this->shape.setRadius(radius);
    this->shape.setFillColor(nodeColorUnactive);
    this->shape.setOutlineColor(nodeColorActive);
    this->shape.setOutlineThickness(outlineThickness);

    setText(radius);
}

void Node::setText(int radius) {

    this->text.setCharacterSize(radius-4);
}