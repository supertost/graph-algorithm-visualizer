#include <SFML/Graphics.hpp>

#include "screens/menu.hpp"
#include "screens/graphEditor.hpp"
#include "screens/settings.hpp"
#include "../io/readwrite.hpp"

void updateBorderRing(sf::RenderWindow &window, sf::RectangleShape &rectRing) {

    sf::Vector2u windowSize = window.getSize();

    float windowWidth = static_cast<float>(windowSize.x);
    float windowHeight = static_cast<float>(windowSize.y);

    rectRing.setSize(sf::Vector2f(windowWidth * 0.98f, windowHeight * 0.97f));
    sf::FloatRect rectRingBounds = rectRing.getLocalBounds();

    rectRing.setOrigin(rectRingBounds.left + rectRingBounds.width / 2.0f, rectRingBounds.top + rectRingBounds.height / 2.0f);
    rectRing.setPosition(windowWidth / 2.0f,  windowHeight / 2.0f);
}


int main() {

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Graph Algorithm Visualizer", sf::Style::Default, settings);

    // Setting up font
    sf::Font font;
    if (!font.loadFromFile("ui/fonts/Futura-Heavy.ttf"))
        return EXIT_FAILURE;


    // Background rectangle ring
    sf::RectangleShape rectRing;
    rectRing.setOutlineColor(sf::Color(237, 98, 28));
    rectRing.setOutlineThickness(2.0f);
    rectRing.setFillColor(sf::Color::Transparent);


    // Config settings
    Config config;
    readConfig(config);


    Screen currentScreen = Screen::Menu;


    VisualGraph vgraph(font);

    while (window.isOpen() && currentScreen != Screen::Exit) {

        switch (currentScreen) {
    
            case Screen::Menu:
    
                currentScreen = displayMenu(window, font, rectRing);
                break;


            case Screen::Graph: // For adding nodes into the graph and such

                currentScreen = displayGraphEditor(window, vgraph, font, rectRing, config);
                break;

            
            case Screen::Settings:

                currentScreen = displaySettings(window, font, rectRing, config);
                break;

            default:
                break;   
        }
    }

    return 0;
}