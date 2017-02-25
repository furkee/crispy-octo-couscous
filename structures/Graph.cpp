#include "Graph.hpp"

#include <iostream>

Graph::Graph() : numEdges(0), numVertices(0)
{
    refVertex = nullptr;
}

Graph::~Graph()
{
    if (refVertex != nullptr)
        delete refVertex;
}

Vertex* Graph::addVertex(int data)
{
    Vertex *newVertex = new Vertex(data);

    if (refVertex == nullptr)
        refVertex = newVertex;

    return newVertex;
}

Edge* Graph::addEdge(Vertex *from, Vertex *to, int length)
{
    if (from == nullptr || to == nullptr)
        throw std::invalid_argument("An edge cannot connect a non existing vertex!");

    Edge *edge = new Edge(from, to, length);

    from->edges.push_back(edge);

    return edge;
}

/* Non member getVertices traversal */
void getVerticesRecursive(vector<Vertex*>* vertices, Vertex* vertex, int data, int &numVisited)
{
    if (vertex != nullptr && !vertex->visited)
    {
        if (vertex->data == data)
            vertices->push_back(vertex);

        vertex->visited = true;

        for (auto edge : (vertex->edges))
            getVerticesRecursive(vertices, edge->to, data, numVisited);
    }
}

vector<Vertex*>* Graph::getVertices(int data)
{
    int numVisited = 0;
    vector<Vertex*> *vertices = new vector<Vertex*>();

    getVerticesRecursive(vertices, refVertex, data, numVisited);

    this->setAllToFalse();

    return vertices;
}

void Graph::setAllToFalse()
{

}
