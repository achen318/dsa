#include "bellman_ford.h"
#include "breadth_first_search.h"
#include "depth_first_search.h"
#include "dijkstras.h"
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

Graph *generate_unweighted_graph()
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

Graph *generate_weighted_graph()
{
    Graph *graph = new Graph();

    for (int i = 1; i <= 4; i++)
        graph->add_vertex(i);

    graph->add_edge(1, 2, 4);
    graph->add_edge(1, 3, 8);

    graph->add_edge(2, 3, 1);
    graph->add_edge(2, 4, 8);

    graph->add_edge(3, 2, 1);
    graph->add_edge(3, 4, 3);

    return graph;
}

// ----- Graph traversal -----
void test_bfs(Graph *graph)
{
    std::cout << "----- Breadth-First Search -----" << '\n';
    display_bfs(graph, 1);
}

void test_dfs(Graph *graph)
{
    std::cout << "----- Depth-First Search -----" << '\n';
    display_dfs(graph, 1);
}

// ----- Shortest path -----
void test_bellman_ford(Graph *graph)
{
    std::cout << "----- Bellman-Ford Algorithm -----" << '\n';
    display_bellman_ford(graph, 1);
}

void test_dijkstras(Graph *graph)
{
    std::cout << "----- Dijkstra's Algorithm -----" << '\n';
    display_dijkstras(graph, 1);
}

int main()
{
    test_graph(3);

    // ----- Graph traversal -----
    Graph *unweighted_graph = generate_unweighted_graph();

    test_bfs(unweighted_graph);
    test_dfs(unweighted_graph);

    // ----- Shortest path -----
    Graph *weighted_graph = generate_weighted_graph();

    test_bellman_ford(weighted_graph);
    test_dijkstras(weighted_graph);

    return 0;
}
