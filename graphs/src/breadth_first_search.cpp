#include "breadth_first_search.h"

#include <queue>
#include <set>

Path *bfs(Graph *graph, Vertex source)
{
    Path *returned_bfs = new Path();

    // Store visited vertices & queue of vertices to visit
    std::set<Vertex> visited;
    std::queue<Vertex> queue;

    // Insert source vertex into visited and queue
    visited.insert(source);
    queue.push(source);

    while (!queue.empty())
    {
        Vertex vertex = queue.front();

        // Insert vertex into returned_bfs & dequeue it from the queue
        returned_bfs->push_back(vertex);
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

    return returned_bfs;
}

void display_bfs(Graph *graph, Vertex source)
{
    display_graph_traversal(bfs(graph, source));
}
