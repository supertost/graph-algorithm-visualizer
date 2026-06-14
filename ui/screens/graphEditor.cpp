#include "graphEditor.hpp"

#include <iostream>

void updateGraphViews(sf::RenderWindow &window, sf::View &graphView, sf::View &uiView, sf::View &borderView) {

    sf::Vector2u windowSize = window.getSize();

    float windowWidth = static_cast<float>(windowSize.x);
    float windowHeight = static_cast<float>(windowSize.y);

    float graphWidth = windowWidth * 0.8f;
    float uiWidth = windowWidth * 0.2f;

    // Left 80% of the window
    graphView.setViewport(sf::FloatRect(0.0f, 0.0f, 0.8f, 1.0f));
    graphView.setSize(graphWidth, windowHeight);
    graphView.setCenter(graphWidth / 2.0f, windowHeight / 2.0f);

    // Right 20% of the window
    uiView.setViewport(sf::FloatRect(0.8f, 0.0f, 0.2f, 1.0f));
    uiView.setSize(uiWidth, windowHeight);
    uiView.setCenter(uiWidth / 2.0f, windowHeight / 2.0f);

    // Full window border view
    borderView.setViewport(sf::FloatRect(0.0f, 0.0f, 1.0f, 1.0f));
    borderView.setSize(windowWidth, windowHeight);
    borderView.setCenter(windowWidth / 2.0f, windowHeight / 2.0f);
}

void updateGraphEditorLayout(sf::RenderWindow &window, Button &exitButton, Textbox &nodeBox, Button &addNodeButton) {

    sf::Vector2u windowSize = window.getSize();

    float windowWidth = static_cast<float>(windowSize.x);
    float windowHeight = static_cast<float>(windowSize.y);

    float uiWidth = windowWidth * 0.2f;

    // Exit Button
    sf::Vector2f exitButtonSize(uiWidth * 0.8f, windowHeight * 0.06f);
    sf::Vector2f exitButtonPosition(uiWidth / 2.0f, windowHeight * 0.06f);
    exitButton.adjustScaling(exitButtonSize, exitButtonPosition, updateTextScale(window, exitButton.textPunto));
    exitButton.setOriginCenter();

    // Textbox for the Node Creation
    sf::Vector2f nodeBoxSize(uiWidth * 0.8f, windowHeight * 0.1f);
    sf::Vector2f nodeBoxPosition(uiWidth / 2.0f, windowHeight * 0.8f);
    nodeBox.adjustScaling(nodeBoxSize, nodeBoxPosition, updateTextScale(window, nodeBox.characterSize));
    nodeBox.setOriginCenter();

    (void)addNodeButton;
    sf::Vector2f addNodeButtonSize(uiWidth * 0.8f, windowHeight * 0.1f);
    sf::Vector2f addNodeButtonPosition(uiWidth / 2.0f, windowHeight * 0.915f);
    addNodeButton.adjustScaling(addNodeButtonSize, addNodeButtonPosition, updateTextScale(window, addNodeButton.textPunto));
    addNodeButton.setOriginCenter();


}

Screen displayGraphEditor(sf::RenderWindow &window, sf::Font &font, sf::RectangleShape &rectRing) {

    sf::Vector2u windowSize = window.getSize();

    float windowWidth = static_cast<float>(windowSize.x);
    float windowHeight = static_cast<float>(windowSize.y);

    // Views
    sf::View graphView;
    sf::View uiView;
    sf::View borderView;

    updateGraphViews(window, graphView, uiView, borderView);


    // UI Elements

    // Exit Button
    sf::Vector2f buttonSize(windowWidth * 0.10f, windowHeight * 0.05f);
    sf::Vector2f buttonPosition(0.0f, 0.0f);
    Button exitButton(buttonSize, buttonPosition, sf::Color::Transparent, sf::Color(237, 98, 28), 2.0f, "<- Menu", font, 20, sf::Color(237, 98, 28));
    
    // Add Node Textbox and Add button
    //Textbox nodeBox(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(3.0f, 3.0f), font, 30, sf::Color::Transparent, sf::Color::White, 2.0f, sf::Color(255, 255, 255, 150), "Add a node", sf::Color::Transparent, sf::Color(52, 177, 235), sf::Color(52, 177, 235));
    Textbox nodeBox(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(3.0f, 3.0f), font, 30, sf::Color::Transparent, sf::Color(237, 98, 28, 100), 2.0f, sf::Color(237, 98, 28, 100), "Add a node", sf::Color::Transparent, sf::Color(237, 98, 28), sf::Color(237, 98, 28));
    Button addNodeButton(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(3.0f, 130.0f), sf::Color::Transparent, sf::Color(237, 98, 28), 2.0f, "Add Node", font, 30, sf::Color(237, 98, 28));

    updateGraphEditorLayout(window, exitButton, nodeBox, addNodeButton);
    updateBorderRing(window, rectRing);

    sf::Vector2i mousePixel;
    sf::Vector2f mousePosition;
    
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {


            switch (event.type) {

                case sf::Event::Closed:
                    
                    window.close();
                    return Screen::Exit;
                    break;

                case sf::Event::Resized: {

                    updateGraphViews(window, graphView, uiView, borderView);
                    updateGraphEditorLayout(window, exitButton, nodeBox, addNodeButton);
                    updateBorderRing(window, rectRing);
                    break;
                }

                case sf::Event::KeyPressed:

                    if (event.key.code == sf::Keyboard::Escape)
                        return Screen::Menu;

                    break;

                case sf::Event::MouseButtonPressed:
                    
                    if (event.mouseButton.button == sf::Mouse::Left) {

                        sf::Vector2i mousePixel(event.mouseButton.x, event.mouseButton.y);
                        sf::Vector2f mousePositionClick = window.mapPixelToCoords(mousePixel, uiView);

                        if (exitButton.isClicked(mousePositionClick))
                            return Screen::Menu;

                        // Change this later on
                        if (addNodeButton.isClicked(mousePositionClick)) {

                            try
                            {
                                int key = std::stoi(nodeBox.getTextContent());
                                std::cout << key << "\n";
                            }
                            catch(const std::exception& e)
                            {
                                std::cout << "Invalid Node Number\n";
                            }
                            
                        }
                    }

                    break;
            
                default:
                    break;
            }

            nodeBox.handleEvent(event, window, uiView);
        }        

        window.clear(sf::Color::Black);

        window.setView(uiView);

        sf::Vector2i mousePixel = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosition = window.mapPixelToCoords(mousePixel, uiView);
        
        exitButton.drawButton(window);
        exitButton.hoverState(mousePosition, sf::Color(237, 98, 28), sf::Color::Black);
        
        nodeBox.drawTextbox(window);
        addNodeButton.drawButton(window);
        addNodeButton.hoverState(mousePosition, sf::Color(237, 98, 28), sf::Color::Black);
        
        window.setView(borderView);
        window.draw(rectRing);

        window.display();
    }

    return Screen::Menu;
}