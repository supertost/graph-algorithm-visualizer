#include "VisualGraph.hpp"

VisualGraph::VisualGraph(const sf::Font &font) : font(font) {

}

// Improve node location determination, this is not good
sf::Vector2f VisualGraph::determineNodeLocation() const {  
    std::size_t nodeCount = displayNodes.size();  

    float startX = 100.0f;  
    float startY = 100.0f;  
    float spacing = 100.0f;  

    int columns = 5;  

    float x = startX + static_cast<float>(nodeCount % columns) * spacing;  
    float y = startY + static_cast<float>(nodeCount / columns) * spacing;  

    return sf::Vector2f(x, y);  
}

bool VisualGraph::containsNode(int key) const {

    return this->displayNodes.find(key) != displayNodes.end();
}

bool VisualGraph::addNode(int key) {

    if (containsNode(key))
        return false;


    sf::Vector2f position = determineNodeLocation();

    this->displayNodes.emplace(key, Node(key, position, 30.0f, sf::Color(237, 98, 28), sf::Color::Black, 2.0f, this->font));
    this->edges[key] = std::vector<int>();

    return true;
}

bool VisualGraph::addEdge(int source, int dest) {

    addNode(source);
    addNode(dest);

    for (int neighbor : this->edges.at(source)) {

        if (neighbor == dest) {

            return false;
        }
    }

    this->edges[source].push_back(dest);

    return true;
}


bool VisualGraph::isClicked(sf::Vector2f mousePosition, int &nodeClicked) {

    for (const std::pair<const int, Node> &node : this->displayNodes) {

        if (node.second.getGlobalBounds().contains(mousePosition)) {
            
            nodeClicked = node.first;
            return true;
        }
    }

    return false;
}

void VisualGraph::dragNode(sf::Vector2f mousePosition, int clickedNode) {

    this->displayNodes.at(clickedNode).setPosition(mousePosition);
}

void VisualGraph::clearGraph() {
    
    this->displayNodes.clear();
    this->edges.clear();
}



void VisualGraph::drawGraph(sf::RenderWindow &window) const {

    for (const std::pair<const int, std::vector<int>> &edge : this->edges) {
        
        for (const int neighbor : edge.second) {
            
            sf::Vertex line[] = {
                
                sf::Vertex(this->displayNodes.at(edge.first).getPosition(), sf::Color(237, 98, 28)),
                sf::Vertex(this->displayNodes.at(neighbor).getPosition(), sf::Color(237, 98, 28))
            };
            
            window.draw(line, 2, sf::Lines);
        }
    }

    for (const std::pair<const int, Node> &displayNode : this->displayNodes) {
    
        displayNode.second.drawNode(window);
    }
}


// Getters

const std::map<int, Node>& VisualGraph::getNodesMap() const {

    return this->displayNodes;
}

const std::map<int, std::vector<int>>& VisualGraph::getEdgesMap() const {

    return this->edges;
}

std::map<int, Node>& VisualGraph::getNodesMapNonConst() {

    return this->displayNodes;
}