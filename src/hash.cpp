/**
 * @file hash.cpp
 * @brief The main source file for the HashTable Class
 */

#include "hash.hpp"

HashTable::HashTable(int bsize)
{

}

HashTable::~HashTable()
{
    
}

node* HashTable::createNode(int key, node* next)
{
    node* newNode = new node;
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
    node* newNode = HashTable::createNode(key, nullptr);

    // If no node exists at that index append newNode as head
    if(HashTable::table[nodeIndex] == nullptr)
    {
        newNode->prev = nullptr;
        HashTable::table[nodeIndex] = newNode;
        return true;
    }
    else // else append to chained LinkedList
    {
        HashTable::numOfcollision++; // Add to collision....
        // Set the node at the Hash Table index as our LinkedList (LL) head
        node* head = HashTable::table[nodeIndex];

        // Check for duplicates in LL
        while(head != nullptr)
        {
            if(head->key == key)
            {
                std::cout << "Duplicate Key!" << std::endl;
                return false;
            }
            head = head->next;
        }

        // NO duplicates so append the new node
        head = HashTable::table[nodeIndex]; // Set Head again
        while((head != nullptr) && (newNode->key > head->key))
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

node* HashTable::searchLLItem(int key)
{
    // Get the index of where the key should be
    int nodeIndex = HashTable::hashFunction(key);

    // If an index does exist for that key enter if statement
    if(HashTable::table[nodeIndex] != nullptr)
    {
        // Set the currNode to the node at the index
        node* currNode = HashTable::table[nodeIndex];

        // If the node is not equal to nullptr, check to see if key is equal to key we're looking for
        // if not check attached LinkedList
        while(currNode != nullptr)
        {
            if(currNode->key == key)
            {
                return currNode;
            }else
            {
                currNode = currNode->next;
            }
        }
    }
    return nullptr; // If key not found at all return nullptr
}

node* HashTable::searchLinearItem(int key)
{

}

node* HashTable::searchQuadItem(int key)
{
    
}

void HashTable::printTable()
{

}

int HashTable::getNumOfCollision()
{
    return HashTable::numOfcollision;
}
