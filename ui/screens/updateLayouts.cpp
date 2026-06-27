#include "updateLayouts.hpp"

void updateGraphEditorLayout(sf::RenderWindow &window, EditorUIElements &ui)
{

        sf::Vector2u windowSize = window.getSize();

        float windowWidth = static_cast<float>(windowSize.x);
        float windowHeight = static_cast<float>(windowSize.y);

        float uiWidth = windowWidth * 0.2f;

        sf::Vector2f compactButtonSize(uiWidth * 0.8f, windowHeight * 0.06f);
        sf::Vector2f defaultButtonSize(uiWidth * 0.8f, windowHeight * 0.1f);

        
        sf::Vector2f exitButtonPosition(uiWidth / 2.0f, windowHeight * 0.06f);
        ui.exitButton.adjustScaling(
                compactButtonSize,
                exitButtonPosition,
                updateTextScale(
                        window,
                        ui.exitButton.getBaseTextPunto()
                )
        );
        ui.exitButton.setOriginCenter();


        sf::Vector2f nodeBoxPosition(uiWidth / 2.0f, windowHeight * 0.8f);
        ui.nodeBox.adjustScaling(
                defaultButtonSize,
                nodeBoxPosition,
                updateTextScale(
                        window,
                        ui.nodeBox.getBaseTextPunto()
                )
        );
        ui.nodeBox.setOriginCenter();

        sf::Vector2f addNodeButtonPosition(uiWidth / 2.0f, windowHeight * 0.915f);
        ui.addNodeButton.adjustScaling(
                defaultButtonSize,
                addNodeButtonPosition,
                updateTextScale(
                        window,
                        ui.addNodeButton.getBaseTextPunto()
                )
        );
        ui.addNodeButton.setOriginCenter();


        sf::Vector2f edgeBoxPosition(uiWidth / 2.0f, windowHeight * 0.55f);
        ui.edgeBox.adjustScaling(
                defaultButtonSize,
                edgeBoxPosition,
                updateTextScale(
                        window,
                        ui.edgeBox.getBaseTextPunto()
                )
        );
        ui.edgeBox.setOriginCenter();

        sf::Vector2f addEdgeButtonPosition(uiWidth / 2.0f, windowHeight * 0.665f);
        ui.addEdgeButton.adjustScaling(
                defaultButtonSize,
                addEdgeButtonPosition,
                updateTextScale(
                        window,
                        ui.addEdgeButton.getBaseTextPunto()
                )
        );
        ui.addEdgeButton.setOriginCenter();

        
        sf::Vector2f clearGraphButtonPosition(uiWidth / 2.0f, windowHeight * 0.15f);
        ui.clearGraphButton.adjustScaling(
                compactButtonSize,
                clearGraphButtonPosition,
                updateTextScale(
                        window,
                        ui.exitButton.getBaseTextPunto()
                )
        );
        ui.clearGraphButton.setOriginCenter();
        
        sf::Vector2f loadGraphButtonPosition(uiWidth / 2.0f, windowHeight * 0.24f);
        ui.loadGraphButton.adjustScaling(
                compactButtonSize,
                loadGraphButtonPosition,
                updateTextScale(
                        window,
                        ui.exitButton.getBaseTextPunto()
                )
        );
        ui.loadGraphButton.setOriginCenter();
        
        sf::Vector2f saveGraphButtonPosition(uiWidth / 2.0f, windowHeight * 0.33f);
        ui.saveGraphButton.adjustScaling(
                compactButtonSize,
                saveGraphButtonPosition,
                updateTextScale(
                        window,
                        ui.exitButton.getBaseTextPunto()
                )
        );
        ui.saveGraphButton.setOriginCenter();
        
        sf::Vector2f centerGraphButtonPosition(uiWidth / 2.0f, windowHeight * 0.42f);
        ui.centerGraphButton.adjustScaling(
                compactButtonSize,
                centerGraphButtonPosition,
                updateTextScale(
                        window,
                        ui.exitButton.getBaseTextPunto()
                )
        );
        ui.centerGraphButton.setOriginCenter();

        ui.bg.setSize(sf::Vector2f(uiWidth, windowHeight));
}


