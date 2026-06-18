#ifndef READWRITE_HPP
#define READWRITE_HPP

#include "../ui/ui_structures/Graph/VisualGraph.hpp"

bool readGraphData(const char *filepath, VisualGraph &vgraph);
bool saveGraphData(const char *filepath, VisualGraph &vgraph);

#endif