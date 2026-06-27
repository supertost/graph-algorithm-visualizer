#include "bfsScreen.hpp"
#include "../vgraph_algorithms/bfs/vbfs.hpp"

static void centerCamera(sf::View &graphView, sf::Vector2f graphViewSize, VisualGraph &vgraph)
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

        float graphWidth = highestX - lowestX;
        float graphHeight = highestY - lowestY;
        
        float ratioHeight = graphHeight / graphViewSize.x;
        float ratioWidth = graphWidth / graphViewSize.y;
        float ratio = std::max(ratioHeight, ratioWidth);
        graphView.zoom(ratio);

        // This works fine for the most part, but maybe doing a ratio calculation 
        // using the graph width or height to either add or remove some padding 
        // might be beneficial as complex graphs with different positioned nodes 
        // seem to make the zoom center feature zoom a bit small compared to the 
        // actual viewport. 
}

void updateBfsViews(sf::RenderWindow &window, BfsViews &views, VisualGraph &vgraph)
{
        sf::Vector2u windowSize = window.getSize();

        float windowWidth = static_cast<float>(windowSize.x);
        float windowHeight = static_cast<float>(windowSize.y);

        sf::Vector2f graphViewSize(windowWidth, windowHeight * 0.8);
        sf::Vector2f uiViewSize(windowWidth, windowHeight * 0.2);
        //sf::Vector2f borderViewSize(windowWidth, windowHeight * 0.2);

        views.graphView.setViewport(sf::FloatRect(0.0f, 0.0f, 1.0f, 0.8f));
        views.graphView.setSize(graphViewSize.x, graphViewSize.y);
        centerCamera(views.graphView, graphViewSize, vgraph);

        views.uiView.setViewport(sf::FloatRect(0.0f, 0.8f, 1.0f, 0.2f));
        views.uiView.setSize(uiViewSize.x, uiViewSize.y);
        views.uiView.setCenter(uiViewSize.x / 2.0f, uiViewSize.y / 2.0f);

        //views.borderView.setViewport(sf::FloatRect(0.0f, 0.0f, 1.0f, 1.0f));
        //views.borderView.setSize(graphViewSize.x, graphViewSize.y);
        //views.borderView.setCenter(graphViewSize.x / 2.0f, graphViewSize.y / 2.0f);
}

void mouseButtonEvent(sf::Event &event, sf::RenderWindow &window, VisualGraph &vgraph, BfsViews &views, BfsUIElements &ui)
{
        switch (event.mouseButton.button) {

        case sf::Mouse::Left: {
                sf::Vector2i mousePixel(event.mouseButton.x, event.mouseButton.y);
                sf::Vector2f mousePositionClickForUI = window.mapPixelToCoords(mousePixel, views.uiView);

                if (ui.playpause.isClicked(mousePositionClickForUI)) {
                        std::vector<int> traversal = bfs(vgraph, 21);

                        for (int node : traversal) {
                                vgraph.setNodeVisited(node);
                        }
                }

                break;
        }           
                        
        default:
                break;
        }
}

Screen displayBfsScreen(sf::RenderWindow &window, const sf::Font &font, VisualGraph vgraph, sf::RectangleShape &rectRing)
{    
        Cursors cursors;

        BfsUIElements ui(font);

        BfsViews views;

        updateBfsViews(window, views, vgraph);
        updateBfsLayout(window, ui);
        updateBorderRing(window, rectRing);
    
        while (window.isOpen()) {
                sf::Event event;

                while (window.pollEvent(event)) {
                        switch (event.type) {

                        case sf::Event::Closed:
                                window.close();
                                return Screen::Exit;
                                break;

                        case sf::Event::Resized: {

                                updateBfsViews(window, views, vgraph);
                                updateBfsLayout(window, ui);
                                updateBorderRing(window, rectRing);
                                break;
                        }

                        case sf::Event::KeyPressed:
                                if (event.key.code == sf::Keyboard::Escape)
                                        return Screen::Menu;

                                break;

                        case sf::Event::MouseButtonPressed:
                                mouseButtonEvent(event, window, vgraph, views, ui);
                                break;

                        default:
                        break;
                        }
                }

                sf::Vector2i mousePixel = sf::Mouse::getPosition(window);
                sf::Vector2f mousePosition = window.mapPixelToCoords(mousePixel, views.uiView);

                window.clear(sf::Color::Black);

                window.setView(views.graphView);
                vgraph.drawGraph(window);

                window.setView(views.uiView);
                ui.drawUI(window);
                if (ui.hoverCheck(mousePosition))
                        window.setMouseCursor(cursors.handCursor);
                else
                        window.setMouseCursor(cursors.normalCursor);

                //window.setView(views.borderView);
                //window.draw(rectRing);
                
                window.display();
        }

    return Screen::Menu;
}