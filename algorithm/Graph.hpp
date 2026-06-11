#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <map>

struct Edge {
    int dest;
    int weight;
};


class Graph {

    private:
        
        int nodeAmount;
        std::map<int, std::vector<Edge>> graph;

    public:
        
        Graph();

        int getNodeAmount() const;
        int getEdgeCount(const int node) const;
        std::vector<Edge> getEdges(const int node) const;

        void addEdge(const int source, const int destination);
        void addEdge(const int source, const int destination, const int weight);
        bool addNode(const int node);
};

#endif