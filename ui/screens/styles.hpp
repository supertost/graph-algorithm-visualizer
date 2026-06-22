#ifndef STYLES_HPP
#define STYLES_HPP

#include <SFML/Graphics.hpp>
#include "../ui_structures/Button/Button.hpp"
#include "../ui_structures/PopUp/PopUp.hpp"
#include "../ui_structures/Label/Label.hpp"

// Label Styles
inline const LabelStyle titleStyle {
        .textPunto = 50,
        .textColor = sf::Color(237, 98, 28),
        .textStyle = sf::Text::Bold
};

inline const LabelStyle subTitleStyle {
        .textPunto = 30,
        .textColor = sf::Color(237, 98, 28),
        .textStyle = sf::Text::Bold
};

// Button Styles
inline const ButtonStyle normalButton {
        .backgroundColor = sf::Color::Transparent,
        .outlineColor = sf::Color(237, 98, 28),
        .outlineThickness = 2.0f,
        .textColor = sf::Color(237, 98, 28),
        .textPunto = 30
};

inline const ButtonStyle hoverNormalButton {
        .backgroundColor = sf::Color(237, 98, 28),
        .outlineColor = sf::Color(237, 98, 28),
        .outlineThickness = 2.0f,
        .textColor = sf::Color::Black,
        .textPunto = 30
};

inline const ButtonStyle compactButton {
        .backgroundColor = sf::Color::Transparent,
        .outlineColor = sf::Color(237, 98, 28),
        .outlineThickness = 2.0f,
        .textColor = sf::Color(237, 98, 28),
        .textPunto = 20
};

inline const ButtonStyle hoverCompactButton {
        .backgroundColor = sf::Color(237, 98, 28),
        .outlineColor = sf::Color(237, 98, 28),
        .outlineThickness = 2.0f,
        .textColor = sf::Color::Black,
        .textPunto = 20
};

// PopUp Styles
inline const PopUpStyle popUpDefault {
        .titleColor = sf::Color(237, 98, 28),
        .titlePunto = 30,
        .descriptionColor = sf::Color(237, 98, 28),
        .descriptionPunto = 30,

        .backgroundColor = sf::Color(0, 0, 0, 200),
        .outlineColor = sf::Color(237, 98, 28),
        .outlineThickness = 2.0f,

        .bgShadeColor = sf::Color(237, 98, 28),

        .defaultStyle = normalButton,
        .hoverStyle = hoverNormalButton
};

#endif