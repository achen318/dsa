#include "depth_first_search.h"
#include "graph.h"

#include <iostream>

void test_graph(int size)
{
    std::cout << "----- Graph -----" << '\n';

    // Create a graph
    Graph graph;
    graph.display_info();

    // Fill the graph with vertices between 1 and size
    for (int i = 1; i <= size; i++)
    {
        graph.add_vertex(i);
        graph.display_info();
    }

    // Add edges between vertices
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            if (i != j)
            {
                graph.add_edge(i, j);
                graph.display_info();
            }
        }
    }

    // Remove vertices
    for (int i = 1; i <= size; i++)
    {
        graph.remove_vertex(i);
        graph.display_info();
    }
}

Graph *generate_graph()
{
    Graph *graph = new Graph();

    for (int i = 1; i <= 5; i++)
        graph->add_vertex(i);

    graph->add_edge(1, 2);
    graph->add_edge(1, 3);

    graph->add_edge(2, 4);
    graph->add_edge(3, 4);

    graph->add_edge(4, 5);

    return graph;
}

void test_dfs(Graph *graph)
{
    std::cout << "----- Depth First Search -----" << '\n';
    dfs(graph, 1);
}

int main()
{
    test_graph(3);

    Graph *graph = generate_graph();
    graph->display_info();

    test_dfs(graph);

    return 0;
}
