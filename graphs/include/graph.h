#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

namespace graph
{
    // ----- Graph components -----
    using Vertex = int;
    using Weight = double;

    using OutgoingEdges = std::map<Vertex, Weight>;
    using Vertices = std::map<Vertex, OutgoingEdges>;

    // ----- Graph traversal -----
    using Path = std::vector<Vertex>;

    // ----- Shortest path stuff -----
    using DistancePathPair = std::pair<Weight, Path>;
    using ShortestPathsMap = std::map<Vertex, DistancePathPair>;

    // Used in priority queue to compare vertices by their distance from source
    // Since the first item in the pair is compared, the weight is first
    using WeightVertexPair = std::pair<Weight, Vertex>;

    // INFINITY represents a tentative distance that is not yet known
    const Weight INFINITY = std::numeric_limits<Weight>::infinity();
}

using namespace graph;

class Graph
{
private:
    Vertices *vertices;

    // Private methods
    void assert_vertex_exists(Vertex vertex, const std::string &param = "vertex") const;
    void assert_edge_exists(Vertex from_vertex, Vertex to_vertex) const;

public:
    // Constructor
    Graph();

    // Primitive methods
    int get_num_vertices() const;
    int get_num_edges() const;

    bool has_vertex(Vertex vertex) const;
    bool is_directed(Vertex from_vertex, Vertex to_vertex) const;

    // Vertex methods
    std::set<Vertex> *get_vertices() const;
    void add_vertex(Vertex vertex);
    void remove_vertex(Vertex vertex);

    // Edge methods
    OutgoingEdges *get_edges(Vertex vertex) const;
    void add_edge(Vertex from_vertex, Vertex to_vertex, Weight weight = 1);
    void remove_edge(Vertex from_vertex, Vertex to_vertex);

    // Weight methods
    Weight get_weight(Vertex from_vertex, Vertex to_vertex) const;
    void set_weight(Vertex from_vertex, Vertex to_vertex, Weight weight);

    // Display
    friend std::ostream &operator<<(std::ostream &out, const Graph &graph);
    void display_info() const;
};

// Algorithm display
void display_graph_traversal(Path *path);
void display_shortest_paths(ShortestPathsMap *shortest_paths, Vertex source);

#endif
