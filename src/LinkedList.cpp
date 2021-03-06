/**
 * @file LinkedList.cpp
 * @brief The main source file for the LinkedList Class
 */

/*********************************************************************/
/*                                                                   */
/*                      CSCI2270 - Final Project                     */
/*                                                                   */
/*                                                                   */
/*                           Jason Popich                            */
/*                        Matthew Januszewski                        */
/*                                                                   */
/*                      LINKED LIST SOURCE FILE                      */
/*                                                                   */
/*********************************************************************/

#include <iostream>
#include "LinkedList.hpp"

LinkedList::LinkedList()
{
    LinkedList::head = nullptr;
}

LinkedList::~LinkedList()
{
    // Iterate through the LL and delete all dynamic nodes
    LLNode *current = LinkedList::head;
    LLNode *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::insert(LLNode *prev, int newKey)
{
    // Inserts newKey after prev
    LLNode *newNode = new LLNode;
    newNode->key = newKey;

    LLNode *current = LinkedList::head;

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
    LLNode *newNode = new LLNode;
    newNode->key = newKey;
    newNode->next = nullptr;

    if (LinkedList::head == nullptr)
    {
        LinkedList::head = newNode;
        return;
    }

    LLNode *current = LinkedList::head;

    while (current->next != nullptr)
    {
        if(current->key == newKey)
        {
            // std::cout << newKey << " is Duplicate Key in Linked List! Ignoring... " << std::endl;
            return;
        }
        current = current->next;
    }

    current->next = newNode;
}

LLNode *LinkedList::search(int key)
{
    // Returns LLNode* with key equal to input, if key is not found returns nullptr
    LLNode *current = LinkedList::head;
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
    LLNode *current = LinkedList::head;
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
    LLNode *current = LinkedList::head;
    int counter = 0;

    while (current != nullptr && counter < 100)
    {
        std::cout << "Key: " << current->key << " -->" << std::endl;
        current = current->next;
        counter++;
    }

    std::cout << "nullptr" << std::endl;
}