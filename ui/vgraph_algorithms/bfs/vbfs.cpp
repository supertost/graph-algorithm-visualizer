#include "vbfs.hpp"

// Only for test
std::vector<int> bfs(const VisualGraph &vgraph, const int startNode) {

    std::vector<int> traversal;
    std::unordered_set<int> visited;
    std::queue<int> queue;

    queue.push(startNode);
    visited.insert(startNode);

    while (!queue.empty()) {

        int currentNode = queue.front();
        queue.pop();

        traversal.push_back(currentNode);
        
        std::vector<int> edges = vgraph.getEdgesMap().at(currentNode);
        
        for (const int edge : edges) {
            
            if (visited.find(edge) == visited.end()) {
                visited.insert(edge);
                queue.push(edge);
            }
        }
    }

    return traversal;
}

void initialStep()
{

}

void runOneIteration()
{

}