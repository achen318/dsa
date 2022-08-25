#include "depth_first_search.h"

#include <iostream>
#include <set>
#include <stack>

Path *dfs(Graph *graph, Vertex source)
{
    Path *returned_dfs = new Path();

    // Store visited vertices & stack of vertices to visit
    std::set<Vertex> visited;
    std::stack<Vertex> stack;

    // Insert source vertex into visited and stack
    visited.insert(source);
    stack.push(source);

    while (!stack.empty())
    {
        Vertex vertex = stack.top();

        // Insert vertex into returned_dfs & pop it from the stack
        returned_dfs->push_back(vertex);
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

    return returned_dfs;
}

void display_dfs(Graph *graph, Vertex source)
{
    display_graph_traversal(dfs(graph, source));
}
