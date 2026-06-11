#include "menu.hpp"

Screen displayMenu(sf::RenderWindow &window, sf::Font &font) {

    
    // Title Text
    Label title("Graph Algorithm Visualizer", font, 50, sf::Text::Bold, sf::Color::White, sf::Vector2f(40.0f, 30.f));

    // Graph Edit Button
    sf::Vector2f buttonSize(250.0f, 70.0f);
    sf::Vector2f buttonPosition(640.0f - buttonSize.x / 2.0f, 500.0f);

    Button graphButton(buttonSize, buttonPosition, sf::Color::White, "Graph Editor", font, 30, sf::Color::Black);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {

            switch (event.type) {

                case sf::Event::Closed:
                    
                    window.close();
                    return Screen::Exit;
                    break;

                case sf::Event::KeyPressed:

                    if (event.key.code == sf::Keyboard::Escape) {
                        window.close();
                        return Screen::Exit;
                    }

                    break;

                case sf::Event::MouseButtonPressed:
                    
                    if (event.mouseButton.button == sf::Mouse::Left) {

                        sf::Vector2f mousePosition(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));

                        if (graphButton.isClicked(mousePosition))
                            return Screen::Graph;
                    }

                    break;
            
                default:
                    break;
            }
        }

        window.clear(sf::Color::Black);

        title.drawLabel(window);
        // Graph button
        graphButton.drawButton(window);

        window.display();
    }

    return Screen::Exit;
}