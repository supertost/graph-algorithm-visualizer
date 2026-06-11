// SFML öncesinde hızlıca test edebilmem için bir main şeysi
#include <iostream>

#include "algorithm/Graph.hpp"
#include "algorithm/BFS.hpp"
#include "algorithm/DFS.hpp"
#include "algorithm/Dijkstra.hpp"

int main() {

    Graph graph;

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

    std::cout << "\n\n";


    int startNode = 10;
    int destNode = 99;
    std::vector<int> traversal2 = bfsShortestPath(graph, startNode, destNode);

    std::cout << "BFS Shortest Path from " << startNode << " to " << destNode  << " is: ";

    for (int node : traversal2) {

        std::cout << node << " ";
    }

    std::cout << "\n\n";


    std::vector<int> traversal3 = dfs(graph, 10);

    std::cout << "DFS traversal: ";

    for (int node : traversal3) {

        std::cout << node << " ";
    }

    std::cout << "\n\n";


    startNode = 10;
    destNode = 7;
    std::vector<int> traversal4 = dfsPath(graph, startNode, destNode);

    std::cout << "DFS path from " << startNode << " to " << destNode << " is: ";

    for (int node : traversal4) {

        std::cout << node << " ";
    }

    std::cout << "\n\n";


    Graph weightedGraph;

    weightedGraph.addEdge(10, 25, 2);
    weightedGraph.addEdge(10, 3, 10);
    weightedGraph.addEdge(25, 99, 4);
    weightedGraph.addEdge(25, 42, 1);
    weightedGraph.addEdge(42, 99, 1);
    weightedGraph.addEdge(3, 7, 1);
    weightedGraph.addEdge(7, 80, 3);

    std::map<int, int> costs = dijkstra(weightedGraph, 10);

    std::cout << "Dijkstra costs from 10:\n";

    for (const auto &[node, cost] : costs) { // bu pythonsal durum için https://www.geeksforgeeks.org/cpp/structured-binding-c/

        std::cout << "Node " << node << ": " << cost << "\n";
    }
    
    return 0;
}