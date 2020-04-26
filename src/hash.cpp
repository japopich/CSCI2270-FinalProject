/**
 * @file hash.cpp
 * @brief The main source file for the HashTable Class
 */

#include "hash.hpp"
#include <math.h>

HashTable::HashTable(int size)
{
    // Declare the dynamic array of node pointers and set tableSize and numOfcollision to 0
    HashTable::table = new node*[size] {nullptr};
    tableSize = size;
    numOfcollision = 0;
}

HashTable::~HashTable()
{
    // Iterate through the array and delete each node object stored in it, then delete the array
    for (int i = 0; i < tableSize; i++)
    {
        // If a node is stored in the ith index of the array delete it
        if (table[i] != nullptr)
        {
            // Iterate through the nodes stored at i and delete them
            node *curr = table[i];
            node *prev = nullptr;
            while (curr != nullptr)
            {
                prev = curr;
                curr = curr->next;
                delete prev;
            }
        }
    }

    // Delete the dynamic array
    delete[] table;
}

node *HashTable::createNode(int key, node *next)
{
    node *newNode = new node;
    newNode->key = key;
    newNode->next = next;
    return newNode;
}

unsigned int HashTable::hashFunction(int key)
{
    return key % HashTable::tableSize;
}

bool HashTable::insertLLitem(int key)
{
    int nodeIndex = HashTable::hashFunction(key);
    node *newNode = HashTable::createNode(key, nullptr);

    // If no node exists at that index append newNode as head
    if (HashTable::table[nodeIndex] == nullptr)
    {
        newNode->prev = nullptr;
        newNode->next = nullptr;
        HashTable::table[nodeIndex] = newNode;
        return true;
    }
    else // else append to chained LinkedList
    {
        HashTable::numOfcollision++; // Add to the num of collisions
        // Set the node at the Hash Table index as our LinkedList (LL) head
        node *head = HashTable::table[nodeIndex];
        while ((head->next != nullptr) && (newNode->key > head->key))
        {
            if (head->key == key)
            {
                // std::cout << head->key << " is Duplicate Key in Chaining Hash! Ignoring... " << std::endl;
                return false;
            }
            head = head->next;
            HashTable::numOfcollision++; // Add to the num of collisions
        }

        // Found the spot, append the new node
        head->next = newNode;
        return true;
    }
}

bool HashTable::insertLinearitem(int key)
{
    int nodeIndex = HashTable::hashFunction(key);
    node* newNode = HashTable::createNode(key, nullptr);

    // If no node exists at that index append newNode
    if(HashTable::table[nodeIndex] == nullptr)
    {
        newNode->prev = nullptr;
        newNode->next = nullptr;
        HashTable::table[nodeIndex] = newNode;
        return true;
    }
    else // else start the Linear Collision Method
    {
        // Loop until the new node is placed
        while (true)
        {
            HashTable::numOfcollision++; // Add to the num of collisions
            nodeIndex++;
            nodeIndex = nodeIndex % HashTable::tableSize;
            if(HashTable::table[nodeIndex] == nullptr)
            {
                HashTable::table[nodeIndex] = newNode;
                return true;
            }
            if(HashTable::table[nodeIndex]->key == key)
            {
                // std::cout << key << " is Duplicate Key in Linear Hash! Ignoring... " << std::endl;
                return false;
            }
        }
    }
}

bool HashTable::insertQuaditem(int key)
{
    int nodeIndex = HashTable::hashFunction(key);
    node* newNode = HashTable::createNode(key, nullptr);

    // If no node exists at that index append newNode
    if(HashTable::table[nodeIndex] == nullptr)
    {
        newNode->prev = nullptr;
        newNode->next = nullptr;
        HashTable::table[nodeIndex] = newNode;
        return true;
    }
    else // else start the Quadratic Collision Method
    {
        // Loop until the new node is placed
        int index = 0;
        int i = 1;
        while(true)
        {
            HashTable::numOfcollision++; // Add to the num of collisions
            index = nodeIndex + pow(i,2);
            i++;
            if(HashTable::table[nodeIndex]->key == key)
            {
                // std::cout << key << " is Duplicate Key in Quad Hash! Ignoring... " << std::endl;
                return false;
            }
            if(HashTable::table[index] == nullptr)
            {
                HashTable::table[index] = newNode;
                return true;
            }
        }
    }
}

node *HashTable::searchLLItem(int key)
{
    // Get the index of where the key should be
    int nodeIndex = HashTable::hashFunction(key);

    // If an index does exist for that key enter if statement
    if (HashTable::table[nodeIndex] != nullptr)
    {
        // Set the currNode to the node at the index
        node *currNode = HashTable::table[nodeIndex];

        // If the node is not equal to nullptr, check to see if key is equal to key we're looking for
        // if not check attached LinkedList
        while (currNode != nullptr)
        {
            if (currNode->key == key)
            {
                return currNode;
            }
            else
            {
                currNode = currNode->next;
                HashTable::numOfcollision++; // Add to the num of collisions
            }
        }
    }
    return nullptr; // If key not found at all return nullptr
}

node *HashTable::searchLinearItem(int key)
{
    // Call the hash function to find the key's hash representation
    int hashCode = HashTable::hashFunction(key);

    // Index into the hash table and find the node object corresponding to key using linear probing
    if (HashTable::table[hashCode]->key == key)
    {
        return HashTable::table[hashCode];
    }
    else
    {
        int i = hashCode + 1;
        // Iterate through the hash table until the node is found
        while (i != hashCode)
        {
            if (HashTable::table[i] != nullptr)
            {
                if (HashTable::table[i]->key == key)
                {
                    return HashTable::table[i];
                }
            }
            i = (i + 1) % HashTable::tableSize;
            HashTable::numOfcollision++; // Add to the num of collisions
        }
    }
    return nullptr;
}

node *HashTable::searchQuadItem(int key)
{
    // Call the hash function to find the key's hash representation
    int hashCode = HashTable::hashFunction(key);

    // Index into the hash table and find the node object corresponding to key using quadratic probing
    if (HashTable::table[hashCode]->key == key)
    {
        return HashTable::table[hashCode];
    }
    else
    {
        // Iterate through the hash table until the node is found
        int index = 0;
        int i = 1;
        while(true)
        {
            HashTable::numOfcollision++; // Add to the num of collisions
            index = hashCode + pow(i,2);
            i++;
            if (HashTable::table[index] != nullptr)
            {
                if (HashTable::table[index]->key == key)
                {
                    return HashTable::table[index];
                }
            }
        }
    }
    return nullptr;
}

void HashTable::printTable()
{
    // Prints the contents of the hash table

    if (HashTable::table == nullptr)
    {
        std::cout << "Hash Table is Empty" << std::endl;
        return;
    }

    std::cout << "Contents of Hash Table: " << std::endl;

    // Print the contents of the hash table with nodes stored at the same index of table on the same line
    for (int i = 0; i < HashTable::tableSize; i++)
    {
        if (HashTable::table[i] != nullptr)
        {
            // Iterate through the nodes stored at i and print them
            node *curr = table[i];
            node *prev = nullptr;
            while (curr != nullptr)
            {
                prev = curr;
                curr = curr->next;
                
                std::cout << curr->key << ", ";
            }

            std::cout << std::endl;
        }
    }

    return;
}

int HashTable::getNumOfCollision()
{
    int collisions = HashTable::numOfcollision;
    HashTable::numOfcollision = 0;
    return collisions;
}