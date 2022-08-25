#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H

#include "graph.h"

using namespace graph;

ShortestPathsMap *bellman_ford(Graph *graph, Vertex source);
void display_bellman_ford(Graph *graph, Vertex source);

#endif
