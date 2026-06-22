#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <string>

struct ButtonStyle
{
        sf::Color backgroundColor = sf::Color::White;
        sf::Color outlineColor = sf::Color::Black;
        float outlineThickness = 2.0f;
        sf::Color textColor = sf::Color::Black;
        unsigned int textPunto = 30;
};

class Button
{
        private:
                sf::RectangleShape shape;
                sf::Text text;

                ButtonStyle defaultStyle;
                ButtonStyle hoverStyle;
                
                bool hovered = false;

                void centerText();
                void setStyle(const ButtonStyle &buttonStyle);

        public:
                Button();
                Button(
                        const std::string &buttonText, 
                        sf::Vector2f size, 
                        sf::Vector2f position, 
                        const sf::Font &textFont,
                        const ButtonStyle &defaultStyle,
                        const ButtonStyle &hoverStyle
                );

                        
                bool isClicked(sf::Vector2f mousePosition) const;
                bool hoverState(sf::Vector2f mousePosition);
                        
                // For real time scaling of the program
                void setSize(sf::Vector2f size);
                void setPosition(sf::Vector2f position);
                void setCharacterSize(unsigned int textPunto);
                        
                void setOriginCenter();
                        
                void adjustScaling(
                        sf::Vector2f size, 
                        sf::Vector2f position, 
                        unsigned int textPunto
                );
                        
                void setText(const std::string &newText);

                void drawButton(sf::RenderWindow &window) const;
};

#endif