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
        sf::Vector2f defaultButtonSize(uiWidth * 0.8f, windowHeight * 0.1f);

        
        sf::Vector2f exitButtonPosition(uiWidth / 2.0f, windowHeight * 0.06f);
        exitButton.adjustScaling(
                compactButtonSize,
                exitButtonPosition,
                updateTextScale(
                        window,
                        exitButton.getBaseTextPunto()
                )
        );
        exitButton.setOriginCenter();


        sf::Vector2f nodeBoxPosition(uiWidth / 2.0f, windowHeight * 0.8f);
        nodeBox.adjustScaling(
                defaultButtonSize,
                nodeBoxPosition,
                updateTextScale(
                        window,
                        nodeBox.getBaseTextPunto()
                )
        );
        nodeBox.setOriginCenter();

        sf::Vector2f addNodeButtonPosition(uiWidth / 2.0f, windowHeight * 0.915f);
        addNodeButton.adjustScaling(
                defaultButtonSize,
                addNodeButtonPosition,
                updateTextScale(
                        window,
                        addNodeButton.getBaseTextPunto()
                )
        );
        addNodeButton.setOriginCenter();


        sf::Vector2f edgeBoxPosition(uiWidth / 2.0f, windowHeight * 0.55f);
        edgeBox.adjustScaling(
                defaultButtonSize,
                edgeBoxPosition,
                updateTextScale(
                        window,
                        edgeBox.getBaseTextPunto()
                )
        );
        edgeBox.setOriginCenter();

        sf::Vector2f addEdgeButtonPosition(uiWidth / 2.0f, windowHeight * 0.665f);
        addEdgeButton.adjustScaling(
                defaultButtonSize,
                addEdgeButtonPosition,
                updateTextScale(
                        window,
                        addEdgeButton.getBaseTextPunto()
                )
        );
        addEdgeButton.setOriginCenter();

        
        sf::Vector2f clearGraphButtonPosition(uiWidth / 2.0f, windowHeight * 0.15f);
        clearGraphButton.adjustScaling(
                compactButtonSize,
                clearGraphButtonPosition,
                updateTextScale(
                        window,
                        exitButton.getBaseTextPunto()
                )
        );
        clearGraphButton.setOriginCenter();
        
        sf::Vector2f loadGraphButtonPosition(uiWidth / 2.0f, windowHeight * 0.24f);
        loadGraphButton.adjustScaling(
                compactButtonSize,
                loadGraphButtonPosition,
                updateTextScale(
                        window,
                        exitButton.getBaseTextPunto()
                )
        );
        loadGraphButton.setOriginCenter();
        
        sf::Vector2f saveGraphButtonPosition(uiWidth / 2.0f, windowHeight * 0.33f);
        saveGraphButton.adjustScaling(
                compactButtonSize,
                saveGraphButtonPosition,
                updateTextScale(
                        window,
                        exitButton.getBaseTextPunto()
                )
        );
        saveGraphButton.setOriginCenter();
        
        sf::Vector2f centerGraphButtonPosition(uiWidth / 2.0f, windowHeight * 0.42f);
        centerGraphButton.adjustScaling(
                compactButtonSize,
                centerGraphButtonPosition,
                updateTextScale(
                        window,
                        exitButton.getBaseTextPunto()
                )
        );
        centerGraphButton.setOriginCenter();

        uibg.setSize(sf::Vector2f(uiWidth, windowHeight));
}


