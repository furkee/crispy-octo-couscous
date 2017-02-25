#pragma once

#ifdef GRAPH_TEST

#include "../structures/Graph.hpp"

#include <iostream>

using std::cout;

void graphTest1()
{
    Graph graph;

    Vertex *vFirst  = graph.addVertex("tokat");
    Vertex *vSecond = graph.addVertex("istanbul");
    Edge *eFirst    = graph.addEdge(vFirst, vSecond, 1000);
    Edge *eSecond   = graph.addEdge(vSecond, vFirst, 1000);

    cout << "Is graph connected(expect -> true): " << graph.isConnected() << "\n" ;

    Vertex *aloneWulf = graph.addVertex("amasya");

    cout << "Is graph connected(expect -> false): " << graph.isConnected() << "\n" ;

    Edge *connector = graph.addEdge(aloneWulf, vFirst, 150);

    // TODO this returns false since there is no incoming edge to aloneWulf
    cout << "Is graph connected(expect -> true): " << graph.isConnected() << "\n" ;
}

#endif

void GraphTests()
{
#ifdef GRAPH_TEST
    graphTest1();
#endif
}