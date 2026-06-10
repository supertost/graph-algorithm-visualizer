#include "Graph.hpp"

Graph::Graph() {

}

int Graph::getNodeAmount() const {

    return this->nodeAmount;
}

int Graph::getEdgeCount(int node) const {

    return this->graph.at(node).size();
}

std::vector<int> Graph::getEdges(int node) const {

    return this->graph.at(node);
}


void Graph::addNode(int node) {

    this->graph[node] = std::vector<int>();
    this->nodeAmount++;
}

void Graph::addEdge(int source, int destionation) {

    this->graph[source].push_back(destionation);
}