#pragma once

#include <vector>

using std::vector;

struct Vertex;

struct Edge {
    int length;
    Vertex *from;
    Vertex *to;

    Edge(Vertex *from, Vertex *to, int length) : from(from), to(to), length(length) {}
};

struct Vertex {
    int data;
    bool visited; // after a traversal, needs to be set to false again - FIXME O(e.v)
    vector<Edge*> edges;

    Vertex(int data) : data(data), visited(false) {}
};

class Graph
{
public:
    Graph();
    ~Graph();
    Vertex* addVertex(int data);
    vector<Vertex*>* getVertices(int data);
    Edge* addEdge(Vertex *from, Vertex *to, int length);

private:
    // our reference vertex FIXME this implementation cannot represent disconnected graphs as one graph
    Vertex *refVertex;
    int numEdges;
    int numVertices;

    void setAllToFalse();

};