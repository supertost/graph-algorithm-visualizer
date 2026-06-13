#include "menu.hpp"

void updateMenuLayout(sf::RenderWindow &window, Label &title, Button &graphButton, Button &bfsButton, Button &dfsButton) {

    sf::Vector2u windowSize = window.getSize();

    float windowWidth = static_cast<float>(windowSize.x);
    float windowHeight = static_cast<float>(windowSize.y);

    // Title text
    title.setCharacterSize(updateTextScale(window, 50));
    title.setPosition(sf::Vector2f(windowWidth * 0.03f, windowHeight * 0.03f));

    // Menu nav buttons
    sf::Vector2f navButtonSize(windowWidth * 0.20f, windowHeight * 0.10f);

    
    // Menu nav buttons positions
    sf::Vector2f graphEditorPosition(windowWidth * 0.03f, windowHeight * 0.2f);
    sf::Vector2f BFSPosition(windowWidth * 0.03f, windowHeight * 0.2f + navButtonSize.y * 1.0f + windowHeight * 0.04f * 1.0f);
    sf::Vector2f DFSPosition(windowWidth * 0.03f, windowHeight * 0.2f + navButtonSize.y * 2.0f + windowHeight * 0.04f * 2.0f);


    //sf::Vector2f navButtonPosition(windowWidth * 0.5f - navButtonSize.x / 2.0f, windowHeight * 0.70f);

    graphButton.adjustScaling(navButtonSize, graphEditorPosition, updateTextScale(window, graphButton.textPunto));
    bfsButton.adjustScaling(navButtonSize, BFSPosition, updateTextScale(window, bfsButton.textPunto));
    dfsButton.adjustScaling(navButtonSize, DFSPosition, updateTextScale(window, dfsButton.textPunto));
}


Screen displayMenu(sf::RenderWindow &window, sf::Font &font) {

    
    // Title Text
    Label title("Graph Algorithm Visualizer", font, 50, sf::Text::Bold, sf::Color(255, 255, 255, 255), sf::Vector2f(40.0f, 30.f)); // sf::Color için r g b ve alpha değerleri var aynı zamanda sf::Color::Transparent da var şeffaflık için

    // Graph Edit Button
    sf::Vector2f buttonSize(250.0f, 70.0f);
    sf::Vector2f buttonPosition(0.0f, 0.0f);

    Button graphButton(buttonSize, buttonPosition, sf::Color::Transparent, sf::Color::White, 2.0f, "Graph Editor", font, 30, sf::Color::White);
    Button bfsButton(buttonSize, buttonPosition, sf::Color::Transparent, sf::Color::White, 2.0f, "Run BFS", font, 30, sf::Color::White);
    Button dfsButton(buttonSize, buttonPosition, sf::Color::Transparent, sf::Color::White, 2.0f, "Run DFS", font, 30, sf::Color::White);

    

    sf::Vector2u windowSize = window.getSize();
    float windowWidth = static_cast<float>(windowSize.x);
    float windowHeight = static_cast<float>(windowSize.y);
    
    sf::FloatRect visibleArea(0.0f, 0.0f, static_cast<float>(windowWidth), static_cast<float>(windowHeight));
    window.setView(sf::View(visibleArea));
    updateMenuLayout(window, title, graphButton, bfsButton, dfsButton);

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
                    updateMenuLayout(window, title, graphButton, bfsButton, dfsButton);
                    break;
                }

                case sf::Event::KeyPressed:

                    if (event.key.code == sf::Keyboard::Escape) {
                        window.close();
                        return Screen::Exit;
                    }

                    break;

                case sf::Event::MouseButtonPressed:
                    
                    if (event.mouseButton.button == sf::Mouse::Left) {

                        sf::Vector2f mousePositionClick(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));

                        if (graphButton.isClicked(mousePositionClick))
                            return Screen::Graph;
                    }

                    break;
            
                default:
                    break;
            }
        }

        window.clear(sf::Color::Black);

        title.drawLabel(window);

        sf::Vector2f mousePosition(static_cast<float>(event.mouseMove.x), static_cast<float>(event.mouseMove.y));

        graphButton.drawButton(window);
        graphButton.hoverState(mousePosition, sf::Color::White, sf::Color::Black);
        
        bfsButton.drawButton(window);
        bfsButton.hoverState(mousePosition, sf::Color::White, sf::Color::Black);

        dfsButton.drawButton(window);
        dfsButton.hoverState(mousePosition, sf::Color::White, sf::Color::Black);

        window.display();
    }

    return Screen::Exit;
}