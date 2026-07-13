#include "vbfs.hpp"

#include <iostream>
#include <chrono>
#include <thread>

// Only for test
std::vector<int> bfs(const VisualGraph &vgraph, const int startNode)
{
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

void initialSetup(BfsStuffTest &bfsgraph)
{
        bfsgraph.queue.push(bfsgraph.lastNode);
        bfsgraph.visited.insert(bfsgraph.lastNode);
}

void runWithWait(BfsStuffTest &bfsgraph, const VisualGraph &vgraph)
{
        while(!bfsgraph.quit) {
                if (bfsgraph.play) {
                        runOneIteration(bfsgraph, vgraph);
                        
                        int count = 0;
                        int seconds = bfsgraph.waitSeconds * 1000;
                        while (count < seconds) {
                                if (seconds != bfsgraph.waitSeconds * 1000)
                                        seconds = bfsgraph.waitSeconds * 1000;

                                std::this_thread::sleep_for(std::chrono::milliseconds(1));
                                if (bfsgraph.quit || !bfsgraph.play)
                                        break;
                                count++;
                        }
                }
        }
}

void runOneIteration(BfsStuffTest &bfsgraph, const VisualGraph &vgraph)
{
        if (!bfsgraph.queue.empty()) {
                int currentNode = bfsgraph.queue.front();
                bfsgraph.queue.pop();
                bfsgraph.lastNode = currentNode;
        
                bfsgraph.traversal.push_back(currentNode);
                        
                std::vector<int> edges = vgraph.getEdgesMap().at(currentNode);   
                for (const int edge : edges) {
                        if (bfsgraph.visited.find(edge) == bfsgraph.visited.end()) {
                                bfsgraph.visited.insert(edge);
                                bfsgraph.queue.push(edge);
                        }
                }
        }
}