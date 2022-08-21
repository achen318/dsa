#include "depth_first_search.h"

#include <iostream>
#include <set>
#include <stack>

void dfs(Graph *graph, Vertex source)
{
    // Store visited vertices & stack of vertices to visit
    std::set<Vertex> visited;
    std::stack<Vertex> stack;

    // Insert source vertex into visited and stack
    visited.insert(source);
    stack.push(source);

    while (!stack.empty())
    {
        Vertex vertex = stack.top();

        // Print vertex & pop it from the stack
        std::cout << "Visiting " << vertex << '\n';
        stack.pop();

        // Iterate through all outgoing edges from vertex
        for (auto &[to_vertex, _] : *graph->get_edges(vertex))

            // If the vertex has not been visited,
            if (visited.find(to_vertex) == visited.end())
            {
                // Insert vertex into visited and stack
                visited.insert(to_vertex);
                stack.push(to_vertex);
            }
    }
}
