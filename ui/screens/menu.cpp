#include "menu.hpp"

Screen displayMenu(
                sf::RenderWindow &window,
                sf::Font &font,
                sf::RectangleShape &rectRing
        )
{
        // Cursor for buttons and normal use
        sf::Cursor normalCursor;
        normalCursor.loadFromSystem(sf::Cursor::Arrow);
        
        sf::Cursor handCursor;
        handCursor.loadFromSystem(sf::Cursor::Hand);



        sf::Vector2u windowSize = window.getSize();
        float windowWidth = static_cast<float>(windowSize.x);
        float windowHeight = static_cast<float>(windowSize.y);


        // Title Text
        Label title(
                "Graph Algorithm Visualizer",
                font,
                titleStyle,
                sf::Vector2f(40.0f, 30.f)
        );

        // Graph Edit Button
        sf::Vector2f buttonSize(250.0f, 70.0f);
        sf::Vector2f buttonPosition(0.0f, 0.0f);

        Button graphButton(
                "Graph Editor",
                buttonSize,
                buttonPosition,
                font,
                normalButton,
                hoverNormalButton
        );
        
        Button bfsButton(
                "Run BFS",
                buttonSize,
                buttonPosition,
                font,
                normalButton,
                hoverNormalButton
        );

        Button dfsButton(
                "Run DFS",
                buttonSize,
                buttonPosition,
                font,
                normalButton,
                hoverNormalButton
        );
        
        Button settingsButton(
                "Settings",
                buttonSize,
                buttonPosition,
                font,
                normalButton,
                hoverNormalButton
        );

    
    sf::FloatRect visibleArea(0.0f, 0.0f, static_cast<float>(windowWidth), static_cast<float>(windowHeight));
    window.setView(sf::View(visibleArea));
    updateMenuLayout(window, title, graphButton, bfsButton, dfsButton, settingsButton);

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
                    
                    sf::FloatRect visibleArea(0.0f, 0.0f, static_cast<float>(event.size.width), static_cast<float>(event.size.height));

                    window.setView(sf::View(visibleArea));
                    updateMenuLayout(window, title, graphButton, bfsButton, dfsButton, settingsButton);
                    updateBorderRing(window, rectRing);
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

                        if (settingsButton.isClicked(mousePositionClick))
                            return Screen::Settings;
                    }

                    break;
            
                default:
                    break;
            }
        }

        window.clear(sf::Color::Black);

        window.draw(rectRing);


        title.drawLabel(window);

        sf::Vector2f mousePosition(static_cast<float>(event.mouseMove.x), static_cast<float>(event.mouseMove.y));

        graphButton.drawButton(window);
        bool graphEditorHover = graphButton.hoverState(mousePosition);
        
        bfsButton.drawButton(window);
        bool bfsHover = bfsButton.hoverState(mousePosition);

        dfsButton.drawButton(window);
        bool dfsHover = dfsButton.hoverState(mousePosition);

        settingsButton.drawButton(window);
        bool settingsHover = settingsButton.hoverState(mousePosition);

        if (graphEditorHover || bfsHover || dfsHover || settingsHover) {

            window.setMouseCursor(handCursor);
        }

        else {

            window.setMouseCursor(normalCursor);
        }

        window.display();
    }

    return Screen::Exit;
}