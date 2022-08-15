#include "graph.h"

#include <stdexcept>

using namespace graph;

// ----- Private methods -----
void Graph::assert_vertex_exists(Vertex vertex, const std::string &param) const
{
    if (!this->has_vertex(vertex))
        throw std::invalid_argument('\'' + param + "' of " + std::to_string(vertex) + " does not exist");
}

void Graph::assert_edge_exists(Vertex from_vertex, Vertex to_vertex) const
{
    if (!this->is_directed(from_vertex, to_vertex))
        throw std::invalid_argument("edge " + std::to_string(from_vertex) + " -> " + std::to_string(to_vertex) + " does not exist");
}

OutgoingEdges *Graph::get_edges(Vertex from_vertex) const
{
    return &this->vertices->at(from_vertex);
}

// ----- Constructor -----
Graph::Graph()
{
    this->vertices = new Vertices();
}

// ----- Boolean methods -----
bool Graph::has_vertex(Vertex vertex) const
{
    Vertices *vertices = this->vertices;
    return vertices->find(vertex) != vertices->end();
}

bool Graph::is_directed(Vertex from_vertex, Vertex to_vertex) const
{
    this->assert_vertex_exists(from_vertex, "from_vertex");
    this->assert_vertex_exists(to_vertex, "to_vertex");

    OutgoingEdges *edges = this->get_edges(from_vertex);
    return edges->find(to_vertex) != edges->end();
}

// ----- Vertex methods -----
void Graph::add_vertex(Vertex vertex)
{
    if (this->has_vertex(vertex))
        throw std::invalid_argument("'vertex' of " + std::to_string(vertex) + " already exists");

    this->vertices->insert({vertex, OutgoingEdges()});
}

void Graph::remove_vertex(Vertex vertex)
{
    // Delete all incoming edges
    for (auto &[from_vertex, outgoing_edges] : *this->vertices)
        if (from_vertex != vertex && this->is_directed(from_vertex, vertex))
            outgoing_edges.erase(vertex);

    // Delete the vertex (and outgoing edges)
    this->vertices->erase(vertex);
}

// ----- Edge methods -----
void Graph::add_edge(Vertex from_vertex, Vertex to_vertex, Weight weight)
{
    this->assert_vertex_exists(from_vertex, "from_vertex");
    this->assert_vertex_exists(to_vertex, "to_vertex");

    this->get_edges(from_vertex)->insert({to_vertex, weight});
}

void Graph::remove_edge(Vertex from_vertex, Vertex to_vertex)
{
    this->assert_edge_exists(from_vertex, to_vertex);
    this->get_edges(from_vertex)->erase(to_vertex);
}

// ----- Weight methods -----
Weight Graph::get_weight(Vertex from_vertex, Vertex to_vertex) const
{
    this->assert_edge_exists(from_vertex, to_vertex);
    return this->get_edges(from_vertex)->at(to_vertex);
}

void Graph::set_weight(Vertex from_vertex, Vertex to_vertex, Weight weight)
{
    this->assert_edge_exists(from_vertex, to_vertex);
    this->get_edges(from_vertex)->at(to_vertex) = weight;
}

// ----- Display -----
std::ostream &operator<<(std::ostream &out, const Graph &graph)
{
    out << '[';

    size_t v_printed = 0;

    // For each vertex, display the vertex and the set of outgoing edges
    for (const auto &[vertex, outgoing_edges] : *graph.vertices)
    {
        out << vertex << ": {";

        size_t e_printed = 0;

        // For each outgoing edge, display the destination vertex and weight
        for (const auto &[to_vertex, weight] : outgoing_edges)
        {
            out << '(' << to_vertex << ", " << weight << ')';

            // If this is not the last outgoing edge, add a separator
            if (e_printed != outgoing_edges.size() - 1)
                out << ", ";

            // Increment the number of outgoing edges printed
            e_printed++;
        }

        out << '}';

        // If this is not the last vertex, add a separator
        if (v_printed != graph.vertices->size() - 1)
            out << ", ";

        // Increment the number of vertices printed
        v_printed++;
    }

    out << ']';

    return out;
}

void Graph::display_info() const
{
    std::cout << "Graph - " << *this << '\n';
    std::cout << "Size  - " << this->vertices->size() << "\n\n";
}
