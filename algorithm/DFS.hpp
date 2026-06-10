#ifndef DFS_HPP
#define DFS_HPP

#include <vector>
#include <unordered_set>

#include "Graph.hpp"

std::vector<int> dfs(const Graph &graph, const int startNode);
std::vector<int> dfsPath(const Graph &graph, const int startNode, const int destNode);

#endif