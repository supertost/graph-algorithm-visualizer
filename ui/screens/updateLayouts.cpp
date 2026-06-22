#include "updateLayouts.hpp"

void updateGraphEditorLayout(
                sf::RenderWindow &window, 
                Button &exitButton, 
                Textbox &nodeBox, 
                Button &addNodeButton, 
                Textbox &edgeBox, 
                Button &addEdgeButton, 
                sf::RectangleShape &uibg, 
                Button &clearGraphButton, 
                Button &loadGraphButton, 
                Button &saveGraphButton, 
                Button &centerGraphButton
        )
{

        sf::Vector2u windowSize = window.getSize();

        float windowWidth = static_cast<float>(windowSize.x);
        float windowHeight = static_cast<float>(windowSize.y);

        float uiWidth = windowWidth * 0.2f;

        sf::Vector2f compactButtonSize(uiWidth * 0.8f, windowHeight * 0.06f);
        sf::Vector2f normalButtonSize(uiWidth * 0.8f, windowHeight * 0.1f);

        
        sf::Vector2f exitButtonPosition(uiWidth / 2.0f, windowHeight * 0.06f);
        exitButton.adjustScaling(compactButtonSize, exitButtonPosition, updateTextScale(window, exitButton.getTextPunto()));
        exitButton.setOriginCenter();


        sf::Vector2f nodeBoxPosition(uiWidth / 2.0f, windowHeight * 0.8f);
        nodeBox.adjustScaling(normalButtonSize, nodeBoxPosition, updateTextScale(window, nodeBox.characterSize));
        nodeBox.setOriginCenter();

        sf::Vector2f addNodeButtonPosition(uiWidth / 2.0f, windowHeight * 0.915f);
        addNodeButton.adjustScaling(normalButtonSize, addNodeButtonPosition, updateTextScale(window, exitButton.getTextPunto()));
        addNodeButton.setOriginCenter();


        sf::Vector2f edgeBoxPosition(uiWidth / 2.0f, windowHeight * 0.55f);
        edgeBox.adjustScaling(normalButtonSize, edgeBoxPosition, updateTextScale(window, edgeBox.characterSize));
        edgeBox.setOriginCenter();

        sf::Vector2f addEdgeButtonPosition(uiWidth / 2.0f, windowHeight * 0.665f);
        addEdgeButton.adjustScaling(normalButtonSize, addEdgeButtonPosition, updateTextScale(window, exitButton.getTextPunto()));
        addEdgeButton.setOriginCenter();

        
        sf::Vector2f clearGraphButtonPosition(uiWidth / 2.0f, windowHeight * 0.15f);
        clearGraphButton.adjustScaling(compactButtonSize, clearGraphButtonPosition, updateTextScale(window, exitButton.getTextPunto()));
        clearGraphButton.setOriginCenter();
        
        sf::Vector2f loadGraphButtonPosition(uiWidth / 2.0f, windowHeight * 0.24f);
        loadGraphButton.adjustScaling(compactButtonSize, loadGraphButtonPosition, updateTextScale(window, exitButton.getTextPunto()));
        loadGraphButton.setOriginCenter();
        
        sf::Vector2f saveGraphButtonPosition(uiWidth / 2.0f, windowHeight * 0.33f);
        saveGraphButton.adjustScaling(compactButtonSize, saveGraphButtonPosition, updateTextScale(window, exitButton.getTextPunto()));
        saveGraphButton.setOriginCenter();
        
        sf::Vector2f centerGraphButtonPosition(uiWidth / 2.0f, windowHeight * 0.42f);
        centerGraphButton.adjustScaling(compactButtonSize, centerGraphButtonPosition, updateTextScale(window, exitButton.getTextPunto()));
        centerGraphButton.setOriginCenter();

        uibg.setSize(sf::Vector2f(uiWidth, windowHeight));
}