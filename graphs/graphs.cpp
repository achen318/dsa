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

int main()
{
    test_graph(5);

    return 0;
}
