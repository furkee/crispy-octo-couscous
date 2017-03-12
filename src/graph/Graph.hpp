#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <functional>

using std::vector;
using std::string;
using std::cout;
using std::unordered_map;
using std::hash;

struct Vertex;

struct Edge {
    int length;
    Vertex *from;
    Vertex *to;

    Edge(Vertex *from, Vertex *to, int length) : from(from), to(to), length(length) {}

    bool operator == (const Edge &rhs) const
    {
        cout << "Comparing edges..\n" ;
        if (length == rhs.length && from == rhs.from && to == rhs.to)
            return true;

        return false;
    }

    bool operator == (const Edge *rhs) const
    {
        return (*this == *rhs);
    }

    bool operator != (const Edge &rhs) const
    {
        return !(*this == rhs);
    }
    bool operator != (const Edge *rhs) const
    {
        return !(*this == *rhs);
    }
};

struct Vertex {
    string label;
    bool visited;
    vector<Edge*> edges;

    Vertex(string label) : label(label), visited(false) {}
    
    bool operator == (const Vertex &rhs) const
    {
        cout << "Comparing vertices..\n" ;
        if (label == rhs.label && edges.size() == rhs.edges.size())
        {
            for (int i = 0; i < edges.size(); i++)
                if (*edges.at(i) != *rhs.edges.at(i))
                    return false;
                
            return true;
        }

        return false;
    }

    bool operator == (const Vertex *rhs) const
    {
        return (*this == *rhs);
    }

    bool operator != (const Vertex &rhs) const
    {
        return !(*this == rhs);
    }

    bool operator != (const Vertex *rhs) const
    {
        return !(*this == *rhs);
    }
};

namespace std
{
    template<>
    struct hash<Vertex>
    {
        size_t operator() (const Vertex &vertex) const
        {
            cout << "hashing..\n" ;
            return hash<string>()(vertex.label);
        }
    };
    template<>
    struct hash<Vertex*>
    {
        size_t operator() (const Vertex *vertex) const
        {
            cout << "hashing..\n" ;
            return hash<string>()(vertex->label);
        }
    };
}

struct VertexEqualFunction {

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