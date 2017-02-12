#include "structures/HashTable.hpp"

#include <iostream>
#include <memory>
#include <exception>

int main(int argc, char** argv)
{
    std::unique_ptr<HashTable<std::string, int>> hashTable(new HashTable<std::string, int>());

    hashTable->put("naber", 5);
    hashTable->put("asd", 5);
    hashTable->remove("asd");

    std::cout << "Is naber in the table(expect -> true): " << hashTable->contains("naber") << "\n" ;
    std::cout << "Is asd in the table(expect -> false): " << hashTable->contains("asd") << "\n" ;

    try
    {
        std::cout << "Now trying to get an element which is not in the table.. Should throw exception.\n" ;
        hashTable->get("non-existing-elem");
    }
    catch (std::invalid_argument &e)
    {
        std::cerr << e.what() << "\n" ;
    }

    hashTable->put("mehmet", 10);
    hashTable->put("furkan", 6);
    hashTable->put("ipek", 1993);

    hashTable->remove("assafsad");

    std::list<const std::pair<std::string, int>*> *pairList = hashTable->getPairList();

    for (auto elem : (*pairList))
        std::cout << "Key: " + elem->first + " -> Value: " + std::to_string(elem->second) + "\n" ;

    // compiler will throw warning saying pairList's elements are read-only
    //pairList->front()->second = 1231;

    delete pairList;

    hashTable->print();

    return 0;
}