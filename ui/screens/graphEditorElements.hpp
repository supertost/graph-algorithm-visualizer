#ifndef GRAPH_EDITOR_UI
#define GRAPH_EDITOR_UI

#include "screens.hpp"
#include "styles.hpp"

struct EditorViews
{
        sf::View graphView;
        sf::View uiView;
        sf::View borderView;
};

struct EditorState
{
        bool showNodeErrorPopUp = false;
        bool showEdgeErrorPopUp = false;
        bool showNodeDelErrorPopUp = false;
        bool showEdgeDelErrorPopUp = false;

        bool isPanningGraph = false;
        sf::Vector2i lastPanPixel;

        bool isNodeClicked = false;
        int clickedNode = 0;

        float currentZoom = 1.0f;
        float targetZoom = 1.0f;
};

struct EditorUIElements
{
        Button exitButton;
        Button addNodeButton;
        Button deleteNodeButton;
        Button addEdgeButton;
        Button deleteEdgeButton;
        Button clearGraphButton;
        Button loadGraphButton;
        Button saveGraphButton;
        Button centerGraphButton;

        Textbox nodeBox;
        Textbox edgeBox;

        sf::RectangleShape bg;

        EditorUIElements(const sf::Font &font)
                : 
                exitButton(
                        "<- Menu",
                        sf::Vector2f(0.0f, 0.0f),
                        sf::Vector2f(0.0f, 0.0f),
                        font,
                        compactButton,
                        hoverCompactButton
                ),
                addNodeButton(
                        "Add",
                        sf::Vector2f(0.0f, 0.0f),
                        sf::Vector2f(3.0f, 130.0f),
                        font,
                        defaultButton,
                        hoverDefaultButton
                ),
                deleteNodeButton(
                        "Del",
                        sf::Vector2f(0.0f, 0.0f),
                        sf::Vector2f(3.0f, 130.0f),
                        font,
                        defaultButton,
                        hoverDefaultButton
                ),
                addEdgeButton(
                        "Add",
                        sf::Vector2f(0.0f, 0.0f),
                        sf::Vector2f(3.0f, 130.0f),
                        font,
                        defaultButton,
                        hoverDefaultButton
                ),
                deleteEdgeButton(
                        "Del",
                        sf::Vector2f(0.0f, 0.0f),
                        sf::Vector2f(3.0f, 130.0f),
                        font,
                        defaultButton,
                        hoverDefaultButton
                ),
                clearGraphButton(
                        "Clear Graph",
                        sf::Vector2f(0.0f, 0.0f),
                        sf::Vector2f(3.0f, 130.0f),
                        font,
                        compactButton,
                        hoverCompactButton
                ),
                loadGraphButton(
                        "Load Graph",
                        sf::Vector2f(0.0f, 0.0f),
                        sf::Vector2f(3.0f, 130.0f),
                        font,
                        compactButton,
                        hoverCompactButton
                ),
                saveGraphButton(
                        "Save Graph",
                        sf::Vector2f(0.0f, 0.0f),
                        sf::Vector2f(3.0f, 130.0f),
                        font,
                        compactButton,
                        hoverCompactButton
                ),
                centerGraphButton(
                        "Center Graph",
                        sf::Vector2f(0.0f, 0.0f),
                        sf::Vector2f(3.0f, 130.0f),
                        font,
                        compactButton,
                        hoverCompactButton
                ),
                nodeBox(
                        sf::Vector2f(0.0f, 0.0f),
                        sf::Vector2f(3.0f, 3.0f),
                        font,
                        "Add a node",
                        defaultTextbox
                ),
                edgeBox(
                        sf::Vector2f(0.0f, 0.0f),
                        sf::Vector2f(3.0f, 3.0f),
                        font,
                        "Edge (eg. 2 3)",
                        defaultTextbox
                )
        {
                bg.setFillColor(sf::Color(0, 0, 0, 200));
        }

        void drawUI(sf::RenderWindow &window)
        {
                window.draw(bg);

                exitButton.drawButton(window);

                nodeBox.drawTextbox(window);
                addNodeButton.drawButton(window);
                deleteNodeButton.drawButton(window);

                edgeBox.drawTextbox(window);
                addEdgeButton.drawButton(window);
                deleteEdgeButton.drawButton(window);

                clearGraphButton.drawButton(window);
                loadGraphButton.drawButton(window);

                saveGraphButton.drawButton(window);
                centerGraphButton.drawButton(window);

        }

