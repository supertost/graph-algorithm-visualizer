#ifndef NODE_HPP
#define NODE_HPP

#include <SFML/Graphics.hpp>

class Node {
    private:
        
        int key;
        float radius;
        sf::Vector2f position;
        sf::Text text;
        sf::CircleShape shape;

        void setText(const sf::Font &font);
        void centerText();

    public:
        Node(int key, sf::Vector2f position, float radius, sf::Color nodeColorActive, sf::Color nodeColorUnactive, float outlineThickness, const sf::Font &font);
        void drawNode(sf::RenderWindow &window) const;
        sf::Vector2f getPosition() const;
};


#endif