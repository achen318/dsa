#include "breadth_first_search.h"

#include <iostream>
#include <queue>
#include <set>

void bfs(Graph *graph, Vertex source)
{
    // Store visited vertices & queue of vertices to visit
    std::set<Vertex> visited;
    std::queue<Vertex> queue;

    // Insert source vertex into visited and queue
    visited.insert(source);
    queue.push(source);

    while (!queue.empty())
    {
        Vertex vertex = queue.front();

        // Print vertex & dequeue it from the queue
        std::cout << "Visiting " << vertex << '\n';
        queue.pop();

        // Iterate through all outgoing edges from vertex
        for (auto &[to_vertex, _] : *graph->get_edges(vertex))

            // If the vertex has not been visited,
            if (visited.find(to_vertex) == visited.end())
            {
                // Insert vertex into visited and queue
                visited.insert(to_vertex);
                queue.push(to_vertex);
            }
    }
}
