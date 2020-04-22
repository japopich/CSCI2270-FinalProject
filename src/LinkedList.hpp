/**
 * @file LinkedList.hpp
 * @brief The main header file for the LinkedList Class
 */
#ifndef _LINKED_LIST_HPP_
#define _LINKED_LIST_HPP_

struct LLNode
{
    int key;
    LLNode *next;
};

class LinkedList
{
private:
    LLNode *head;

public:
    LinkedList();
    ~LinkedList();
    void insert(LLNode *prev, int newKey); // Inserts after prev
    void insert(int newKey);             // Inserts at the end of the list
    LLNode *search(int key);
    void displayAll();      // Displays all LLNodes in the list
    void displayFirst100(); // Displays the first 100 LLNodes in the list
};

#endif