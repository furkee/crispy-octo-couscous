#include "structures/HashTable.hpp"
#include "structures/Graph.hpp"

//#define TEST_HASH_TABLE
#include "tests/HashTableTest.hpp"
#define GRAPH_TEST
#include "tests/GraphTest.hpp"

void runTests()
{
    HashTableTests();
    GraphTests();
}

int main(int argc, char** argv)
{
    runTests();

    return 0;
}
