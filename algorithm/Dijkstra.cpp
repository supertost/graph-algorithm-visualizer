#include "Dijkstra.hpp"

#include <queue>
#include <utility>
#include <unordered_set>
#include <vector>
#include <functional>

// Returns the map of the shortest cost path from a node to all other nodes 
std::map<int, int> dijkstra(const Graph &graph, int startNode) {

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pqueue; // Priority queue için pair'ın ilk elemanı baz alınıyormuş ondan pair için <weight, node> şeklinde saklıyorum.
    std::unordered_set<int> visited;

    std::map<int, int> weights;

    pqueue.push({0, startNode});
    weights[startNode] = 0;
    
    while (!pqueue.empty()) {

        if (visited.find(pqueue.top().second) != visited.end()) {

            pqueue.pop();
            continue;
        }
        
        std::pair<int, int> currentNode = pqueue.top(); 
        int currentNodeVal = currentNode.second;
        int currentNodeWeight = currentNode.first;

        pqueue.pop();

        visited.insert(currentNodeVal);

        for (const Edge &edge : graph.getEdges(currentNodeVal)) {

            if (edge.weight < 0) {

                return {};
            }

            if (visited.find(edge.dest) == visited.end()) {


                int edgeWeight = currentNodeWeight + edge.weight;

                pqueue.push({edgeWeight, edge.dest});

                if (weights.find(edge.dest) == weights.end())
                    weights[edge.dest] = edgeWeight;
                
                else
                    if (weights.at(edge.dest) > edgeWeight)
                        weights[edge.dest] = edgeWeight;
            }
        }
    }
    
    return weights;
}