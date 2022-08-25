#include "graph.h"

#include <stdexcept>

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

// ----- Constructor -----
Graph::Graph()
{
    this->vertices = new Vertices();
}

// ----- Primitive methods -----
int Graph::get_num_vertices() const
{
    return this->vertices->size();
}

int Graph::get_num_edges() const
{
    int num_edges = 0;

    for (auto &[_, edges] : *this->vertices)
        num_edges += edges.size();

    return num_edges;
}

bool Graph::has_vertex(Vertex vertex) const
{
    Vertices *vertices = this->vertices;
    return vertices->find(vertex) != vertices->end();
}

bool Graph::is_directed(Vertex from_vertex, Vertex to_vertex) const
{
    OutgoingEdges *edges = this->get_edges(from_vertex);
    return edges->find(to_vertex) != edges->end();
}

// ----- Vertex methods -----
std::set<Vertex> *Graph::get_vertices() const
{
    std::set<Vertex> *vertices = new std::set<Vertex>();

    for (auto &[vertex, _] : *this->vertices)
        vertices->insert(vertex);

    return vertices;
}

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
OutgoingEdges *Graph::get_edges(Vertex vertex) const
{
    this->assert_vertex_exists(vertex);
    return &this->vertices->at(vertex);
}

void Graph::add_edge(Vertex from_vertex, Vertex to_vertex, Weight weight)
{
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
        for (const auto [to_vertex, weight] : outgoing_edges)
        {
            out << to_vertex << ": " << weight;

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
    std::cout << "Graph         - " << *this << '\n';
    std::cout << "Vertices |V|  - " << this->get_num_vertices() << '\n';
    std::cout << "Edges    |E|  - " << this->get_num_edges() << "\n\n";
}
