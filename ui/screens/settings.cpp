#include "settings.hpp"
#include "settingsElements.hpp"
#include "../../io/readwrite.hpp"

#include <iostream>

Screen mouseButtonEvent(
                sf::Event &event,
                sf::RenderWindow &window,
                Config &config,
                SettingsUIElements &ui
        )
{
        switch (event.mouseButton.button) {

        case sf::Mouse::Left: {
                sf::Vector2i mousePixel(event.mouseButton.x, event.mouseButton.y);
                sf::Vector2f mousePositionClickForUI = window.mapPixelToCoords(mousePixel);

                if (ui.exitButton.isClicked(mousePositionClickForUI))
                        return Screen::Menu;

                if (ui.smoothScrollButton.isClicked(mousePositionClickForUI)) {
                        config.smoothScroll = !config.smoothScroll;
                                
                        if (config.smoothScroll == 1)
                                ui.smoothScrollButton.setText("On");
                        else
                                ui.smoothScrollButton.setText("Off");

                        std::cout << "Smoothscroll: " << config.smoothScroll << "\n"; 
                }

                if (ui.saveButton.isClicked(mousePositionClickForUI))
                        saveConfig(config);

                break;
        }
                        
                default:
                        break;
        }

        return Screen::Settings;
}

Screen displaySettings(
                sf::RenderWindow &window,
                const sf::Font &font,
                sf::RectangleShape &rectRing,
                Config &config
        )
{
        Cursors cursors;

        sf::Vector2u windowSize = window.getSize();

        float windowWidth = static_cast<float>(windowSize.x);
        float windowHeight = static_cast<float>(windowSize.y);
        
        std::string smoothState = "Off";
        if (config.smoothScroll == 1)
                smoothState = "On";

        SettingsUIElements ui(font, smoothState);

        updateSettingsLayout(window, ui);
        updateBorderRing(window, rectRing);

    
    sf::FloatRect visibleArea(0.0f, 0.0f, windowWidth, windowHeight);
    window.setView(sf::View(visibleArea));

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
                                        0.0f, 0.0f,
                                        event.size.width, event.size.height
                                );
                                window.setView(sf::View(visibleArea));

                                updateSettingsLayout(window, ui);
                                updateBorderRing(window, rectRing);
                                break;
                        }

                        case sf::Event::KeyPressed:
                                if (event.key.code == sf::Keyboard::Escape)
                                        return Screen::Menu;

                                break;

                        case sf::Event::MouseButtonPressed: {
                                Screen screenToGo = mouseButtonEvent(
                                        event,
                                        window,
                                        config,
                                        ui
                                );

                                if (screenToGo != Screen::Settings)
                                        return screenToGo;

                                break;
                        }
            
                        default:
                                break;
            }
        }        

        window.clear(sf::Color::Black);

        ui.drawUI(window);

        sf::Vector2i mousePixel = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosition = window.mapPixelToCoords(mousePixel);

        if (ui.checkHover(mousePosition))
            window.setMouseCursor(cursors.handCursor);
        else
            window.setMouseCursor(cursors.normalCursor);

        window.draw(rectRing);
        
        window.display();
    }

    return Screen::Menu;
}