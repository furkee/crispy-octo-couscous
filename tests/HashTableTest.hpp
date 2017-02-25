#pragma once

#ifdef TEST_HASH_TABLE

#include "../structures/HashTable.hpp"

void hashTableTest1()
{
    std::unique_ptr<HashTable<std::string, int>> hashTable(new HashTable<std::string, int>());

    hashTable->put("naber", 5);
    hashTable->put("asd", 5);
    hashTable->remove("asd");

    std::cout << "Is naber in the table(expect -> true): " << hashTable->contains("naber") << "\n" ;
    std::cout << "Is asd in the table(expect -> false): " << hashTable->contains("asd") << "\n" ;

    try
    {
        std::cout << "Now trying to get an element which is not in the table.. Should throw an exception.\n" ;
        hashTable->get("non-existing-elem");
    }
    catch (std::invalid_argument &e)
    {
        std::cerr << e.what() << "\n" ;
    }

    hashTable->put("mehmet", 10);
    hashTable->put("furkan", 6);
    hashTable->put("ipek", 1993);
    hashTable->put("naber", 70);

    hashTable->remove("assafsad");

    std::unique_ptr<std::list<const Entry<std::string, int>*>> entryList(hashTable->getEntryList());

    for (auto elem : (*entryList))
        std::cout << "Key: " + elem->key + " -> Value: " + std::to_string(elem->value) + "\n" ;

    // compiler will throw warning saying entryList's elements are read-only
    //entryList->front()->second = 1231;

    hashTable->print();
}

void hashTableTest2()
{
    HashTable<int, int> *ht = new HashTable<int, int>();
    
    for (int i = 0; i < 5; i++)
        ht->put(i, i);

    HashTable<std::string, HashTable<int,int>*> table;

    table.put("class", ht);

    std::cout << "Get result from our new class table: " << table.get("class") ;
}

void hashTableTest3()
{
    HashTable<std::string, int> table;
    int i = 0;

    while (i++ < 8)
        table.put("trial-" + std::to_string(i), i);
        
    i--;

    while (i++ < 15)
        table.put("trial-" + std::to_string(i), i);

    if (table.get("trial-1") != 1)
        throw std::exception();
}

#endif

void HashTableTests()
{
#ifdef TEST_HASH_TABLE
    hashTableTest1();
    hashTableTest2();
    hashTableTest3();
#endif
}