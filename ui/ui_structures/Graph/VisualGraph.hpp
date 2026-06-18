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
        std::map<int, Node> displayNodes;
        std::map<int, std::vector<int>> edges;
        
    public:

        VisualGraph(const sf::Font &font);

        bool addNode(int key);
        bool addEdge(int source, int dest);
        bool containsNode(int key) const;

        bool isClicked(sf::Vector2f mousePosition, int &nodeClicked);

        void drawGraph(sf::RenderWindow &window) const;
        void dragNode(sf::Vector2f mousePosition, int clickedNode);
        void clearGraph();
        const std::map<int, Node> &getNodesMap() const;
        const std::map<int, std::vector<int>> &getEdgesMap() const;
        
        std::map<int, Node> &getNodesMapNonConst();
};


#endif