#include "bfsScreen.hpp"

void updateBfsViews(sf::RenderWindow &window)
{
        (void)window;
}

void updateBfsLayout(sf::RenderWindow &window)
{
        (void)window;
}

void mouseButtonEvent(sf::Event &event, sf::RenderWindow &window)
{
        switch (event.mouseButton.button) {

        case sf::Mouse::Left: {
                sf::Vector2i mousePixel(event.mouseButton.x, event.mouseButton.y);
                sf::Vector2f mousePositionClickForUI = window.mapPixelToCoords(mousePixel);

                (void) mousePositionClickForUI;

                break;
        }           
                        
        default:
                break;
        }
}

Screen displaySettings(sf::RenderWindow &window, const sf::Font &font, sf::RectangleShape &rectRing)
{    
        sf::Vector2u windowSize = window.getSize();

        float windowWidth = static_cast<float>(windowSize.x);
        float windowHeight = static_cast<float>(windowSize.y);

        (void)windowWidth, (void)windowHeight;
        (void)font;

        sf::View graphView;
        sf::View uiView;

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
                                sf::FloatRect bfsView(0.0f, 0.0f, event.size.width, event.size.height);
                                window.setView(sf::View(bfsView));

                                updateBfsLayout(window);
                                updateBorderRing(window, rectRing);
                                break;
                        }

                        case sf::Event::KeyPressed:
                                if (event.key.code == sf::Keyboard::Escape)
                                        return Screen::Menu;

                                break;

                        case sf::Event::MouseButtonPressed:
                                mouseButtonEvent(event, window);
                                break;

                        default:
                        break;
                        }
                }        

                window.clear(sf::Color::Black);

                window.draw(rectRing);
                
                window.display();
        }

    return Screen::Menu;
}