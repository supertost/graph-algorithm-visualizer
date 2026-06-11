#include <SFML/Graphics.hpp>

#include "screens/menu.hpp"
#include "screens/graphEditor.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Graph Algorithm Visualizer");

    // Setting up font
    sf::Font font;
    if (!font.loadFromFile("ui/fonts/AdwaitaSans-Regular.ttf"))
        return EXIT_FAILURE;


    Screen currentScreen = Screen::Menu;

    while (window.isOpen() && currentScreen != Screen::Exit) {

        switch (currentScreen) {
    
            case Screen::Menu:
    
                currentScreen = displayMenu(window, font);
                break;


            case Screen::Graph: // For adding nodes into the graph and such

                currentScreen = displayGraphEditor(window, font);
                break;

            default:
                break;   
        }
    }

    return 0;
}