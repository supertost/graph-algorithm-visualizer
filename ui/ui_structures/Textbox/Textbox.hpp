#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include <SFML/Graphics.hpp>
#include <string>

struct TextboxStyle
{
        sf::Color inactivebackgroundColor = sf::Color(255, 255, 255, 200);
        sf::Color activeBackgroundColor = sf::Color::White;
        
        sf::Color inactiveOutlineColor = sf::Color(0, 0, 0, 200);
        sf::Color activeOutlineColor = sf::Color::Black;
        float outlineThickness = 2.0f;
        
        sf::Color inactiveTextColor = sf::Color (0, 0, 0, 200);
        sf::Color activeTextColor = sf::Color::Black;
        unsigned int textPunto = 30.0f;
};

class Textbox
{
        private:
                sf::Text text;
                sf::RectangleShape shape;

                std::string input = "";
                std::string placeholder;

                TextboxStyle style;

                bool active = false;
                unsigned int baseTextPunto;

                void setStyle(const TextboxStyle &newStyle);
                void positionText();

        public:
                Textbox(
                        sf::Vector2f size,
                        sf::Vector2f position,
                        const sf::Font &font,
                        const std::string &placeholder,
                        const TextboxStyle &style
                );

                void handleEvent(
                        const sf::Event &event,
                        const sf::RenderWindow &window,
                        const sf::View &view
                );

                void drawTextbox(sf::RenderWindow &window) const;
                
                // Setters
                void setActive();
                void setSize(sf::Vector2f size);
                void setPosition(sf::Vector2f position);
                void setTextPunto(unsigned int size);
                void adjustScaling(sf::Vector2f size, sf::Vector2f position, int charSize);
                void setOriginCenter();

                // Getters
                unsigned int getTextPunto() const;
                unsigned int getBaseTextPunto() const;
                std::string getTextContent() const;
                bool getActive() const;
};

#endif