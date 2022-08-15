#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <map>
#include <string>

namespace graph
{
    using Vertex = int;
    using Weight = double;

    using OutgoingEdges = std::map<Vertex, Weight>;
    using Vertices = std::map<Vertex, OutgoingEdges>;
}

using namespace graph;

class Graph
{
private:
    Vertices *vertices;

    // Private methods
    void assert_vertex_exists(Vertex vertex, const std::string &param = "vertex") const;
    void assert_edge_exists(Vertex from_vertex, Vertex to_vertex) const;
    OutgoingEdges *get_edges(Vertex from_vertex) const;

public:
    // Constructor
    Graph();

    // Boolean methods
    bool has_vertex(Vertex vertex) const;
    bool is_directed(Vertex from_vertex, Vertex to_vertex) const;

    // Vertex methods
    void add_vertex(Vertex vertex);
    void remove_vertex(Vertex vertex);

    // Edge methods
    void add_edge(Vertex from_vertex, Vertex to_vertex, Weight weight = 1);
    void remove_edge(Vertex from_vertex, Vertex to_vertex);

    // Weight methods
    Weight get_weight(Vertex from_vertex, Vertex to_vertex) const;
    void set_weight(Vertex from_vertex, Vertex to_vertex, Weight weight);

    // Display
    friend std::ostream &operator<<(std::ostream &out, const Graph &graph);
    void display_info() const;
};

#endif
