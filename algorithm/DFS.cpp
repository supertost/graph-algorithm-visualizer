#include "DFS.hpp"

#include <algorithm>

void dfs(const Graph &graph, const int currentNode, std::unordered_set<int> &visited, std::vector<int> &traversal) {

    visited.insert(currentNode);
    traversal.push_back(currentNode);

    for (int edge : graph.getEdges(currentNode)) {

        if (visited.find(edge) == visited.end()) {

            dfs(graph, edge, visited, traversal);
        }
    }
}

// Returns the DFS traversal
std::vector<int> dfs(const Graph &graph, const int startNode) {
    
    std::vector<int> traversal;
    std::unordered_set<int> visited;
    
    dfs(graph, startNode, visited, traversal);
    
    return traversal;
}



bool dfsPathHelper(const Graph &graph, const int currentNode, const int destNode, std::unordered_set<int> &visited, std::map<int, int> &traversal) {

    visited.insert(currentNode);

    if (currentNode == destNode)
        return true;

    for (int edge : graph.getEdges(currentNode)) {

        if (visited.find(edge) == visited.end()) {

            traversal[edge] = currentNode;
            if (dfsPathHelper(graph, edge, destNode, visited, traversal))
                return true;
        }
    }

    return false;
}

// Returns a path between two nodes
std::vector<int> dfsPath(const Graph &graph, const int startNode, const int destNode) {

    std::map<int, int> traversal;
    std::unordered_set<int> visited;

    bool found = dfsPathHelper(graph, startNode, destNode, visited, traversal);

    if (!found)
        return {};
    
    std::vector<int> path;

    int currentNode = destNode;
    while (currentNode != startNode) {

        path.push_back(currentNode);
        currentNode = traversal.at(currentNode);
    }

    path.push_back(startNode);
    std::reverse(std::begin(path), std::end(path));

    return path;
}

