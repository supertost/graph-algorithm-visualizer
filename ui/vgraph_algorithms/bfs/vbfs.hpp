#ifndef VBFS_HPP
#define VBFS_HPP

#include "../../ui_structures/Graph/VisualGraph.hpp"

#include <queue>
#include <vector>

std::vector<int> bfs(const VisualGraph &vgraph, const int startNode);

#endif