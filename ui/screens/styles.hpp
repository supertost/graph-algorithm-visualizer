#ifndef STYLES_HPP
#define STYLES_HPP

#include <SFML/Graphics.hpp>
#include "../ui_structures/Button/Button.hpp"

ButtonStyle normalButton {
        .backgroundColor = sf::Color::Transparent,
        .outlineColor = sf::Color(237, 98, 28),
        .outlineThickness = 2.0f,
        .textColor = sf::Color(237, 98, 28),
        .textPunto = 30
};

ButtonStyle hoverNormalButton {
        .backgroundColor = sf::Color(237, 98, 28),
        .outlineColor = sf::Color(237, 98, 28),
        .outlineThickness = 2.0f,
        .textColor = sf::Color::Black,
        .textPunto = 30
};

ButtonStyle compactButton {
        .backgroundColor = sf::Color::Transparent,
        .outlineColor = sf::Color(237, 98, 28),
        .outlineThickness = 2.0f,
        .textColor = sf::Color(237, 98, 28),
        .textPunto = 20
};

ButtonStyle hoverCompactButton {
        .backgroundColor = sf::Color(237, 98, 28),
        .outlineColor = sf::Color(237, 98, 28),
        .outlineThickness = 2.0f,
        .textColor = sf::Color::Black,
        .textPunto = 20
};

#endif