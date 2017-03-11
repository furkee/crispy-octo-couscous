#include "Graph.hpp"

#include <iostream>

using std::string;
using std::vector;
using std::cout;

Graph::Graph() : numEdges(0), numVertices(0) {}

Graph::~Graph()
{
    vertices.clear();
}

Vertex* Graph::addVertex(string label)
{
    Vertex *vertex = new Vertex(label);

    vertices.push_back(vertex);
    this->numVertices++;

    return vertex;
}

Edge* Graph::addEdge(Vertex *from, Vertex *to, int length)
{
    if (from == nullptr || to == nullptr)
        throw std::invalid_argument("An edge cannot connect a non existing vertex!");

    Edge *edge = new Edge(from, to, length);

    from->edges.push_back(edge);
    this->numEdges++;

    return edge;
}

void isConnectedRecursive(Vertex *vertex, int &numVisited)
{
    if (!vertex->visited)
    {
        vertex->visited = true;
        numVisited++;

        for (auto edge : (vertex->edges))
            isConnectedRecursive(edge->to, numVisited);
    }
}

bool Graph::isConnected()
{
    int numVisited = 0;

    isConnectedRecursive(this->vertices.front(), numVisited);

    this->setVisitedAsFalse();

    if (numVisited > this->numVertices)
        throw std::string("Implementation failure in Graph::isConnected"); // implementation failure

    return numVisited == this->numVertices;
}

void Graph::setVisitedAsFalse()
{
    for (auto vertex : vertices)
        vertex->visited = false;
}
