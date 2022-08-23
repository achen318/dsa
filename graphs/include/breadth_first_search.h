#ifndef BREADTH_FIRST_SEARCH_H
#define BREATH_FIRST_SEARCH_H

#include "graph.h"

#include <vector>

using namespace graph;

std::vector<Vertex> *bfs(Graph *graph, Vertex source);
void display_bfs(Graph *graph, Vertex source);

#endif
