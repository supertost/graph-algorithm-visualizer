#include "VisualGraph.hpp"

VisualGraph::VisualGraph(const sf::Font &font, const NodeStyle &style) 
        : font(font), defaultStyle(style)
{

}

// Improve node location determination, this is not good
sf::Vector2f VisualGraph::determineNodeLocation() const
{  
        std::size_t nodeCount = displayNodes.size();  

        float startX = 100.0f;  
        float startY = 100.0f;  
        float spacing = 100.0f;  

        int columns = 5;  

        float x = startX + static_cast<float>(nodeCount % columns) * spacing;  
        float y = startY + static_cast<float>(nodeCount / columns) * spacing;  

        return sf::Vector2f(x, y);  
}

bool VisualGraph::addNode(int key)
{
        if (containsNode(key))
                return false;
        
        
        sf::Vector2f position = determineNodeLocation();
        
        displayNodes.emplace(key, Node(key, position, defaultStyle, font));
        edges[key] = std::vector<int>();
        
        return true;
}

bool VisualGraph::addEdge(int source, int dest)
{
        addNode(source);
        addNode(dest);
        
        for (int neighbor : edges.at(source))
                if (neighbor == dest)
                        return false;
        
        edges[source].push_back(dest);
        
        return true;
}

bool VisualGraph::containsNode(int key) const
{
        return displayNodes.find(key) != displayNodes.end();
}

bool VisualGraph::isClicked(sf::Vector2f mousePosition, int &nodeClicked)
{
        for (const std::pair<const int, Node> &node : displayNodes) {
                if (node.second.getGlobalBounds().contains(mousePosition)) {
                        nodeClicked = node.first;
                        return true;
                }
        }

        return false;
}

void VisualGraph::dragNode(sf::Vector2f mousePosition, int clickedNode)
{
        displayNodes.at(clickedNode).setPosition(mousePosition);
}

void VisualGraph::clearGraph()
{
        displayNodes.clear();
        edges.clear();
}

void VisualGraph::drawGraph(sf::RenderWindow &window) const
{
        for (const auto &[source, neighbors] : edges) {
                for (const int neighbor : neighbors) {
                        sf::Vertex line[] = {
                                sf::Vertex(
                                        displayNodes.at(source).getPosition(),
                                        sf::Color(237, 98, 28)
                                ),
                                sf::Vertex(
                                        displayNodes.at(neighbor).getPosition(),
                                        sf::Color(237, 98, 28)
                                )
                        };
                        
                        window.draw(line, 2, sf::Lines);
                }
        }

        for (const auto &[key, node] : displayNodes)
                node.drawNode(window);
}

// Getters
const std::map<int, Node>& VisualGraph::getNodesMap() const
{
        return displayNodes;
}

const std::map<int, std::vector<int>>& VisualGraph::getEdgesMap() const
{
        return edges;
}

const std::array<float, 4>  VisualGraph::getBounds() const {

        if (displayNodes.empty())
                return {0.0f, 0.0f, 0.0f, 0.0f};

        auto it = displayNodes.begin();
        sf::Vector2f firstPos = it->second.getPosition();

        float lowestX = firstPos.x;
        float highestX = firstPos.x;
        float lowestY = firstPos.y;
        float highestY = firstPos.y;

        for (const auto &pair : displayNodes) {
        
                sf::Vector2f pos = pair.second.getPosition();

                if (pos.x < lowestX)
                        lowestX = pos.x;

                if (pos.x > highestX)
                        highestX = pos.x;

                if (pos.y < lowestY)
                        lowestY = pos.y;

                if (pos.y > highestY)
                        highestY = pos.y;
        }

        return {lowestX, highestX, lowestY, highestY};
}

// Setters

// Returns true if node found and a position is set, false if no node found in graph.
bool VisualGraph::setNodePosition(int key, sf::Vector2f position)
{
        if (displayNodes.find(key) != displayNodes.end()) {

                displayNodes.at(key).setPosition(position);
                return true;
        }

        return false;
}