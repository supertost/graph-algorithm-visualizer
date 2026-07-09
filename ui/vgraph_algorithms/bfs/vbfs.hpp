#ifndef VBFS_HPP
#define VBFS_HPP

#include "../../ui_structures/Graph/VisualGraph.hpp"
#include "../../screens/bfsScreen.hpp"

#include <queue>
#include <vector>

std::vector<int> bfs(const VisualGraph &vgraph, const int startNode);
void initialSetup(BfsStuffTest &bfsgraph);
void runOneIteration(BfsStuffTest &bfsgraph, const VisualGraph &vgraph);

#endif