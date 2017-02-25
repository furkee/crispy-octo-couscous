#pragma once

#ifdef GRAPH_TEST

#include "../structures/Graph.hpp"

void graphTest1()
{
    Graph graph;

    Vertex *vFirst  = graph.addVertex(5);
    Vertex *vSecond = graph.addVertex(5);
    Edge *eFirst    = graph.addEdge(vFirst, vSecond, 1);
    Edge *eSecond   = graph.addEdge(vSecond, vFirst, 3);

    auto vertices = graph.getVertices(5);

    std::cout << "Size: " << (*vertices).size() << "\n" ;
}

#endif

void GraphTests()
{
#ifdef GRAPH_TEST
    graphTest1();
#endif
}