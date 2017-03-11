//#include "HashTable.hpp"
#include <graph/Graph.hpp>
#include <utils/graph.utils/GraphReader.hpp>

#include <iostream>

using std::cout;

int main(int argc, char** argv)
{
    Graph graph;

    Vertex *vFirst  = graph.addVertex("tokat");
    Vertex *vSecond = graph.addVertex("istanbul");
    Edge *eFirst    = graph.addEdge(vFirst, vSecond, 1000);
    //Edge *eSecond   = graph.addEdge(vSecond, vFirst, 1000);

    cout << "Is graph connected(expect -> true): " << graph.isConnected() << "\n" ;

    Vertex *aloneWulf = graph.addVertex("amasya");

    cout << "Is graph connected(expect -> false): " << graph.isConnected() << "\n" ;

    Edge *connector = graph.addEdge(aloneWulf, vFirst, 150);

    // TODO this returns false since there is no incoming edge to aloneWulf
    cout << "Is graph connected(expect -> true): " << graph.isConnected() << "\n" ;
    //cout << connector->from->label + " -> " + connector->to->label + "\n" ;

    for (auto neighbor : vFirst->edges)
        cout << neighbor->from-> label + " -> " + neighbor->to-> label + "\n" ;

    GraphReader reader("../resources/graph.gp");
    Graph* roadGraph = reader.read();

    std::cout << "Is road graph connected: " << roadGraph->isConnected() << "\n" ;

    return 0;
}
