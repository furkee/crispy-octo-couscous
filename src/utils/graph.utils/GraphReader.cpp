#include "GraphReader.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>

using std::string;
using std::cout;
using std::vector;
using std::list;
using std::ifstream;
using std::istringstream;

struct Node {
    string label; // ID of node
    vector<std::pair<int,int>> neighbors; // vector<neighbor ID - distance>
};

GraphReader::GraphReader(string fileName) : fileName(fileName) {}

GraphReader::~GraphReader() {}

bool getLineSkipComments(ifstream &file, string &line)
{
    while (getline(file, line))
    {
        if (line.at(0) != '#')
            return true;
    }

    return false;
}

void parseVertexData(string line, vector<Node> &nodes)
{
    istringstream parser(line);
    Node node;

    parser >> node.label;

    do
    {
        int neighbor, distance;

        parser >> neighbor >> distance ;

        if (parser)
            node.neighbors.push_back(std::pair<int,int>(neighbor, distance));
    }
    while (parser);

    nodes.push_back(node);
}

Graph* convertToGraph(vector<Node> &nodes)
{
    Graph* graph = new Graph();
    vector<Vertex*> vertices;

    // go over nodes and using their labels, create vertices
    for (int i = 0; i < nodes.size(); i++)
    {
        Vertex *v = graph->addVertex(nodes.at(i).label);
        vertices.push_back(v);
    }

    // go over nodes again and this time connect them by adding edges in btw em.
    for (int i = 0; i < nodes.size(); i++)
    {
        Vertex *from = vertices.at(i);

        for (auto neighbor : nodes.at(i).neighbors)
        {
            Vertex *to = vertices.at(neighbor.first);
            graph->addEdge(from, to, neighbor.second);
        }
    }

    return graph;
}

Graph* GraphReader::read()
{
    ifstream file(this->fileName, std::ios::in);
    Graph* graph = nullptr;

    if (file.is_open())
    {   
        string line;
        vector<Node> nodes;

        while (getLineSkipComments(file, line))
            parseVertexData(line, nodes);

        file.close();

        graph = convertToGraph(nodes);
    }

    return graph;
}