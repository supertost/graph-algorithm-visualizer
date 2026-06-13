#include "textScale.hpp"

unsigned int updateTextScale(sf::RenderWindow &window, unsigned int size) {

    sf::Vector2u windowSize = window.getSize();

    float scaleX = static_cast<float>(windowSize.x) / 1280.0f;
    float scaleY = static_cast<float>(windowSize.y) / 720.0f;

    float scale = std::min(scaleX, scaleY);

    return static_cast<unsigned int>(size * scale);
}