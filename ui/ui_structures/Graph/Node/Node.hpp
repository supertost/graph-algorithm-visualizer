#ifndef NODE_HPP
#define NODE_HPP

#include <SFML/Graphics.hpp>

class Node {
    private:
        
        int key;
        sf::Text text;
        sf::CircleShape shape;

        void setText(int radius);

    public:
        Node(int key, sf::Vector2f position, float radius, sf::Color nodeColorActive, sf::Color nodeColorUnactive, float outlineThickness);
};


#endif