void updateMenuLayout(
                sf::RenderWindow &window,
                Label &title,
                Button &graphButton,
                Button &bfsButton,
                Button &dfsButton,
                Button &settingsButton
        )
{
        sf::Vector2u windowSize = window.getSize();

        float windowWidth = static_cast<float>(windowSize.x);
        float windowHeight = static_cast<float>(windowSize.y);

        // Title text
        title.setTextPunto(updateTextScale(window, 50));
        title.setPosition(sf::Vector2f(windowWidth * 0.03f, windowHeight * 0.06f));

        // Menu nav buttons
        sf::Vector2f navButtonSize(windowWidth * 0.20f, windowHeight * 0.10f);
        sf::Vector2f setttingsButtonSize(windowWidth * 0.20f, windowHeight * 0.06f);

        // Menu nav buttons positions
        sf::Vector2f graphEditorPosition(
                windowWidth * 0.03f,
                windowHeight * 0.2f
        );
        sf::Vector2f BFSPosition(
                windowWidth * 0.03f,
                windowHeight * 0.2f + navButtonSize.y * 1.0f + windowHeight * 0.04f * 1.0f
        );
        sf::Vector2f DFSPosition(
                windowWidth * 0.03f,
                windowHeight * 0.2f + navButtonSize.y * 2.0f + windowHeight * 0.04f * 2.0f
        );

        graphButton.adjustScaling(
                navButtonSize,
                graphEditorPosition,
                updateTextScale(
                        window,
                        graphButton.getBaseTextPunto()
                )
        );
        bfsButton.adjustScaling(
                navButtonSize,
                BFSPosition,
                updateTextScale(
                        window,
                        bfsButton.getBaseTextPunto()
                )
        );
        dfsButton.adjustScaling(
                navButtonSize,
                DFSPosition,
                updateTextScale(
                        window,
                        dfsButton.getBaseTextPunto()
                )
        );
        
        sf::Vector2f settingsPosition(
                windowWidth * 0.03f,
                windowHeight * 0.89f
        );
        settingsButton.adjustScaling(
                setttingsButtonSize,
                settingsPosition,
                updateTextScale(
                        window,
                        settingsButton.getBaseTextPunto()
                )
        );
}

void updateSettingsLayout(
                sf::RenderWindow &window,
                Button &exitButton,
                Label &title,
                Label &smoothScroll,
                Button &smoothScrollButton,
                Button &saveButton
        )
{

        sf::Vector2u windowSize = window.getSize();

        float windowWidth = static_cast<float>(windowSize.x);
        float windowHeight = static_cast<float>(windowSize.y);

        sf::Vector2f defaultButtonSize(windowWidth * 0.20f, windowHeight * 0.10f);
        sf::Vector2f compactButtonSize(windowWidth * 0.20f, windowHeight * 0.06f);

        title.setTextPunto(updateTextScale(window, 50));
        title.setPosition(
                sf::Vector2f(
                        windowWidth * 0.03f,
                        windowHeight * 0.06f
                )
        );

        smoothScroll.setTextPunto(updateTextScale(window, 30));
        smoothScroll.setPosition(
                sf::Vector2f(
                        windowWidth * 0.03f,
                        windowHeight * 0.25f
                )
        );
        sf::FloatRect smoothScrollBounds = smoothScroll.getLocalBounds();

        sf::Vector2f smoothScrollButtonPosition(
                windowWidth * 0.28f,
                windowHeight * 0.25f + smoothScrollBounds.height / 2 + 5.0f
        );
        smoothScrollButton.adjustScaling(
                defaultButtonSize,
                smoothScrollButtonPosition,
                updateTextScale(
                        window,
                        smoothScrollButton.getBaseTextPunto()
                )
        );

        smoothScrollButton.setOriginCenter();

        sf::Vector2f exitButtonSize(
                windowWidth * 0.2 * 0.8f,
                windowHeight * 0.06f
        );
        sf::Vector2f exitButtonPosition(
                windowWidth * 0.2 / 2.0f + windowWidth * 0.8,
                windowHeight * 0.06f
        );
        exitButton.adjustScaling(
                exitButtonSize,
                exitButtonPosition,
                updateTextScale(
                        window,
                        exitButton.getBaseTextPunto()
                )
        );
        exitButton.setOriginCenter();

        sf::Vector2f savePosition(
                windowWidth * 0.03f,
                windowHeight * 0.89f
        );
        saveButton.adjustScaling(
                compactButtonSize,
                savePosition,
                updateTextScale(
                        window,
                        saveButton.getBaseTextPunto()
                )
        );
}