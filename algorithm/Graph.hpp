#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <map>

class Graph {

    private:
        
        int nodeAmount;
        std::map<int, std::vector<int>> graph;

    public:
        
        Graph();

        int getNodeAmount() const;
        int getEdgeCount(int node) const;
        std::vector<int> getEdges(int node) const;

        void addEdge(int source, int destination);
        void addNode(int node);
};

#endif