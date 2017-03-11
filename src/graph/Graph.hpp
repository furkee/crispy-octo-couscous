#pragma once

#include <vector>
#include <string>

using std::vector;
using std::string;

struct Vertex;

struct Edge {
    int length;
    Vertex *from;
    Vertex *to;

    Edge(Vertex *from, Vertex *to, int length) : from(from), to(to), length(length) {}
};

struct Vertex {
    string label;
    bool visited;
    vector<Edge*> edges;

    Vertex(string label) : label(label), visited(false) {}
};

/**
 * Directed graph implementation
 */
class Graph
{
public:
    Graph();
    ~Graph();
    Vertex* addVertex(string label);
    bool isConnected();
    Edge* addEdge(Vertex *from, Vertex *to, int length);

private:
    vector<Vertex*> vertices;
    int numEdges;
    int numVertices;

    void setVisitedAsFalse();

};