#include "menu.hpp"
#include "menuElements.hpp"

Screen displayMenu(
                sf::RenderWindow &window,
                sf::Font &font,
                sf::RectangleShape &rectRing
        )
{
        // Cursor for buttons and normal use
        Cursors cursors;


        sf::Vector2u windowSize = window.getSize();
        float windowWidth = static_cast<float>(windowSize.x);
        float windowHeight = static_cast<float>(windowSize.y);


        MenuUIElements ui(font);

    
        sf::FloatRect visibleArea(
                0.0f,
                0.0f,
                static_cast<float>(windowWidth),
                static_cast<float>(windowHeight)
        );
        window.setView(sf::View(visibleArea));
        updateMenuLayout(window, ui);

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
                                sf::FloatRect visibleArea(
                                        0.0f, 
                                        0.0f,
                                        static_cast<float>(event.size.width),
                                        static_cast<float>(event.size.height)
                                );

                                window.setView(sf::View(visibleArea));
                                updateMenuLayout(window, ui);
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
                                        sf::Vector2f mousePositionClick(
                                                static_cast<float>(event.mouseButton.x),
                                                static_cast<float>(event.mouseButton.y)
                                        );

                                        if (ui.graphButton.isClicked(mousePositionClick))
                                                return Screen::Graph;

                                        if (ui.settingsButton.isClicked(mousePositionClick))
                                                return Screen::Settings;

                                        if (ui.bfsButton.isClicked(mousePositionClick))
                                                return Screen::BFS;
                                }

                                break;
            
                        default:
                                break;
                        }
                }

                window.clear(sf::Color::Black);

                window.draw(rectRing);

                ui.drawUI(window);

                sf::Vector2i mousePixel = sf::Mouse::getPosition(window);
                sf::Vector2f mousePosition = window.mapPixelToCoords(mousePixel);

                if (ui.hoverCheck(mousePosition))
                        window.setMouseCursor(cursors.handCursor);
                else
                        window.setMouseCursor(cursors.normalCursor);

                window.display();
        }

        return Screen::Exit;
}