void updateMenuLayout(sf::RenderWindow &window, MenuUIElements &ui)
{
        sf::Vector2u windowSize = window.getSize();

        float windowWidth = static_cast<float>(windowSize.x);
        float windowHeight = static_cast<float>(windowSize.y);

        // Title text
        ui.title.setTextPunto(updateTextScale(window, 50));
        ui.title.setPosition(sf::Vector2f(windowWidth * 0.03f, windowHeight * 0.06f));

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

        ui.graphButton.adjustScaling(
                navButtonSize,
                graphEditorPosition,
                updateTextScale(
                        window,
                        ui.graphButton.getBaseTextPunto()
                )
        );
        ui.bfsButton.adjustScaling(
                navButtonSize,
                BFSPosition,
                updateTextScale(
                        window,
                        ui.bfsButton.getBaseTextPunto()
                )
        );
        ui.dfsButton.adjustScaling(
                navButtonSize,
                DFSPosition,
                updateTextScale(
                        window,
                        ui.dfsButton.getBaseTextPunto()
                )
        );
        
        sf::Vector2f settingsPosition(
                windowWidth * 0.03f,
                windowHeight * 0.89f
        );
        ui.settingsButton.adjustScaling(
                setttingsButtonSize,
                settingsPosition,
                updateTextScale(
                        window,
                        ui.settingsButton.getBaseTextPunto()
                )
        );
}

void updateSettingsLayout(sf::RenderWindow &window, SettingsUIElements &ui)
{

        sf::Vector2u windowSize = window.getSize();

        float windowWidth = static_cast<float>(windowSize.x);
        float windowHeight = static_cast<float>(windowSize.y);

        sf::Vector2f defaultButtonSize(windowWidth * 0.20f, windowHeight * 0.10f);
        sf::Vector2f compactButtonSize(windowWidth * 0.20f, windowHeight * 0.06f);

        ui.title.setTextPunto(updateTextScale(window, 50));
        ui.title.setPosition(
                sf::Vector2f(
                        windowWidth * 0.03f,
                        windowHeight * 0.06f
                )
        );

        ui.smoothScroll.setTextPunto(updateTextScale(window, 30));
        ui.smoothScroll.setPosition(
                sf::Vector2f(
                        windowWidth * 0.03f,
                        windowHeight * 0.25f
                )
        );
        sf::FloatRect smoothScrollBounds = ui.smoothScroll.getLocalBounds();

        sf::Vector2f smoothScrollButtonPosition(
                windowWidth * 0.28f,
                windowHeight * 0.25f + smoothScrollBounds.height / 2 + 5.0f
        );
        ui.smoothScrollButton.adjustScaling(
                defaultButtonSize,
                smoothScrollButtonPosition,
                updateTextScale(
                        window,
                        ui.smoothScrollButton.getBaseTextPunto()
                )
        );

        ui.smoothScrollButton.setOriginCenter();

        sf::Vector2f exitButtonSize(
                windowWidth * 0.2 * 0.8f,
                windowHeight * 0.06f
        );
        sf::Vector2f exitButtonPosition(
                windowWidth * 0.2 / 2.0f + windowWidth * 0.8,
                windowHeight * 0.06f
        );
        ui.exitButton.adjustScaling(
                exitButtonSize,
                exitButtonPosition,
                updateTextScale(
                        window,
                        ui.exitButton.getBaseTextPunto()
                )
        );
        ui.exitButton.setOriginCenter();

        sf::Vector2f savePosition(
                windowWidth * 0.03f,
                windowHeight * 0.89f
        );
        ui.saveButton.adjustScaling(
                compactButtonSize,
                savePosition,
                updateTextScale(
                        window,
                        ui.saveButton.getBaseTextPunto()
                )
        );
}

void updateBfsLayout(sf::RenderWindow &window, BfsUIElements &ui)
{
        sf::Vector2u windowSize = window.getSize();

        float windowWidth = static_cast<float>(windowSize.x);
        float windowHeight = static_cast<float>(windowSize.y);

        sf::Vector2f defaultButtonSize(windowWidth * 0.10f, windowHeight * 0.10f);

        float uiViewHeight = windowHeight * 0.2;

        sf::Vector2f playpauseButtonPosition(
                windowWidth / 2.0f, 
                uiViewHeight / 2.0f
        );
        ui.playpause.adjustScaling(
                defaultButtonSize,
                playpauseButtonPosition,
                updateTextScale(
                        window,
                        ui.playpause.getBaseTextPunto()
                )
        );
        ui.playpause.setOriginCenter();
}