#include "graphEditor.hpp"
#include "../../third_party_libraries/tinyfiledialogs/tinyfiledialogs.hpp"
#include "../../io/readwrite.hpp"

#include <iostream>
#include <sstream>

void updateGraphViews(
                sf::RenderWindow &window, 
                sf::View &graphView, 
                sf::View &uiView, 
                sf::View &borderView
        )
{
    sf::Vector2u windowSize = window.getSize();

    float windowWidth = static_cast<float>(windowSize.x);
    float windowHeight = static_cast<float>(windowSize.y);

    float graphWidth = windowWidth * 1.0f;
    float uiWidth = windowWidth * 0.2f;

    // Left 80% of the window
    graphView.setViewport(sf::FloatRect(0.0f, 0.0f, 1.0f, 1.0f));
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

Screen displayGraphEditor(
                sf::RenderWindow &window, 
                VisualGraph &vgraph, 
                sf::Font &font, 
                sf::RectangleShape &rectRing, 
                Config &config
        )
{

        // For file selection
        char const *lFilterPatterns[] = {"*.txt"};

        // Cursor for buttons and normal use
        sf::Cursor normalCursor;
        normalCursor.loadFromSystem(sf::Cursor::Arrow);
        
        sf::Cursor handCursor;
        handCursor.loadFromSystem(sf::Cursor::Hand);

        sf::Cursor moveCursor;
        moveCursor.loadFromSystem(sf::Cursor::SizeAll);

        // Window Dimensions
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
        Button exitButton(
                "<- Menu",
                sf::Vector2f(0.0f, 0.0f),
                sf::Vector2f(0.0f, 0.0f),
                font,
                compactButton,
                hoverCompactButton
        );
    
        // Add Node
        Textbox nodeBox(
                sf::Vector2f(0.0f, 0.0f),
                sf::Vector2f(3.0f, 3.0f),
                font,
                "Add a node",
                defaultTextbox
        );
        Button addNodeButton(
                "Add Node", 
                sf::Vector2f(0.0f, 0.0f), 
                sf::Vector2f(3.0f, 130.0f),
                font,
                defaultButton,
                hoverDefaultButton
        );
        
        // Add Edge
        Textbox edgeBox(
                sf::Vector2f(0.0f, 0.0f),
                sf::Vector2f(3.0f, 3.0f),
                font,
                "Edge (eg. 2 3)",
                defaultTextbox
        );
        Button addEdgeButton(
                "Add Edge", 
                sf::Vector2f(0.0f, 0.0f), 
                sf::Vector2f(3.0f, 130.0f),
                font,
                defaultButton,
                hoverDefaultButton
        );
        
        Button clearGraphButton(
                "Clear Graph",
                sf::Vector2f(0.0f, 0.0f),
                sf::Vector2f(3.0f, 130.0f),
                font,
                compactButton,
                hoverCompactButton
        );

        Button loadGraphButton(
                "Load Graph",
                sf::Vector2f(0.0f, 0.0f),
                sf::Vector2f(3.0f, 130.0f),
                font,
                compactButton,
                hoverCompactButton
        );

        Button saveGraphButton(
                "Save Graph",
                sf::Vector2f(0.0f, 0.0f),
                sf::Vector2f(3.0f, 130.0f),
                font,
                compactButton,
                hoverCompactButton
        );

        Button centerGraphButton(
                "Center Graph",
                sf::Vector2f(0.0f, 0.0f),
                sf::Vector2f(3.0f, 130.0f),
                font,
                compactButton,
                hoverCompactButton
        );
    
        // ui black semi transparent rectangle
        sf::RectangleShape uibg;
        uibg.setFillColor(sf::Color(0, 0, 0, 200));
        
        updateGraphEditorLayout(
                window, 
                exitButton, 
                nodeBox, 
                addNodeButton,
                edgeBox,
                addEdgeButton,
                uibg,
                clearGraphButton,
                loadGraphButton,
                saveGraphButton,
                centerGraphButton
        );

        updateBorderRing(window, rectRing);


        // Error Pop Ups
        bool showNodeErrorPopUp = false;
        PopUp nodeErrorPopUp(
                "Cannot Add Node",
                "The node you are trying to\n\nadd is already in the graph",
                "Okay",
                font,
                sf::Vector2f(
                        windowWidth * 0.5,
                        windowHeight * 0.5
                ),
                popUpDefault,
                window
        );

        bool showEdgeErrorPopUp = false;
        PopUp edgeErrorPopUp(
                "Cannot Add Edge",
                "The edge you are trying to\n\nadd is already in the graph",
                "Okay",
                font,
                sf::Vector2f(
                        windowWidth * 0.5, 
                        windowHeight * 0.5
                ),
                popUpDefault,
                window
        );

        sf::Vector2i mousePixel;
        sf::Vector2f mousePosition;

        // Graph View Settings

        //float graphZoom = 1.0f;
        //sf::Vector2f graphCameraCenter = graphView.getCenter();
        bool isPanningGraph = false;
        sf::Vector2i lastPanPixel;

        int clickedNode;
        bool isNodeClicked = false;

        float currentZoom = 1.0f;
        float targetZoom = 1.0f;
    
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
                                updateGraphEditorLayout(window, exitButton, nodeBox, addNodeButton, edgeBox, addEdgeButton, uibg, clearGraphButton, loadGraphButton, saveGraphButton, centerGraphButton);
                                updateBorderRing(window, rectRing);
                                break;
                        }

                        case sf::Event::KeyPressed:
                                if (event.key.code == sf::Keyboard::Escape)
                                        return Screen::Menu;

                                if (event.key.code == sf::Keyboard::Enter) {
                                        if (nodeBox.getActive())
                                                addNodeAction(nodeBox, vgraph, showNodeErrorPopUp);

                                        if (edgeBox.getActive())
                                                addEdgeAction(edgeBox, vgraph, showEdgeErrorPopUp);
                                }

                        break;

                        case sf::Event::MouseButtonPressed:
                                switch (event.mouseButton.button) {

                                case sf::Mouse::Left: {
                                        sf::Vector2i mousePixel(event.mouseButton.x, event.mouseButton.y);
                                        sf::Vector2f mousePositionClickForUI = window.mapPixelToCoords(mousePixel, uiView);
                                        sf::Vector2f mousePositionClickForGraph = window.mapPixelToCoords(mousePixel, graphView);
                                        sf::Vector2f mousePositionClickForBorder = window.mapPixelToCoords(mousePixel, borderView);

                                        if (!(showEdgeErrorPopUp || showNodeErrorPopUp)) {
                                                if (exitButton.isClicked(mousePositionClickForUI))
                                                        return Screen::Menu;
                
                                                // Change this later on
                                                else if (addNodeButton.isClicked(mousePositionClickForUI))
                                                        addNodeAction(nodeBox, vgraph, showNodeErrorPopUp);
                
                                                else if (addEdgeButton.isClicked(mousePositionClickForUI))
                                                        addEdgeAction(edgeBox, vgraph, showEdgeErrorPopUp);
                
                                                else if (clearGraphButton.isClicked(mousePositionClickForUI))
                                                        vgraph.clearGraph();

                                                else if (centerGraphButton.isClicked(mousePositionClickForUI))
                                                        centerCamera(graphView, vgraph);
                
                                                if (loadGraphButton.isClicked(mousePositionClickForUI)) {
                
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

                                                if (saveGraphButton.isClicked(mousePositionClickForUI)) {

                                                        char const *folderSelection = tinyfd_selectFolderDialog(
                                                                "Select a folder to save", // title
                                                                "" // optional initial directory
                                                        );
                                                        char const *fileNameSelection = tinyfd_inputBox("Name your graph", "Choose a file name for your graph (must end with .txt)", "graph.txt");

                                                        std::string filepath(folderSelection);
                                                        filepath.append("/");
                                                        filepath.append(fileNameSelection);

                                                        std::cout << "Filepath created: " << filepath << "\n";

                                                        saveGraphData(filepath.c_str(), vgraph);
                                                }
                        
                                                else {
                        
                                                        if (!isNodeClicked) {
                                                                isNodeClicked = vgraph.isClicked(mousePositionClickForGraph, clickedNode);
                                                                
                                                                if (isNodeClicked) {
                                                                        window.setMouseCursor(moveCursor);
                                                                        std::cout << "Clicked Node " << clickedNode << "\n";
                                                                }
                                                        }
                                                }
                                        }

                                        else {

                                                if (showNodeErrorPopUp)
                                                        if (nodeErrorPopUp.isDismissed(mousePositionClickForBorder))
                                                                showNodeErrorPopUp = false;

                                                if (showEdgeErrorPopUp)
                                                        if (edgeErrorPopUp.isDismissed(mousePositionClickForBorder))
                                                                showEdgeErrorPopUp = false;
                                        }
                

                                        break;

                                }

                                case sf::Mouse::Middle:
                                        isPanningGraph = true;
                                        lastPanPixel = sf::Vector2i(event.mouseButton.x, event.mouseButton.y);
                                        window.setMouseCursor(moveCursor);

                                        break;
                                
                                default:
                                break;
                        }

                        break;

                        case sf::Event::MouseButtonReleased:

                                switch (event.mouseButton.button) {

                                case sf::Mouse::Left:
                                        if (isNodeClicked) {
                                                std::cout << "Mouse button released and no longer dragging\n";
                                                isNodeClicked = false;
                                        }

                                        break;

                                case sf::Mouse::Middle:
                                        isPanningGraph = false;
                                        break;
                                
                                default:
                                break;
                                }

                        break;

                        case sf::Event::MouseMoved:

                                if (isNodeClicked) {
                                        sf::Vector2i mousePixel(event.mouseMove.x, event.mouseMove.y);
                                        sf::Vector2f mousePositionForGraph = window.mapPixelToCoords(mousePixel, graphView);

                                        vgraph.dragNode(mousePositionForGraph, clickedNode);
                                }

                                if (isPanningGraph) {

                                        sf::Vector2i currentPixel(event.mouseMove.x, event.mouseMove.y);

                                        sf::Vector2f oldPosition = window.mapPixelToCoords(lastPanPixel, graphView);
                                        sf::Vector2f newPosition = window.mapPixelToCoords(currentPixel, graphView);

                                        graphView.move(oldPosition - newPosition);

                                        lastPanPixel = currentPixel;
                                }

                                break;

                        case sf::Event::MouseWheelScrolled:

                                if (config.smoothScroll == 1) {

                                        if (event.mouseWheelScroll.delta > 0)
                                                targetZoom *= 0.9f;

                                        else
                                                targetZoom *= 1.1;
                                }
                                else {

                                        if (event.mouseWheelScroll.delta > 0)
                                                graphView.zoom(0.9f);

                                        else
                                                graphView.zoom(1.1);
                                }
                        
                                break;
                
                        default:
                        break;
                        }

                        nodeBox.handleEvent(event, window, uiView);
                        edgeBox.handleEvent(event, window, uiView);
                }        


                if (config.smoothScroll == 1) {
                        float newZoom = currentZoom + (targetZoom - currentZoom) * 0.01f;
                        float zoomFactor = newZoom / currentZoom;
                        graphView.zoom(zoomFactor);
                        currentZoom = newZoom;
                }

                window.clear(sf::Color::Black);


                window.setView(graphView);

                vgraph.drawGraph(window);

        
        
                window.setView(uiView);

                window.draw(uibg);
        
                sf::Vector2i mousePixel = sf::Mouse::getPosition(window);
                sf::Vector2f mousePosition = window.mapPixelToCoords(mousePixel, uiView);
        
                exitButton.drawButton(window);
                bool exitButtonHover = exitButton.hoverState(mousePosition);
                
                nodeBox.drawTextbox(window);
                addNodeButton.drawButton(window);
                bool addNodeHover = addNodeButton.hoverState(mousePosition);
                
                edgeBox.drawTextbox(window);
                addEdgeButton.drawButton(window);
                bool addEdgeHover = addEdgeButton.hoverState(mousePosition);
                
                clearGraphButton.drawButton(window);
                bool clearGraphHover = clearGraphButton.hoverState(mousePosition);
                
                loadGraphButton.drawButton(window);
                bool loadGraphHover = loadGraphButton.hoverState(mousePosition);
                
                saveGraphButton.drawButton(window);
                bool saveGraphHover = saveGraphButton.hoverState(mousePosition);
                
                centerGraphButton.drawButton(window);
                bool centerGraphHover = centerGraphButton.hoverState(mousePosition);
        
                if (
                        addNodeHover 
                        || addEdgeHover 
                        || exitButtonHover 
                        || clearGraphHover 
                        || loadGraphHover 
                        || saveGraphHover 
                        || centerGraphHover
                ) {
                window.setMouseCursor(handCursor);
                }
                else if (!(isNodeClicked || isPanningGraph)) {
                window.setMouseCursor(normalCursor);
                }
        
                window.setView(borderView);
                sf::Vector2f mousePositionPopUp = window.mapPixelToCoords(mousePixel, borderView);

                if (showNodeErrorPopUp) {
                if (nodeErrorPopUp.dismissHoverState(mousePositionPopUp)) {
                        window.setMouseCursor(handCursor);
                }

                nodeErrorPopUp.drawPopUp(window);
                }

                if (showEdgeErrorPopUp) {
                if (edgeErrorPopUp.dismissHoverState(mousePositionPopUp)) {
                        window.setMouseCursor(handCursor);
                }

                edgeErrorPopUp.drawPopUp(window);
                }

                window.draw(rectRing);
                
                window.display();
        }

        return Screen::Menu;
}