#pragma once

#include "../../graph/Graph.hpp"

#include <string>

using std::string;

class GraphReader
{
public:
    GraphReader(string fileName);
    ~GraphReader();
    Graph* read();

private:
    string fileName;
};