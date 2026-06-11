#include "Graph.hpp"

Graph::Graph() {

}


// Returns the total number of nodes in the graph 
int Graph::getNodeAmount() const {

    return this->nodeAmount;
}

// Returns the edge count of a node
int Graph::getEdgeCount(const int node) const {

    return this->graph.at(node).size();
}

// Returns all edges of a node
std::vector<Edge> Graph::getEdges(const int node) const {

    return this->graph.at(node);
}


// Adds a node to the graph if it does not exist
// Returns true if node added, false if node not added
bool Graph::addNode(const int node) {

    if (graph.find(node) == graph.end()) {

        this->graph[node] = std::vector<Edge>();
        this->nodeAmount++;

        return true;
    }

    return false;
}

// Adds a directed unweighted edge, edge weight default is 1
void Graph::addEdge(const int source, const int destination) {

    if (graph.find(source) == graph.end())
        addNode(source);

    if (graph.find(destination) == graph.end())
        addNode(destination);
    
    this->graph[source].push_back(Edge{.dest = destination, .weight = 1}); // (Edge) {.dest = destionation, .weight = 1} struct için bu yandaki daha C syntaxmiş, ondan şu anki koddaki halini kullan
}

// Adds a directed edge with a weight
void Graph::addEdge(const int source, const int destination, const int weight) {

    if (graph.find(source) == graph.end())
        addNode(source);

    if (graph.find(destination) == graph.end())
        addNode(destination);
    
    this->graph[source].push_back(Edge{.dest = destination, .weight = weight});
}