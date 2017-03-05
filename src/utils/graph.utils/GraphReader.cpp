#include "GraphReader.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

using std::string;
using std::ifstream;
using std::istringstream;

GraphReader::GraphReader(string fileName) : fileName(fileName) {}

GraphReader::~GraphReader() {}

void getLineBySkippingComments(ifstream &file, string &line)
{
    do
    {
        getline(file, line);
    }
    while (line.at(0) == '#');
}

Graph* GraphReader::read()
{
    ifstream file(this->fileName, std::ios::in);

    if (file.is_open())
    {
        string line;
        istringstream lineParser;
        int numVertices;

        getLineBySkippingComments(file, line);
        lineParser.str(line);
        lineParser >> numVertices;

        while (getline(file, line))
        {
            
        }

        file.close();
    }
}