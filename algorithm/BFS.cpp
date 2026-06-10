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
        
        std::vector<int> edges = graph.getEdges(currentNode);
        
        for (int edge : edges) {
            
            if (visited.find(edge) == visited.end()) {
                visited.insert(edge);
                queue.push(edge);
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

    int previousNode;

    bool found = false;

    while (!queue.empty()) {

        int currentNode = queue.front();
        queue.pop();

        
        std::vector<int> edges = graph.getEdges(currentNode);
        
        for (int edge : edges) {
            
            if (visited.find(edge) == visited.end()) {

                traversal[edge] = currentNode;

                if (edge == destNode) {
                    found = true;
                    break;
                }

                visited.insert(edge);
                queue.push(edge);
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
