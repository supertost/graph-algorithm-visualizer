#ifndef LABEL_HPP
#define LABEL_HPP

#include <SFML/Graphics.hpp>
#include <string>

struct LabelStyle
{
        unsigned int textPunto = 30;
        sf::Color textColor = sf::Color::Black;
        sf::Text::Style textStyle = sf::Text::Style::Regular;
};

class Label
{
        private:
                sf::Text text;
                LabelStyle style;
        
        public:
                Label(
                        const std::string &text, 
                        const sf::Font &font, 
                        const LabelStyle &style, 
                        sf::Vector2f position
                );
                
                void drawLabel(sf::RenderWindow &window);
                
                // Setters
                void setStyle(const LabelStyle &style);
                void setPosition(sf::Vector2f position);
                void setTextPunto(unsigned int charSize);
                void adjustScaling(sf::Vector2f position, unsigned int charSize);

                // Getters
                const sf::FloatRect getLocalBounds() const;
};


#endif