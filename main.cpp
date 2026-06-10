// SFML öncesinde hızlıca test edebilmem için bir main şeysi
#include <iostream>

#include "algorithm/Graph.hpp"
#include "algorithm/BFS.hpp"

int main() {

    Graph graph;

    graph.addNode(10);
    graph.addNode(25);
    graph.addNode(3);
    graph.addNode(99);
    graph.addNode(42);
    graph.addNode(7);
    graph.addNode(80);

    graph.addEdge(10, 25);
    graph.addEdge(10, 3);
    graph.addEdge(25, 99);
    graph.addEdge(25, 42);
    graph.addEdge(3, 7);
    graph.addEdge(7, 80);

    std::vector<int> traversal = bfs(graph, 10);

    std::cout << "BFS traversal: ";

    for (int node : traversal) {
        std::cout << node << " ";
    }

    std::cout << "\n";


    int startNode = 10;
    int destNode = 99;
    std::vector<int> traversal2 = bfsShortestPath(graph, startNode, destNode);

    std::cout << "BFS Shortest Path from " << startNode << " to " << destNode  << " is: ";

    for (int node : traversal2) {
        std::cout << node << " ";
    }

    std::cout << "\n";
    
    return 0;
}