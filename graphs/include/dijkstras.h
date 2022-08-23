#ifndef DIJKSTRAS_H
#define DIJKSTRAS_H

#include "graph.h"

#include <map>
#include <utility>
#include <vector>

using namespace graph;

namespace dijkstras_namespace
{
    // A path is a vector of vertices in order,
    // starting at the source and ending at the destination
    using Path = std::vector<Vertex>;

    using DistancePathPair = std::pair<Weight, Path>;
    using DijkstrasMap = std::map<Vertex, DistancePathPair>;

    // Used in priority queue to compare vertices by their distance from source
    // Since the first item in the pair is compared, the weight is first
    using WeightVertexPair = std::pair<Weight, Vertex>;

    // INFINITY represents a tentative distance that is not yet known
    const Weight INFINITY = std::numeric_limits<Weight>::infinity();
}

using namespace dijkstras_namespace;

DijkstrasMap *dijkstras(Graph *graph, Vertex source);
void display_dijkstras(Graph *graph, Vertex source);

#endif
