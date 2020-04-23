/**
 * @file hash.cpp
 * @brief The main source file for the HashTable Class
 */

#include "hash.hpp"

HashTable::HashTable(int size)
{
    // Declare the dynamic array of node pointers and set tableSize and numOfcollision to 0
    table = new node *[size];
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
    delete table;
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
        HashTable::table[nodeIndex] = newNode;
        return true;
    }
    else // else append to chained LinkedList
    {
        HashTable::numOfcollision++; // Add to collision....
        // Set the node at the Hash Table index as our LinkedList (LL) head
        node *head = HashTable::table[nodeIndex];

        // Check for duplicates in LL
        while (head != nullptr)
        {
            if (head->key == key)
            {
                std::cout << "Duplicate Key!" << std::endl;
                return false;
            }
            head = head->next;
        }

        // NO duplicates so append the new node
        head = HashTable::table[nodeIndex]; // Set Head again
        while ((head != nullptr) && (newNode->key > head->key))
        {
            head = head->next;
        }

        // Found the spot, append the new node
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        return true;
    }
}

bool HashTable::insertLinearitem(int key)
{
}

bool HashTable::insertQuaditem(int key)
{
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
            }
        }
    }
    return nullptr; // If key not found at all return nullptr
}

node *HashTable::searchLinearItem(int key)
{
    // Call the hash function to find the key's hash representation
    int hashCode = HashTable::hashFunction(key);

    // Index into the hash table and find the node object corrosponding to key using linear probing
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
        }

        i = (i + 1) % HashTable::tableSize;
    }
}

node *HashTable::searchQuadItem(int key)
{
    // Call the hash function to find the key's hash representation
    int hashCode = HashTable::hashFunction(key);

    // Index into the hash table and find the node object corrosponding to key using quadratic probing
    if (HashTable::table[hashCode]->key == key)
    {
        return HashTable::table[hashCode];
    }

    else
    {
        int j = 1;
        int i = hashCode + 1;
        // Iterate through the hash table until the node is found
        while (true)
        {
            if (HashTable::table[i] != nullptr)
            {
                if (HashTable::table[i]->key == key)
                {
                    return HashTable::table[i];
                }
            }
            
            i = (i + (j * j)) % HashTable::tableSize;
        }
    }
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
    return HashTable::numOfcollision;
}