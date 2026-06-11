#include <queue>
#include <unordered_set>
#include <iostream>
#include <algorithm>

#include "BFS.hpp"

// Just for basic bfs traversal so I can check the algorithm
std::vector<int> bfs(const Graph &graph, const int startNode) {

    std::vector<int> traversal;
    std::unordered_set<int> visited;
    std::queue<int> queue;

    queue.push(startNode);
    visited.insert(startNode);

    while (!queue.empty()) {

        int currentNode = queue.front();
        queue.pop();

        traversal.push_back(currentNode);
        
        std::vector<Edge> edges = graph.getEdges(currentNode);
        
        for (const Edge &edge : edges) {
            
            if (visited.find(edge.dest) == visited.end()) {
                visited.insert(edge.dest);
                queue.push(edge.dest);
            }
        }
    }

    return traversal;
}

// To find the shortest path from one node to another node
std::vector<int> bfsShortestPath(const Graph &graph, const int startNode, const int destNode) {

    std::map<int, int> traversal; // map: node, previous node
    std::unordered_set<int> visited;
    std::queue<int> queue;

    queue.push(startNode);
    visited.insert(startNode);

    bool found = false;

    while (!queue.empty()) {

        int currentNode = queue.front();
        queue.pop();

        
        std::vector<Edge> edges = graph.getEdges(currentNode);
        
        for (const Edge &edge : edges) {
            
            if (visited.find(edge.dest) == visited.end()) {

                traversal[edge.dest] = currentNode;

                if (edge.dest == destNode) {
                    found = true;
                    break;
                }

                visited.insert(edge.dest);
                queue.push(edge.dest);
            }
        }

        if (found)
            break;
    }

    if (!found) {

        std::cout << "A path from " << startNode << " to " << destNode << " does not exist.\n";
        return {};
    }


    std::vector<int> shortestPath;

    int currentNode = destNode;
    while (currentNode != startNode) {

        shortestPath.push_back(currentNode);
        currentNode = traversal.at(currentNode);
    }

    shortestPath.push_back(startNode);
    std::reverse(std::begin(shortestPath), std::end(shortestPath));

    return shortestPath;
}
