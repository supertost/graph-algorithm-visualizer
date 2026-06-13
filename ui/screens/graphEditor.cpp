#include "graphEditor.hpp"

#include <iostream>

void updateGraphEditorLayout(sf::RenderWindow &window, Button &exitButton) {

    sf::Vector2u windowSize = window.getSize();

    float windowWidth = static_cast<float>(windowSize.x);
    float windowHeight = static_cast<float>(windowSize.y);

    sf::Vector2f exitButtonSize(windowWidth * 0.10f, windowHeight * 0.05f);
    sf::Vector2f exitButtonPosition(windowWidth - (exitButton.size.x) - (windowWidth * 0.03f), windowHeight * 0.03f);

    exitButton.adjustScaling(exitButtonSize, exitButtonPosition, updateTextScale(window, exitButton.textPunto));


}

Screen displayGraphEditor(sf::RenderWindow &window, sf::Font &font) {

    sf::Vector2u windowSize = window.getSize();

    float windowWidth = static_cast<float>(windowSize.x);
    float windowHeight = static_cast<float>(windowSize.y);

    // Exit Button
    sf::Vector2f buttonSize(windowWidth * 0.10f, windowHeight * 0.05f);
    sf::Vector2f buttonPosition(0.0f, 0.0f);

    Button exitButton(buttonSize, buttonPosition, sf::Color::Transparent, sf::Color::White, 2.0f, "<- Menu", font, 20, sf::Color::White);
    
    Textbox nodeBox(sf::Vector2f(windowWidth * 0.20f, windowHeight * 0.10f), sf::Vector2f(3.0f, 3.0f), font, 30, sf::Color::Transparent, sf::Color::White, 2.0f, sf::Color(255, 255, 255, 150), "Add a node", sf::Color::Transparent, sf::Color(52, 177, 235), sf::Color(52, 177, 235));
    Button addNodeButton(sf::Vector2f(windowWidth * 0.20f, windowHeight * 0.10f), sf::Vector2f(3.0f, 130.0f), sf::Color::Transparent, sf::Color::White, 2.0f, "Add Node", font, 30, sf::Color::White);

    sf::FloatRect visibleArea(0.0f, 0.0f, static_cast<float>(windowWidth), static_cast<float>(windowHeight));
    window.setView(sf::View(visibleArea));
    updateGraphEditorLayout(window, exitButton);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {

            switch (event.type) {

                case sf::Event::Closed:
                    
                    window.close();
                    return Screen::Exit;
                    break;

                case sf::Event::Resized: {
                    
                    sf::FloatRect visibleArea(0.0f, 0.0f, static_cast<float>(event.size.width), static_cast<float>(event.size.height));

                    window.setView(sf::View(visibleArea));
                    updateGraphEditorLayout(window, exitButton);
                    break;
                }

                case sf::Event::KeyPressed:

                    if (event.key.code == sf::Keyboard::Escape)
                        return Screen::Menu;

                    break;

                case sf::Event::MouseButtonPressed:
                    
                    if (event.mouseButton.button == sf::Mouse::Left) {

                        sf::Vector2f mousePositionClick(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));

                        if (exitButton.isClicked(mousePositionClick))
                            return Screen::Menu;

                        // Change this later on
                        if (addNodeButton.isClicked(mousePositionClick)) {
                            int key = std::stoi(nodeBox.getTextContent());

                            std::cout << key << "\n";
                        }
                    }

                    break;
            
                default:
                    break;
            }

            nodeBox.handleEvent(event, window);
        }        

        window.clear(sf::Color::Black);

        sf::Vector2f mousePosition(static_cast<float>(event.mouseMove.x), static_cast<float>(event.mouseMove.y));

        exitButton.drawButton(window);
        exitButton.hoverState(mousePosition, sf::Color::White, sf::Color::Black);

        nodeBox.drawTextbox(window);
        addNodeButton.drawButton(window);
        addNodeButton.hoverState(mousePosition, sf::Color::White, sf::Color::Black);

        window.display();
    }

    return Screen::Menu;
}