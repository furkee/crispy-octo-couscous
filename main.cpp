#include "structures/HashTable.hpp"

#include <iostream>
#include <memory>
#include <exception>

int main(int argv, char** argc)
{
    std::unique_ptr<HashTable<std::string, int>> hashTable(new HashTable<std::string, int>());

    hashTable->put("naber", 5);
    hashTable->put("asd", 5);
    hashTable->remove("asd");

    std::cout << "Is naber in the table(expect -> true): " << hashTable->contains("naber") << "\n";
    std::cout << "Is asd in the table(expect -> false): " << hashTable->contains("asd") << "\n";

    try
    {
        std::cout << "Now trying to get an element which is not in the table.. Should throw exception.\n" ;
        hashTable->get("non-existing-elem");
    }
    catch (std::invalid_argument &e)
    {
        std::cerr << e.what() << "\n" ;
    }

    hashTable->put("asd", 11);
    hashTable->put("asd", 16);
    hashTable->put("ransm", 5);
    hashTable->put("asdsafd", 5);
    hashTable->put("assafsad", 5);
    hashTable->put("aasdsd", 5);
    hashTable->put("assad", 5);
    hashTable->put("mehmet", 5);
    hashTable->put("furkan", 5);
    hashTable->put("ipek", 5);

    std::cout << "Getting it: " + std::to_string(hashTable->get("asd")) + "\n" ;

    hashTable->print();

    return 0;
}