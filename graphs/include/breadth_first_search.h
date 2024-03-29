#ifndef BREADTH_FIRST_SEARCH_H
#define BREATH_FIRST_SEARCH_H

#include "graph.h"

using namespace graph;

Path *bfs(Graph *graph, Vertex source);
void display_bfs(Graph *graph, Vertex source);

#endif
