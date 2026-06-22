#ifndef VGRAPH_HPP
#define VGRAPH_HPP

#include "Node.hpp"

#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include <unordered_set>
#include <utility>
#include <array>

class VisualGraph
{
        private:
                const sf::Font &font;

                sf::Vector2f determineNodeLocation() const;
                std::map<int, Node> displayNodes;
                std::map<int, std::vector<int>> edges;

                const NodeStyle defaultStyle;
                
        public:
                VisualGraph(const sf::Font &font, const NodeStyle &style);

                bool addNode(int key);
                bool addEdge(int source, int dest);
                
                bool containsNode(int key) const;
                bool isClicked(sf::Vector2f mousePosition, int &nodeClicked);
                void dragNode(sf::Vector2f mousePosition, int clickedNode);
                
                void clearGraph();
                
                void drawGraph(sf::RenderWindow &window) const;

                // Getters
                const std::map<int, Node> &getNodesMap() const;
                std::map<int, Node> &getNodesMapNonConst();
                const std::map<int, std::vector<int>> &getEdgesMap() const;
                const std::array<float, 4> getBounds() const;
};


#endif