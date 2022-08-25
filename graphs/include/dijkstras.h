#ifndef DIJKSTRAS_H
#define DIJKSTRAS_H

#include "graph.h"

using namespace graph;

ShortestPathsMap *dijkstras(Graph *graph, Vertex source);
void display_dijkstras(Graph *graph, Vertex source);

#endif
