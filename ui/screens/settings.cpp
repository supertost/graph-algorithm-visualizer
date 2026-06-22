#include "settings.hpp"
#include "../../io/readwrite.hpp"

#include <iostream>


void updateSettingsLayout(sf::RenderWindow &window, Button &exitButton, Label &title, Label &smoothScroll, Button &smoothScrollButton, Button &saveButton) {

    sf::Vector2u windowSize = window.getSize();

    float windowWidth = static_cast<float>(windowSize.x);
    float windowHeight = static_cast<float>(windowSize.y);

    title.setTextPunto(updateTextScale(window, 50));
    title.setPosition(sf::Vector2f(windowWidth * 0.03f, windowHeight * 0.06f));

    smoothScroll.setTextPunto(updateTextScale(window, 30));
    smoothScroll.setPosition(sf::Vector2f(windowWidth * 0.03f, windowHeight * 0.25f));
    sf::FloatRect smoothScrollBounds = smoothScroll.getLocalBounds();

    sf::Vector2f smoothScrollButtonSize(windowWidth * 0.2 * 0.8f, windowHeight * 0.06f);
    sf::Vector2f smoothScrollButtonPosition(windowWidth * 0.28f, windowHeight * 0.25f + smoothScrollBounds.height / 2 + 5.0f);
    smoothScrollButton.adjustScaling(smoothScrollButtonSize, smoothScrollButtonPosition, updateTextScale(window, smoothScrollButton.textPunto));
    smoothScrollButton.setOriginCenter();


    sf::Vector2f exitButtonSize(windowWidth * 0.2 * 0.8f, windowHeight * 0.06f);
    sf::Vector2f exitButtonPosition(windowWidth * 0.2 / 2.0f + windowWidth * 0.8, windowHeight * 0.06f);
    exitButton.adjustScaling(exitButtonSize, exitButtonPosition, updateTextScale(window, exitButton.textPunto));
    exitButton.setOriginCenter();

    sf::Vector2f saveButtonSize(windowWidth * 0.20f, windowHeight * 0.06f);
    sf::Vector2f savePosition(windowWidth * 0.03f, windowHeight * 0.89f);
    saveButton.adjustScaling(saveButtonSize, savePosition, updateTextScale(window, saveButton.textPunto));
}

Screen displaySettings(sf::RenderWindow &window, const sf::Font &font, sf::RectangleShape &rectRing, Config &config) {

    sf::Cursor normalCursor;
    normalCursor.loadFromSystem(sf::Cursor::Arrow);
    
    sf::Cursor handCursor;
    handCursor.loadFromSystem(sf::Cursor::Hand);


    sf::Vector2u windowSize = window.getSize();

    float windowWidth = static_cast<float>(windowSize.x);
    float windowHeight = static_cast<float>(windowSize.y);


    
    Label title("Settings", font, 50, sf::Text::Bold, sf::Color(237, 98, 28), sf::Vector2f(40.0f, 30.f));
    
    sf::Vector2f buttonSize(windowWidth * 0.10f, windowHeight * 0.05f);
    sf::Vector2f buttonPosition(0.0f, 0.0f);
    Button exitButton(buttonSize, buttonPosition, sf::Color::Transparent, sf::Color(237, 98, 28), 2.0f, "<- Menu", font, 20, sf::Color(237, 98, 28));
    
    std::string smoothState = "Off";
    if (config.smoothScroll == 1)
        smoothState = "On";

    Label smoothScroll("Smooth Scroll", font, 30, sf::Text::Bold, sf::Color(237, 98, 28), sf::Vector2f(0.0f, 0.0f));
    Button smoothScrollButton(buttonSize, buttonPosition, sf::Color::Transparent, sf::Color(237, 98, 28), 2.0f, smoothState, font, 20, sf::Color(237, 98, 28));
    

    Button saveButton(buttonSize, buttonPosition, sf::Color::Transparent, sf::Color(237, 98, 28), 2.0f, "Save", font, 30, sf::Color(237, 98, 28));

    updateSettingsLayout(window, exitButton, title, smoothScroll, smoothScrollButton, saveButton);
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

                    sf::FloatRect visibleArea(0.0f, 0.0f, event.size.width, event.size.height);
                    window.setView(sf::View(visibleArea));

                    updateSettingsLayout(window, exitButton, title, smoothScroll, smoothScrollButton, saveButton);
                    updateBorderRing(window, rectRing);
                    break;
                }

                case sf::Event::KeyPressed:

                    if (event.key.code == sf::Keyboard::Escape)
                        return Screen::Menu;

                    break;

                case sf::Event::MouseButtonPressed:
                    
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

                    break;

            
                default:
                    break;
            }
        }        

        window.clear(sf::Color::Black);

        sf::Vector2f mousePosition(event.mouseMove.x, event.mouseMove.y);

        title.drawLabel(window);

        smoothScroll.drawLabel(window);
        smoothScrollButton.drawButton(window);
        bool smoothScrollHover = smoothScrollButton.hoverState(mousePosition, sf::Color(237, 98, 28), sf::Color::Black);

        exitButton.drawButton(window);
        bool exitHover = exitButton.hoverState(mousePosition, sf::Color(237, 98, 28), sf::Color::Black);

        saveButton.drawButton(window);
        bool saveHover = saveButton.hoverState(mousePosition, sf::Color(237, 98, 28), sf::Color::Black);

        if (exitHover || smoothScrollHover || saveHover)
            window.setMouseCursor(handCursor);
        else
            window.setMouseCursor(normalCursor);

        window.draw(rectRing);
        
        window.display();
    }

    return Screen::Menu;
}