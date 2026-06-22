#ifndef NODE_HPP
#define NODE_HPP

#include <SFML/Graphics.hpp>

struct NodeStyle
{
        float radius = 30.0f;
        sf::Color activeColor = sf::Color::Black;
        sf::Color inactiveColor = sf::Color::White;
        sf::Color activeOutlineColor = sf::Color::White;
        sf::Color inactiveOutlineColor = sf::Color::Black;
        float outlineThickness = 2.0f;
};

class Node
{
        private:
                int key;
                bool active = false;
                sf::Vector2f position;
                float radius;

                sf::Text text;
                sf::CircleShape shape;

                void setText(const sf::Font &font);
                void centerText();
                
                public:
                Node(        
                        int key,
                        sf::Vector2f position,
                        const NodeStyle &style,
                        const sf::Font &font
                );
                
                void drawNode(sf::RenderWindow &window) const;
                
                // Getters
                sf::Vector2f getPosition() const;
                const sf::FloatRect getGlobalBounds() const;
                
                // Setters
                void setStyle(const NodeStyle &newStyle);
                void setPosition(sf::Vector2f position);
};


#endif