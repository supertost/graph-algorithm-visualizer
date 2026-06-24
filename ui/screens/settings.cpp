#include "settings.hpp"
#include "../../io/readwrite.hpp"

#include <iostream>

Screen mouseButtonEvent(
                sf::Event &event,
                sf::RenderWindow &window,
                Config &config,
                Button &exitButton,
                Button &smoothScrollButton,
                Button &saveButton
        )
{
        switch (event.mouseButton.button) {

        case sf::Mouse::Left: {
                sf::Vector2i mousePixel(event.mouseButton.x, event.mouseButton.y);
                sf::Vector2f mousePositionClickForUI = window.mapPixelToCoords(mousePixel);

                if (exitButton.isClicked(mousePositionClickForUI))
                        return Screen::Menu;

                if (smoothScrollButton.isClicked(mousePositionClickForUI)) {
                        config.smoothScroll = !config.smoothScroll;
                                
                        if (config.smoothScroll == 1)
                                smoothScrollButton.setText("On");
                        else
                                smoothScrollButton.setText("Off");

                        std::cout << "Smoothscroll: " << config.smoothScroll << "\n"; 
                }

                if (saveButton.isClicked(mousePositionClickForUI))
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
        sf::Cursor normalCursor;
        normalCursor.loadFromSystem(sf::Cursor::Arrow);
        
        sf::Cursor handCursor;
        handCursor.loadFromSystem(sf::Cursor::Hand);


        sf::Vector2u windowSize = window.getSize();

        float windowWidth = static_cast<float>(windowSize.x);
        float windowHeight = static_cast<float>(windowSize.y);


    
        Label title(
                "Settings",
                font,
                titleStyle,
                sf::Vector2f(40.0f, 30.f)
        );
    
        Button exitButton(
                "<- Menu", 
                sf::Vector2f(0.0f, 0.0f),
                sf::Vector2f(0.0f, 0.0f),
                font,
                compactButton,
                hoverCompactButton
        );
        
        std::string smoothState = "Off";
        if (config.smoothScroll == 1)
                smoothState = "On";

        Label smoothScroll(
                "Smooth Scroll",
                font,
                subtitleStyle,
                sf::Vector2f(0.0f, 0.0f)
        );

        Button smoothScrollButton(
                smoothState,
                sf::Vector2f(0.0f, 0.0f),
                sf::Vector2f(0.0f, 0.0f),
                font,
                compactButton,
                hoverCompactButton
        );
        

        Button saveButton(
                "Save",
                sf::Vector2f(0.0f, 0.0f),
                sf::Vector2f(0.0f, 0.0f),
                font,
                defaultButton,
                hoverDefaultButton
        );

        updateSettingsLayout(
                window,
                exitButton,
                title,
                smoothScroll,
                smoothScrollButton,
                saveButton
        );
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

                                updateSettingsLayout(
                                        window,
                                        exitButton,
                                        title,
                                        smoothScroll,
                                        smoothScrollButton,
                                        saveButton
                                );
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
                                        exitButton,
                                        smoothScrollButton,
                                        saveButton
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

        sf::Vector2i mousePixel = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosition = window.mapPixelToCoords(mousePixel);

        title.drawLabel(window);

        smoothScroll.drawLabel(window);
        smoothScrollButton.drawButton(window);
        bool smoothScrollHover = smoothScrollButton.hoverState(mousePosition);

        exitButton.drawButton(window);
        bool exitHover = exitButton.hoverState(mousePosition);

        saveButton.drawButton(window);
        bool saveHover = saveButton.hoverState(mousePosition);

        if (exitHover || smoothScrollHover || saveHover)
            window.setMouseCursor(handCursor);
        else
            window.setMouseCursor(normalCursor);

        window.draw(rectRing);
        
        window.display();
    }

    return Screen::Menu;
}