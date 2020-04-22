/**
 * @file LinkedList.cpp
 * @brief The main source file for the LinkedList Class
 */

#include <iostream>
#include "LinkedList.hpp"

LinkedList::LinkedList()
{
    LinkedList::head = nullptr;
}

LinkedList::~LinkedList()
{
    // Iterate through the LL and delete all dynamic nodes
    Node *current = LinkedList::head;
    Node *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::insert(Node *prev, int newKey)
{
    // Inserts newKey after prev
    Node *newNode = new Node;
    newNode->key = newKey;

    Node *current = LinkedList::head;

    while (current != prev)
    {
        current = current->next;
    }

    if (current != nullptr)
    {
        newNode->next = current->next;
        current->next = newNode;
    }
}

void LinkedList::insert(int newKey)
{
    // Inserts newKey at the end of the linked list
    Node *newNode = new Node;
    newNode->key = newKey;
    newNode->next = nullptr;

    Node *current = LinkedList::head;

    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = newNode;
}

Node *LinkedList::search(int key)
{
    // Returns Node* with key equal to input, if key is not found returns nullptr
    Node *current = LinkedList::head;
    while (current != nullptr && current->key != key)
    {
        current = current->next;
    }

    if (current->key == key)
    {
        return current;
    }

    return nullptr;
}

void LinkedList::displayAll()
{
    // Displays entire contents of the linked list
    Node *current = LinkedList::head;
    while (current != nullptr)
    {
        std::cout << "Key: " << current->key << " -->" << std::endl;
        current = current->next;
    }

    std::cout << "nullptr" << std::endl;
}

void LinkedList::displayFirst100()
{
    // Displays the first 100 nodes of the linked list
    Node *current = LinkedList::head;
    int counter = 0;

    while (current != nullptr && counter < 100)
    {
        std::cout << "Key: " << current->key << " -->" << std::endl;
        current = current->next;
        counter++;
    }

    std::cout << "nullptr" << std::endl;
}