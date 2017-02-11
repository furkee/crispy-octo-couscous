#pragma once

#include <string>
#include <list>
#include <exception>
#include <functional>
#include <iostream>

#define INITIAL_SIZE 10

// collisions are handled by linked lists
template <class K, class V>
class HashTable 
{
public:
    HashTable();
    ~HashTable();
    void put(K key, V value);
    bool remove(K key);
    int get(K key);
    bool contains(K key);

    void print();

private:
    struct Entry {
        K key;
        V value;

        Entry(K key, V value) : key(key), value(value) {}
    };

    std::list<Entry*> *hashTable;
    std::hash<K> hasher;
    int size;
    int numElements;

    bool shouldResize();
    void resize();
    int indexer(K key);
};

template <class K, class V>
HashTable<K,V>::HashTable() : size(INITIAL_SIZE), numElements(0)
{
    this->hashTable = new std::list<Entry*>[this->size];
}

template <class K, class V>
HashTable<K,V>::~HashTable()
{
    for (int i = 0; i < this->size; i++)
        for (auto elem : this->hashTable[i])
            delete elem;

    delete[] this->hashTable;
}

template <class K, class V>
void HashTable<K,V>::put(K key, V value)
{
    if (this->shouldResize())
        this->resize();

    Entry *entry = new Entry(key, value);
    int index = this->indexer(key);
    bool existing = false;

    std::cout << "Index: " << index << " Key: " << key << "\n" ;

    for (auto elem : this->hashTable[index])
    {
        if (elem -> key == entry -> key)
        {
            elem -> value = entry -> value;
            existing = true;
        }
    }

    if (!existing)
        this->hashTable[index].push_back(entry);

    this->numElements++;
}

template <class K, class V>
bool HashTable<K,V>::remove(K key)
{
    if (!this->contains(key))
        return false;

    int index = this->indexer(key);

    for (auto elem : this->hashTable[index])
    {
        if (elem->key == key)
        {
            this->hashTable[index].remove(elem);
            this->numElements--;

            delete elem;

            return true;
        }
    }
    
    throw std::exception();
}

template <class K, class V>
int HashTable<K,V>::get(K key)
{
    int index = this->indexer(key);

    for (auto elem : this->hashTable[index])
        if (elem->key == key)
            return elem->value;

    throw std::invalid_argument("Element " + key + " is not in the table!");
}

template <class K, class V>
bool HashTable<K,V>::contains(K key)
{
    int index = this->indexer(key);

    for (auto elem : this->hashTable[index])
        if (elem->key == key)
            return true;
    
    return false;
}

template <class K, class V> 
inline bool HashTable<K,V>::shouldResize()
{
    return this->size < this->numElements * 2 ? true : false;
}

template <class K, class V>
void HashTable<K,V>::resize()
{
    std::list<Entry*> *oldTable = this->hashTable;
    int oldSize = this->size;

    this->size *= 10;
    this->hashTable = new std::list<Entry*>[this->size];

    for (int i = 0; i < oldSize; i++)
        for (auto elem : oldTable[i])
            this->hashTable[this->indexer(elem->key)].push_back(elem);

    std::cout << "Resized hastable from size of " + std::to_string(oldSize) + " to " + std::to_string(this->size) + "\n" ;

    delete[] oldTable;
}

template <class K, class V>
inline int HashTable<K,V>::indexer(K key)
{
    return hasher(key) % this->size;
}

template <>
void HashTable<std::string,int>::print()
{
    std::cout << "Printing elements of table(print only works on <string, int> hash tables):\n" ;

    for (int i = 0; i < size; i++)
    {
        for (auto elem : this->hashTable[i])
        {
            std::cout << "[" + std::to_string(i) + "] Key: " + elem->key + " -> Value: " + std::to_string(elem->value) + "\n" ;
        }
    }
}