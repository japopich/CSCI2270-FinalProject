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
    struct node* next;
    struct node* prev;
};

class HashTable
{
    private:
        int tableSize;  // No. of buckets (linked lists)

        // Pointer to an array containing buckets
        node* *table;
  
        int numOfcolision = 0;
        node* createNode(int key, node* next);

    public:
        HashTable(int bsize);  // Constructor

        // inserts a key into hash table
        bool insertItem(int key);

        // hash function to map values to key
        unsigned int hashFunction(int key);

        void printTable();
        int getNumOfCollision();

        node* searchItem(int key);
};

#endif
