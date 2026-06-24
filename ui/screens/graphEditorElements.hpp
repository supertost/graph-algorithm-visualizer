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

struct EditorUIElements
{
        Button exitButton;
        Button addNodeButton;
        Button addEdgeButton;
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
                        "Add Node",
                        sf::Vector2f(0.0f, 0.0f),
                        sf::Vector2f(3.0f, 130.0f),
                        font,
                        defaultButton,
                        hoverDefaultButton
                ),
                addEdgeButton(
                        "Add Edge",
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

                edgeBox.drawTextbox(window);
                addEdgeButton.drawButton(window);

                clearGraphButton.drawButton(window);
                loadGraphButton.drawButton(window);

                saveGraphButton.drawButton(window);
                centerGraphButton.drawButton(window);

        }

        bool checkHover(sf::Vector2f mousePosition)
        {
                bool exitButtonHover = exitButton.hoverState(mousePosition);
                bool addNodeHover = addNodeButton.hoverState(mousePosition);
                bool addEdgeHover = addEdgeButton.hoverState(mousePosition);
                bool clearGraphHover = clearGraphButton.hoverState(mousePosition);
                bool loadGraphHover = loadGraphButton.hoverState(mousePosition);
                bool saveGraphHover = saveGraphButton.hoverState(mousePosition);
                bool centerGraphHover = centerGraphButton.hoverState(mousePosition);

                if (
                        addNodeHover 
                        || addEdgeHover 
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

        EditorPopUps(const sf::Font &font, sf::RenderWindow &window, sf::Vector2f size)
                : 
                nodeErrorPopUp(
                        "Cannot Add Node",
                        "The node you are trying to\n\nadd is already in the graph",
                        "Okay",
                        font,
                        size,
                        popUpDefault,
                        window
                ),
                edgeErrorPopUp(
                        "Cannot Add Edge",
                        "The edge you are trying to\n\nadd is already in the graph",
                        "Okay",
                        font,
                        size,
                        popUpDefault,
                        window
                )
        {
                
        }
};

struct EditorState
{
        bool showNodeErrorPopUp = false;
        bool showEdgeErrorPopUp = false;

        bool isPanningGraph = false;
        sf::Vector2i lastPanPixel;

        bool isNodeClicked = false;
        int clickedNode = 0;

        float currentZoom = 1.0f;
        float targetZoom = 1.0f;

        char const *lFilterPatterns[];
};

struct EditorCursors
{
        sf::Cursor normalCursor;
        sf::Cursor handCursor;
        sf::Cursor moveCursor;

        EditorCursors()
        {
                normalCursor.loadFromSystem(sf::Cursor::Arrow);
                handCursor.loadFromSystem(sf::Cursor::Hand);
                moveCursor.loadFromSystem(sf::Cursor::SizeAll);
        }
};

#endif