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
    bool visited; // after a traversal, needs to be set to false again - FIXME O(e.v)
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
    // our reference vertex FIXME this implementation cannot represent disconnected graphs as one graph
    vector<Vertex*> vertices;
    int numEdges;
    int numVertices;

    void setVisitedAsFalse();

};