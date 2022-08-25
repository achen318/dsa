#include "bellman_ford.h"

ShortestPathsMap *bellman_ford(Graph *graph, Vertex source)
{
    // Map of vertices to their distance from source and the path to them
    ShortestPathsMap *bellman_ford_map = new ShortestPathsMap();

    // Initialize the map with infinite distances and empty paths
    for (Vertex vertex : *graph->get_vertices())
        if (vertex != source)
            bellman_ford_map->insert({vertex,
                                      {INFINITY, Path{}}});
        else
            // Initialize the source distance to 0
            bellman_ford_map->insert({vertex,
                                      {0, Path{source}}});

    const int num_vertices = graph->get_num_vertices();

    // Repeat |V| times, with the last iteration for negative cycle detection
    for (int i = 0; i < num_vertices; i++)
        for (Vertex vertex : *graph->get_vertices())
            for (auto [to_vertex, weight] : *graph->get_edges(vertex))
            {
                Weight new_dist = bellman_ford_map->at(vertex).first + weight;

                // If the current distance is greater than the new distance
                if (bellman_ford_map->at(to_vertex).first > new_dist)
                {
                    // Throw an error if a negative cycle is detected
                    if (i == num_vertices - 1)
                        throw std::invalid_argument(
                            "negative cycle detected from " + std::to_string(vertex) + " -> " + std::to_string(to_vertex));

                    // Get the path to min_vertex & add vertex to the end
                    Path new_path = bellman_ford_map->at(vertex).second;
                    new_path.push_back(to_vertex);

                    // Update the distance-path pair
                    bellman_ford_map->at(to_vertex) = {new_dist, new_path};
                }
            }

    return bellman_ford_map;
}

void display_bellman_ford(Graph *graph, Vertex source)
{
    display_shortest_paths(bellman_ford(graph, source), source);
}
