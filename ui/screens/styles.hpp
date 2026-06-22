#ifndef STYLES_HPP
#define STYLES_HPP

#include <SFML/Graphics.hpp>
#include "../ui_structures/Button/Button.hpp"
#include "../ui_structures/PopUp/PopUp.hpp"
#include "../ui_structures/Label/Label.hpp"
#include "../ui_structures/Graph/Node.hpp"
#include "../ui_structures/Textbox/Textbox.hpp"

// Label Styles
inline const LabelStyle titleStyle {
        .textPunto = 50,
        .textColor = sf::Color(237, 98, 28),
        .textStyle = sf::Text::Bold
};

inline const LabelStyle subtitleStyle {
        .textPunto = 30,
        .textColor = sf::Color(237, 98, 28),
        .textStyle = sf::Text::Bold
};

// Button Styles
inline const ButtonStyle defaultButton {
        .backgroundColor = sf::Color::Transparent,
        .outlineColor = sf::Color(237, 98, 28),
        .outlineThickness = 2.0f,
        .textColor = sf::Color(237, 98, 28),
        .textPunto = 30
};

inline const ButtonStyle hoverDefaultButton {
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
        .titleStyle = sf::Text::Style::Bold,

        .descriptionColor = sf::Color(237, 98, 28),
        .descriptionPunto = 30,
        .descriptionStyle = sf::Text::Style::Regular,

        .backgroundColor = sf::Color(0, 0, 0, 200),
        .outlineColor = sf::Color(237, 98, 28),
        .outlineThickness = 2.0f,

        .bgShadeColor = sf::Color(0, 0, 0, 200),

        .defaultStyle = defaultButton,
        .hoverStyle = hoverDefaultButton
};

// Node Styles
inline const NodeStyle defaultNodeStyle {
        .radius = 30.0f,
        .activeColor = sf::Color(237, 98, 28),
        .inactiveColor = sf::Color::Black,
        .activeOutlineColor = sf::Color::Black,
        .inactiveOutlineColor = sf::Color(237, 98, 28),
        .outlineThickness = 2.0f
};

// Textbox Styles
inline const TextboxStyle defaultTextbox {
        .inactivebackgroundColor = sf::Color::Transparent,
        .activeBackgroundColor = sf::Color::Transparent,

        .inactiveOutlineColor = sf::Color(237, 98, 28, 100),
        .activeOutlineColor = sf::Color(237, 98, 28),
        .outlineThickness = 2.0f,

        .inactiveTextColor = sf::Color(237, 98, 28, 100),
        .activeTextColor = sf::Color(237, 98, 28),
        .textPunto = 30
};

#endif