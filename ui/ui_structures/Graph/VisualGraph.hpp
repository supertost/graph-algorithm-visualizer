#ifndef VGRAPH_HPP
#define VGRAPH_HPP

#include "Node/Node.hpp"

#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include <unordered_set>
#include <utility>

class VisualGraph {
    private:

        //float highestCoordX;
        //float lowestCoordX;
        //float highestCoordY;
        //float lowestCoordY;
        const sf::Font &font;

        sf::Vector2f determineNodeLocation() const;
        
    public:

        std::map<int, Node> displayNodes;
        std::map<int, std::vector<int>> edges;
        VisualGraph(const sf::Font &font);

        bool addNode(int key);
        bool addEdge(int source, int dest);
        bool containsNode(int key) const;

        void drawGraph(sf::RenderWindow &window) const;
};


#endif