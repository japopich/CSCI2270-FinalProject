/**
 * @file hash.hpp
 * @brief The main header file for the HashTable Class
 */

#ifndef HASH_HPP
#define HASH_HPP

#include <string>
#include <iostream>

using namespace std;

struct node
{
    int key;
    struct node *next;
    struct node *prev;
};

class HashTable
{
private:
    int tableSize; // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    node **table;

    int numOfcollision;
    node *createNode(int key, node *next);

public:
    HashTable(int size); // Constructor
    ~HashTable();         // Destructor

    // inserts a key into hash table
    bool insertLLitem(int key);         // Chaining collision avoidance method implemented
    bool insertLinearitem(int key);     // Linear Probing collision avoidance method implemented
    bool insertQuaditem(int key);       // Quadratic Probing collision avoidance method implemented

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable(); // -----
    int getNumOfCollision();

    node *searchLLItem(int key);     // Search using the Chain collision avoidance method
    node *searchLinearItem(int key); // Search using the Linear collision avoidance method -----
    node *searchQuadItem(int key);   // Search using the Quad collision avoidance method -----
};

#endif
