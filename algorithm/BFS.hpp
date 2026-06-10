#ifndef BFS_HPP
#define BFS_HPP

#include "Graph.hpp"

std::vector<int> bfs(const Graph &graph, int startNode);
std::vector<int> bfsShortestPath(const Graph &graph, int startNode, int destNode);

#endif