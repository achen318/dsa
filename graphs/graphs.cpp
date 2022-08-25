#include "bellman_ford.h"
#include "breadth_first_search.h"
#include "depth_first_search.h"
#include "dijkstras.h"

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
        for (int j = 1; j <= size; j++)
            if (i != j)
            {
                graph.add_edge(i, j);
                graph.display_info();
            }

    // Remove vertices
    for (int i = 1; i <= size; i++)
    {
        graph.remove_vertex(i);
        graph.display_info();
    }
}

// ----- Graph generation -----
Graph *generate_graph_a()
{
    // An unweighted digraph (for BFS and DFS)
    Graph *graph_a = new Graph();

    for (int i = 1; i <= 5; i++)
        graph_a->add_vertex(i);

    graph_a->add_edge(1, 2);
    graph_a->add_edge(1, 3);

    graph_a->add_edge(2, 4);
    graph_a->add_edge(3, 4);

    graph_a->add_edge(4, 5);

    return graph_a;
}

Graph *generate_graph_b()
{
    // A positively-weighted digraph (for Dijkstra's)
    Graph *graph_b = new Graph();

    for (int i = 1; i <= 4; i++)
        graph_b->add_vertex(i);

    graph_b->add_edge(1, 2, 4);
    graph_b->add_edge(1, 3, 8);

    graph_b->add_edge(2, 3, 1);
    graph_b->add_edge(2, 4, 8);

    graph_b->add_edge(3, 2, 1);
    graph_b->add_edge(3, 4, 3);

    return graph_b;
}

Graph *generate_graph_c()
{
    // A digraph containing negative weights (for Bellman-Ford)
    Graph *graph_c = new Graph();

    for (int i = 1; i <= 5; i++)
        graph_c->add_vertex(i);

    graph_c->add_edge(1, 2, 1);
    graph_c->add_edge(1, 3, 10);

    graph_c->add_edge(2, 4, 2);
    graph_c->add_edge(3, 4, -10);

    graph_c->add_edge(4, 5, 3);

    return graph_c;
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

    // ----- Graph generation -----
    Graph *graph_a = generate_graph_a();
    Graph *graph_b = generate_graph_b();
    Graph *graph_c = generate_graph_c();

    // ----- Graph traversal -----
    test_bfs(graph_a);
    test_dfs(graph_a);

    // ----- Shortest path -----
    test_dijkstras(graph_b);
    test_bellman_ford(graph_c);

    return 0;
}
