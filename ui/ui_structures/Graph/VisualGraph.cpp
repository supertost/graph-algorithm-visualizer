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