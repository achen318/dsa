#ifndef DEPTH_FIRST_SEARCH_H
#define DEPTH_FIRST_SEARCH_H

#include "graph.h"

using namespace graph;

Path *dfs(Graph *graph, Vertex source);
void display_dfs(Graph *graph, Vertex source);

#endif
