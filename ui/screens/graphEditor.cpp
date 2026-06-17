#include "graphEditor.hpp"

#include <iostream>
#include <sstream>

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

void updateGraphEditorLayout(sf::RenderWindow &window, Button &exitButton, Textbox &nodeBox, Button &addNodeButton, Textbox &edgeBox, Button &addEdgeButton) {

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

    sf::Vector2f addNodeButtonSize(uiWidth * 0.8f, windowHeight * 0.1f);
    sf::Vector2f addNodeButtonPosition(uiWidth / 2.0f, windowHeight * 0.915f);
    addNodeButton.adjustScaling(addNodeButtonSize, addNodeButtonPosition, updateTextScale(window, addNodeButton.textPunto));
    addNodeButton.setOriginCenter();

    // Edge creaton
    sf::Vector2f edgeBoxSize(uiWidth * 0.8f, windowHeight * 0.1f);
    sf::Vector2f edgeBoxPosition(uiWidth / 2.0f, windowHeight * 0.5f);
    edgeBox.adjustScaling(edgeBoxSize, edgeBoxPosition, updateTextScale(window, edgeBox.characterSize));
    edgeBox.setOriginCenter();

    sf::Vector2f addEdgeButtonSize(uiWidth * 0.8f, windowHeight * 0.1f);
    sf::Vector2f addEdgeButtonPosition(uiWidth / 2.0f, windowHeight * 0.615f);
    addEdgeButton.adjustScaling(addEdgeButtonSize, addEdgeButtonPosition, updateTextScale(window, addEdgeButton.textPunto));
    addEdgeButton.setOriginCenter();
}

Screen displayGraphEditor(sf::RenderWindow &window, VisualGraph &vgraph, sf::Font &font, sf::RectangleShape &rectRing) {

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
    
    // Edge
    Textbox edgeBox(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(3.0f, 3.0f), font, 30, sf::Color::Transparent, sf::Color(237, 98, 28, 100), 2.0f, sf::Color(237, 98, 28, 100), "Edge (eg. 2 3)", sf::Color::Transparent, sf::Color(237, 98, 28), sf::Color(237, 98, 28));
    Button addEdgeButton(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(3.0f, 130.0f), sf::Color::Transparent, sf::Color(237, 98, 28), 2.0f, "Add Edge", font, 30, sf::Color(237, 98, 28));

    updateGraphEditorLayout(window, exitButton, nodeBox, addNodeButton, edgeBox, addEdgeButton);
    updateBorderRing(window, rectRing);

    sf::Vector2i mousePixel;
    sf::Vector2f mousePosition;


    // Graph View Settings

    //float graphZoom = 1.0f;
    //sf::Vector2f graphCameraCenter = graphView.getCenter();
    //bool isPanningGraph = false;
    //sf::Vector2i lastPanPixel;

    int clickedNode;
    bool isNodeClicked = false;
    
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
                    updateGraphEditorLayout(window, exitButton, nodeBox, addNodeButton, edgeBox, addEdgeButton);
                    updateBorderRing(window, rectRing);
                    break;
                }

                case sf::Event::KeyPressed:

                    if (event.key.code == sf::Keyboard::Escape)
                        return Screen::Menu;

                    if (event.key.code == sf::Keyboard::Enter) {

                        if (nodeBox.getActive()) {
                            
                            try {

                                int key = std::stoi(nodeBox.getTextContent());
                                std::cout << key << "\n";
    
                                // Add a position check for other nodes
                                if (!vgraph.addNode(key)) {
    
                                    std::cout << "Key " << key << " is already in the graph\n";
                                }
                            }
                            catch(const std::exception& e) {

                                std::cout << "Invalid Node Number\n";
                            }
                        }

                        if (edgeBox.getActive()) {

                            try {

                                std::string edge = edgeBox.getTextContent();
                                std::stringstream ss(edge);

                                int source;
                                int destination;

                                if (ss >> source >> destination) {

                                    if (!vgraph.addEdge(source, destination)) {
                                        
                                        std::cout << "Edge cannot be added\n";
                                    }
                                }

                                else {
                                    
                                    std::cout << "Invalid edge input\n";
                                }
                            }
                            catch(const std::exception& e) {

                                std::cout << "Invalid Edge input\n";
                            }
                        }
                    }


                    break;

                case sf::Event::MouseButtonPressed:
                    
                    if (event.mouseButton.button == sf::Mouse::Left) {

                        sf::Vector2i mousePixel(event.mouseButton.x, event.mouseButton.y);
                        sf::Vector2f mousePositionClickForUI = window.mapPixelToCoords(mousePixel, uiView);
                        sf::Vector2f mousePositionClickForGraph = window.mapPixelToCoords(mousePixel, graphView);

                        if (exitButton.isClicked(mousePositionClickForUI))
                            return Screen::Menu;

                        // Change this later on
                        if (addNodeButton.isClicked(mousePositionClickForUI)) {

                            try
                            {
                                int key = std::stoi(nodeBox.getTextContent());
                                std::cout << key << "\n";

                                // Add a position check for other nodes
                                if (!vgraph.addNode(key)) {

                                    std::cout << "Key " << key << " is already in the graph\n";
                                }
                            }
                            catch(const std::exception& e)
                            {
                                std::cout << "Invalid Node Number\n";
                            }
                            
                        }

                        else {

                            if (!isNodeClicked) {

                                isNodeClicked = vgraph.isClicked(mousePositionClickForGraph, clickedNode);

                                if (isNodeClicked) {

                                    std::cout << "Clicked Node " << clickedNode << "\n";
                                }
                            }
                        }

                        
                    }

                    break;

                case sf::Event::MouseButtonReleased:

                    if (event.mouseButton.button == sf::Mouse::Left) {

                        if (isNodeClicked) {
                            std::cout << "Mouse button released and no longer dragging\n";
                            isNodeClicked = false;
                        }
                    }

                    break;

                case sf::Event::MouseMoved:

                    if (isNodeClicked) {

                        sf::Vector2i mousePixel(event.mouseMove.x, event.mouseMove.y);
                        sf::Vector2f mousePositionForGraph = window.mapPixelToCoords(mousePixel, graphView);

                        vgraph.dragNode(mousePositionForGraph, clickedNode);
                    }

                    break;
            
                default:
                    break;
            }

            nodeBox.handleEvent(event, window, uiView);
            edgeBox.handleEvent(event, window, uiView);
        }        

        window.clear(sf::Color::Black);


        window.setView(graphView);

        vgraph.drawGraph(window);

        
        
        window.setView(uiView);
        
        sf::Vector2i mousePixel = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosition = window.mapPixelToCoords(mousePixel, uiView);
        
        exitButton.drawButton(window);
        exitButton.hoverState(mousePosition, sf::Color(237, 98, 28), sf::Color::Black);
        
        nodeBox.drawTextbox(window);
        addNodeButton.drawButton(window);
        addNodeButton.hoverState(mousePosition, sf::Color(237, 98, 28), sf::Color::Black);
        
        edgeBox.drawTextbox(window);
        addEdgeButton.drawButton(window);
        addEdgeButton.hoverState(mousePosition, sf::Color(237, 98, 28), sf::Color::Black);

        
        window.setView(borderView);
        window.draw(rectRing);
        
        window.display();
    }

    return Screen::Menu;
}