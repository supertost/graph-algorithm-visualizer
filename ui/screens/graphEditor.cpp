#include "graphEditor.hpp"

Screen displayGraphEditor(sf::RenderWindow &window, sf::Font &font) {

    // Exit Button
    sf::Vector2f buttonSize(100.0f, 35.0f);
    sf::Vector2f buttonPosition(30.0f, 30.0f);

    Button exitButton(buttonSize, buttonPosition, sf::Color::White, "<- Menu", font, 20, sf::Color::Black);


    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {

            switch (event.type) {

                case sf::Event::Closed:
                    
                    window.close();
                    return Screen::Exit;
                    break;

                case sf::Event::KeyPressed:

                    if (event.key.code == sf::Keyboard::Escape)
                        return Screen::Menu;

                    break;

                case sf::Event::MouseButtonPressed:
                    
                    if (event.mouseButton.button == sf::Mouse::Left) {

                        sf::Vector2f mousePosition(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));

                        if (exitButton.isClicked(mousePosition))
                            return Screen::Menu;
                    }

                    break;
            
                default:
                    break;
            }
        }        

        window.clear(sf::Color::Black);

        // Graph button
        exitButton.drawButton(window);

        window.display();
    }

    return Screen::Menu;
}