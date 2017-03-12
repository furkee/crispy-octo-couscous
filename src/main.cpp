//#include "HashTable.hpp"
#include <graph/Graph.hpp>
#include <utils/graph.utils/GraphReader.hpp>

#include <iostream>
#include <functional>
#include <unordered_map>
#include <string>

using std::cout;

int main(int argc, char** argv)
{
    Graph graph;

    Vertex *vFirst  = graph.addVertex("tokat");
    Vertex *vSecond = graph.addVertex("istanbul");
    Edge *eFirst    = graph.addEdge(vFirst, vSecond, 1000);
    //Edge *eSecond   = graph.addEdge(vSecond, vFirst, 1000);

    std::unordered_map<Vertex*, std::string> map;

    map[vFirst] = "Selam";
    map[vSecond] = "Naber";
    map[vFirst] = "Edited";

    cout << "Holaaa: " + map[vFirst] + "\n" ;

    cout << "Hash(vFirst) -> " << std::to_string(std::hash<Vertex>()(*vFirst)) << "\n" ;
    cout << "Hash(vSecond) -> " << std::to_string(std::hash<Vertex>()(*vSecond)) << "\n" ;

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