        bool checkHover(sf::Vector2f mousePosition)
        {
                bool exitButtonHover = exitButton.hoverState(mousePosition);
                bool addNodeHover = addNodeButton.hoverState(mousePosition);
                bool deleteNodeHover = deleteNodeButton.hoverState(mousePosition);
                bool addEdgeHover = addEdgeButton.hoverState(mousePosition);
                bool deleteEdgeHover = deleteEdgeButton.hoverState(mousePosition);
                bool clearGraphHover = clearGraphButton.hoverState(mousePosition);
                bool loadGraphHover = loadGraphButton.hoverState(mousePosition);
                bool saveGraphHover = saveGraphButton.hoverState(mousePosition);
                bool centerGraphHover = centerGraphButton.hoverState(mousePosition);

                if (
                        addNodeHover
                        || deleteNodeHover
                        || addEdgeHover
                        || deleteEdgeHover
                        || exitButtonHover
                        || clearGraphHover
                        || loadGraphHover
                        || saveGraphHover
                        || centerGraphHover
                ) {
                        return true;
                }

                return false;
        }
};

struct EditorPopUps
{
        PopUp nodeErrorPopUp;
        PopUp edgeErrorPopUp;

        PopUp nodeDelErrorPopUp;
        PopUp edgeDelErrorPopUp;

        EditorPopUps(const sf::Font &font, sf::RenderWindow &window, sf::Vector2f size)
                : 
                nodeErrorPopUp(
                        "Cannot Add Node",
                        "The node you are trying to\n\nadd is already in the graph",
                        "OK",
                        font,
                        size,
                        popUpDefault,
                        window
                ),
                edgeErrorPopUp(
                        "Cannot Add Edge",
                        "The edge you are trying to\n\nadd is already in the graph",
                        "OK",
                        font,
                        size,
                        popUpDefault,
                        window
                ),
                nodeDelErrorPopUp(
                        "Cannot Delete Node",
                        "The node you are trying to\n\ndelete is not in the graph",
                        "OK",
                        font,
                        size,
                        popUpDefault,
                        window
                ),
                edgeDelErrorPopUp(
                        "Cannot Delete Edge",
                        "The edge you are trying to\n\ndelete is not in the graph",
                        "OK",
                        font,
                        size,
                        popUpDefault,
                        window
                )
        {
                
        }

        void drawPopUps(
                        sf::RenderWindow &window,
                        EditorState &state,
                        sf::Vector2f mousePositionPopUp,
                        Cursors &cursors
                )
        {
                if (state.showNodeErrorPopUp) {
                        if (nodeErrorPopUp.dismissHoverState(mousePositionPopUp)) {
                                window.setMouseCursor(cursors.handCursor);
                        }

                        nodeErrorPopUp.drawPopUp(window);
                }

                if (state.showNodeDelErrorPopUp) {
                        if (nodeDelErrorPopUp.dismissHoverState(mousePositionPopUp)) {
                                window.setMouseCursor(cursors.handCursor);
                        }

                        nodeDelErrorPopUp.drawPopUp(window);
                }

                if (state.showEdgeErrorPopUp) {
                        if (edgeErrorPopUp.dismissHoverState(mousePositionPopUp)) {
                                window.setMouseCursor(cursors.handCursor);
                        }

                        edgeErrorPopUp.drawPopUp(window);
                }

                if (state.showEdgeDelErrorPopUp) {
                        if (edgeDelErrorPopUp.dismissHoverState(mousePositionPopUp)) {
                                window.setMouseCursor(cursors.handCursor);
                        }

                        edgeDelErrorPopUp.drawPopUp(window);
                }
        }

        void isDismissed(EditorState &state, sf::Vector2f mousePosition)
        {
                if (state.showNodeErrorPopUp)
                        if (nodeErrorPopUp.isDismissed(mousePosition))
                                state.showNodeErrorPopUp = false;

                if (state.showEdgeErrorPopUp)
                        if (edgeErrorPopUp.isDismissed(mousePosition))
                                state.showEdgeErrorPopUp = false;

                if (state.showNodeDelErrorPopUp)
                        if (nodeDelErrorPopUp.isDismissed(mousePosition))
                                state.showNodeDelErrorPopUp = false;
                
                if (state.showEdgeDelErrorPopUp)
                        if (edgeDelErrorPopUp.isDismissed(mousePosition))
                                state.showEdgeDelErrorPopUp = false;
        }
};

#endif