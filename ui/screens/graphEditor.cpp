#include "graphEditor.hpp"
#include "graphEditorElements.hpp"
#include "../../third_party_libraries/tinyfiledialogs/tinyfiledialogs.hpp"
#include "../../io/readwrite.hpp"

#include <iostream>
#include <sstream>

void updateGraphViews(sf::RenderWindow &window, EditorViews &views)
{
    sf::Vector2u windowSize = window.getSize();

    float windowWidth = static_cast<float>(windowSize.x);
    float windowHeight = static_cast<float>(windowSize.y);

    float graphWidth = windowWidth * 1.0f;
    float uiWidth = windowWidth * 0.2f;

    // Left 80% of the window
    views.graphView.setViewport(sf::FloatRect(0.0f, 0.0f, 1.0f, 1.0f));
    views.graphView.setSize(graphWidth, windowHeight);
    views.graphView.setCenter(graphWidth / 2.0f, windowHeight / 2.0f);

    // Right 20% of the window
    views.uiView.setViewport(sf::FloatRect(0.8f, 0.0f, 0.2f, 1.0f));
    views.uiView.setSize(uiWidth, windowHeight);
    views.uiView.setCenter(uiWidth / 2.0f, windowHeight / 2.0f);

    // Full window border view
    views.borderView.setViewport(sf::FloatRect(0.0f, 0.0f, 1.0f, 1.0f));
    views.borderView.setSize(windowWidth, windowHeight);
    views.borderView.setCenter(windowWidth / 2.0f, windowHeight / 2.0f);
}

void addNodeAction(Textbox &nodeBox, VisualGraph &vgraph, bool &showNodeErrorPopUp)
{
        try {
                int key = std::stoi(nodeBox.getTextContent());
                std::cout << key << "\n";
                
                // Add a position check for other nodes
                if (!vgraph.addNode(key)) {         
                        showNodeErrorPopUp = true;
                        std::cout << "Key " << key << " is already in the graph\n";
                }
        }
        catch(const std::exception& e) {
                std::cout << "Invalid Node Number\n";
        }
}

