#ifndef READWRITE_HPP
#define READWRITE_HPP

#include "../ui/ui_structures/Graph/VisualGraph.hpp"
#include "../ui/program.hpp"

bool readGraphData(const char *filepath, VisualGraph &vgraph);
bool saveGraphData(const char *filepath, VisualGraph &vgraph);
bool readConfig(Config &config);
bool saveConfig(Config &config);

#endif