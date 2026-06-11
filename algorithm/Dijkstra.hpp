#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "Graph.hpp"
#include <map>

std::map<int, int> dijkstra(const Graph &graph, int startNode);

#endif