void addEdgeAction(Textbox &edgeBox, VisualGraph &vgraph, bool &showEdgeErrorPopUp)
{
        try {
                std::string edge = edgeBox.getTextContent();
                std::stringstream ss(edge);

                int source;
                int destination;

                if (ss >> source >> destination) {
                        if (!vgraph.addEdge(source, destination)) {
                                showEdgeErrorPopUp = true;
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

void centerCamera(sf::View &graphView, VisualGraph &vgraph)
{
        std::array<float, 4> bounds = vgraph.getBounds();

        float lowestX  = bounds[0];
        float highestX = bounds[1];
        float lowestY  = bounds[2];
        float highestY = bounds[3];

        sf::Vector2f centerPoint(
                (lowestX + highestX) / 2.0f,
                (lowestY + highestY) / 2.0f
        );

        graphView.setCenter(centerPoint);
}

Screen mouseButtonEvent(
                sf::Event &event,
                sf::RenderWindow &window,
                VisualGraph &vgraph,
                EditorViews &views,
                EditorUIElements &ui,
                EditorPopUps &popUps,
                EditorState &state,
                EditorCursors &cursors
        )
{
        switch (event.mouseButton.button) {

        case sf::Mouse::Left: {
                sf::Vector2i mousePixel(event.mouseButton.x, event.mouseButton.y);
                sf::Vector2f mousePositionClickForUI = window.mapPixelToCoords(mousePixel, views.uiView);
                sf::Vector2f mousePositionClickForGraph = window.mapPixelToCoords(mousePixel, views.graphView);
                sf::Vector2f mousePositionClickForBorder = window.mapPixelToCoords(mousePixel, views.borderView);

                if (!(state.showEdgeErrorPopUp || state.showNodeErrorPopUp)) {
                        if (ui.exitButton.isClicked(mousePositionClickForUI))
                                return Screen::Menu;
                
                        // Change this later on
                        else if (ui.addNodeButton.isClicked(mousePositionClickForUI))
                                addNodeAction(ui.nodeBox, vgraph, state.showNodeErrorPopUp);
                
                        else if (ui.addEdgeButton.isClicked(mousePositionClickForUI))
                                addEdgeAction(ui.edgeBox, vgraph, state.showEdgeErrorPopUp);
                
                        else if (ui.clearGraphButton.isClicked(mousePositionClickForUI))
                                vgraph.clearGraph();

                        else if (ui.centerGraphButton.isClicked(mousePositionClickForUI))
                                centerCamera(views.graphView, vgraph);
                
                        if (ui.loadGraphButton.isClicked(mousePositionClickForUI)) {
                                char const *lFilterPatterns[] = {"*.txt"};
                                // Tiny File Dialog part
                                char const *selection = tinyfd_openFileDialog(
                                        "Select file", // title
                                        "", // optional initial directory
                                        1, // number of filter patterns
                                        lFilterPatterns, // char const * lFilterPatterns[2] = { "*.txt", "*.jpg" };
                                        NULL, // optional filter description
                                        0 // forbids multiple selections
                                );

                                if (!(selection == nullptr)) {
                                        std::cout << selection << "\n";
                                        readGraphData(selection, vgraph);
                                }
                                else {
                                        std::cout << "No file selected\n";
                                }
                        }

                        if (ui.saveGraphButton.isClicked(mousePositionClickForUI)) {
                                char const *folderSelection = tinyfd_selectFolderDialog(
                                        "Select a folder to save", // title
                                        "" // optional initial directory
                                );
                                if (folderSelection == nullptr)
                                        break;
                                
                                char const *fileNameSelection = tinyfd_inputBox("Name your graph", "Choose a file name for your graph (must end with .txt)", "graph.txt");
                                if (fileNameSelection == nullptr)
                                        break;

                                std::string filepath(folderSelection);
                                filepath.append("/");
                                filepath.append(fileNameSelection);

                                std::cout << "Filepath created: " << filepath << "\n";

                                saveGraphData(filepath.c_str(), vgraph);
                        }
                        
                        else {
                                if (!state.isNodeClicked) {
                                        state.isNodeClicked = vgraph.isClicked(mousePositionClickForGraph, state.clickedNode);
                                                                
                                        if (state.isNodeClicked) {
                                                window.setMouseCursor(cursors.moveCursor);
                                                std::cout << "Clicked Node " << state.clickedNode << "\n";
                                        }
                                }
                        }
                }

                else {

                        if (state.showNodeErrorPopUp)
                                if (popUps.nodeErrorPopUp.isDismissed(mousePositionClickForBorder))
                                        state.showNodeErrorPopUp = false;

                        if (state.showEdgeErrorPopUp)
                                if (popUps.edgeErrorPopUp.isDismissed(mousePositionClickForBorder))
                                        state.showEdgeErrorPopUp = false;
                }
                

                break;

        }

        case sf::Mouse::Middle:
                state.isPanningGraph = true;
                state.lastPanPixel = sf::Vector2i(event.mouseButton.x, event.mouseButton.y);
                window.setMouseCursor(cursors.moveCursor);

                break;
                                
        default:
                break;
        }

        return Screen::Graph;
}

Screen displayGraphEditor(
                sf::RenderWindow &window, 
                VisualGraph &vgraph, 
                sf::Font &font, 
                sf::RectangleShape &rectRing, 
                Config &config
        )
{
        // Cursor for buttons and normal use
        EditorCursors cursors;

        // Window Dimensions
        sf::Vector2u windowSize = window.getSize();

        float windowWidth = static_cast<float>(windowSize.x);
        float windowHeight = static_cast<float>(windowSize.y);

        // Views
        EditorViews views;
        updateGraphViews(window, views);

        // UI elements
        EditorUIElements ui(font);

        
        updateGraphEditorLayout(window, ui);

        updateBorderRing(window, rectRing);


        EditorState state;

        // Error Pop Ups
        EditorPopUps popUps(
                font,
                window,
                sf::Vector2f(
                        windowWidth * 0.5,
                        windowHeight * 0.5
                )
        );

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
                                updateGraphViews(window, views);
                                updateGraphEditorLayout(window, ui);
                                updateBorderRing(window, rectRing);
                                break;
                        }

                        case sf::Event::KeyPressed:
                                if (event.key.code == sf::Keyboard::Escape)
                                        return Screen::Menu;

                                if (event.key.code == sf::Keyboard::Enter) {
                                        if (ui.nodeBox.getActive())
                                                addNodeAction(ui.nodeBox, vgraph, state.showNodeErrorPopUp);

                                        if (ui.edgeBox.getActive())
                                                addEdgeAction(ui.edgeBox, vgraph, state.showEdgeErrorPopUp);
                                }

                        break;

                        case sf::Event::MouseButtonPressed: {
                                Screen screenToGo = mouseButtonEvent(event, window, vgraph, views, ui, popUps, state, cursors);
                                
                                if (screenToGo != Screen::Graph)
                                        return screenToGo;

                                break;
                        }

                        case sf::Event::MouseButtonReleased:

                                switch (event.mouseButton.button) {

                                case sf::Mouse::Left:
                                        if (state.isNodeClicked) {
                                                std::cout << "Mouse button released and no longer dragging\n";
                                                state.isNodeClicked = false;
                                        }

                                        break;

                                case sf::Mouse::Middle:
                                        state.isPanningGraph = false;
                                        break;
                                
                                default:
                                break;
                                }

                        break;

                        case sf::Event::MouseMoved:

                                if (state.isNodeClicked) {
                                        sf::Vector2i mousePixel(event.mouseMove.x, event.mouseMove.y);
                                        sf::Vector2f mousePositionForGraph = window.mapPixelToCoords(mousePixel, views.graphView);

                                        vgraph.dragNode(mousePositionForGraph, state.clickedNode);
                                }

                                if (state.isPanningGraph) {

                                        sf::Vector2i currentPixel(event.mouseMove.x, event.mouseMove.y);

                                        sf::Vector2f oldPosition = window.mapPixelToCoords(state.lastPanPixel, views.graphView);
                                        sf::Vector2f newPosition = window.mapPixelToCoords(currentPixel, views.graphView);

                                        views.graphView.move(oldPosition - newPosition);

                                        state.lastPanPixel = currentPixel;
                                }

                                break;

                        case sf::Event::MouseWheelScrolled:

                                if (config.smoothScroll == 1) {

                                        if (event.mouseWheelScroll.delta > 0)
                                                state.targetZoom *= 0.9f;

                                        else
                                                state.targetZoom *= 1.1;
                                }
                                else {

                                        if (event.mouseWheelScroll.delta > 0)
                                                views.graphView.zoom(0.9f);

                                        else
                                                views.graphView.zoom(1.1);
                                }
                        
                                break;
                
                        default:
                        break;
                        }

                        ui.nodeBox.handleEvent(event, window, views.uiView);
                        ui.edgeBox.handleEvent(event, window, views.uiView);
                }        


                if (config.smoothScroll == 1) {
                        float newZoom = state.currentZoom + (state.targetZoom - state.currentZoom) * 0.01f;
                        float zoomFactor = newZoom / state.currentZoom;
                        views.graphView.zoom(zoomFactor);
                        state.currentZoom = newZoom;
                }

                window.clear(sf::Color::Black);


                window.setView(views.graphView);
                vgraph.drawGraph(window);

                window.setView(views.uiView);
                ui.drawUI(window);
        
                sf::Vector2i mousePixel = sf::Mouse::getPosition(window);
                sf::Vector2f mousePosition = window.mapPixelToCoords(mousePixel, views.uiView);
        
                if (ui.checkHover(mousePosition)) {
                        window.setMouseCursor(cursors.handCursor);
                }
                else if (!(state.isNodeClicked || state.isPanningGraph)) {
                        window.setMouseCursor(cursors.normalCursor);
                }
        
                window.setView(views.borderView);
                sf::Vector2f mousePositionPopUp = window.mapPixelToCoords(mousePixel, views.borderView);

                if (state.showNodeErrorPopUp) {
                        if (popUps.nodeErrorPopUp.dismissHoverState(mousePositionPopUp)) {
                                window.setMouseCursor(cursors.handCursor);
                        }

                        popUps.nodeErrorPopUp.drawPopUp(window);
                }

                if (state.showEdgeErrorPopUp) {
                        if (popUps.edgeErrorPopUp.dismissHoverState(mousePositionPopUp)) {
                                window.setMouseCursor(cursors.handCursor);
                        }

                        popUps.edgeErrorPopUp.drawPopUp(window);
                }

                window.draw(rectRing);
                
                window.display();
        }

        return Screen::Menu;
}