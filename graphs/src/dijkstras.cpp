#include "dijkstras.h"

#include <iostream>
#include <queue>
#include <stdexcept>

ShortestPathsMap *dijkstras(Graph *graph, Vertex source)
{
    // Map of vertices to their distance from source and the path to them
    ShortestPathsMap *dijkstras_map = new ShortestPathsMap();

    // Initialize the map with infinite distances and empty paths
    for (Vertex vertex : *graph->get_vertices())
        if (vertex != source)
            dijkstras_map->insert({vertex,
                                   {INFINITY, Path{}}});
        else
            // Initialize the source distance to 0
            dijkstras_map->insert({vertex,
                                   {0, Path{source}}});

    // Minimum priority queue of WeightVertex pairs
    std::priority_queue<WeightVertexPair,
                        std::vector<WeightVertexPair>,
                        std::greater<WeightVertexPair>>
        priority_queue;

    // Start Dijkstra's algorithm from source (distance from source to source is 0)
    dijkstras_map->at(source).first = 0;
    priority_queue.push({0, source});

    while (!priority_queue.empty())
    {
        // Get unvisited vertex with the smallest distance
        auto [min_dist, min_vertex] = priority_queue.top();
        priority_queue.pop();

        // For all outgoing edges from min_vertex
        for (auto [vertex, weight] : *graph->get_edges(min_vertex))
        {
            // Throw an error if weight is negative
            if (weight < 0)
                throw std::invalid_argument(
                    "edge " + std::to_string(min_vertex) + " -> " + std::to_string(vertex) + " has a negative weight of " + std::to_string(weight));

            Weight new_dist = min_dist + weight;

            // If the current distance is greater than the new distance
            if (dijkstras_map->at(vertex).first > new_dist)
            {
                // Get the path to min_vertex & add vertex to the end
                Path new_path = dijkstras_map->at(min_vertex).second;
                new_path.push_back(vertex);

                // Update the distance-path pair & add to priority queue
                dijkstras_map->at(vertex) = {new_dist, new_path};
                priority_queue.push({new_dist, vertex});
            }
        }
    }

    return dijkstras_map;
}

void display_dijkstras(Graph *graph, Vertex source)
{
    display_shortest_paths(dijkstras(graph, source), source);
}
