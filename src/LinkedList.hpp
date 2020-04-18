/**
 * @file LinkedList.hpp
 * @brief The main header file for the LinkedList Class
 */
#ifndef _LINKED_LIST_HPP_
#define _LINKED_LIST_HPP_

struct Node
{
    int key;
    Node *next;
};

class LinkedList
{
    private:
        Node *head;

    public:
        LinkedList();
        ~LinkedList();
        void insert(Node *prev, int newKey); // Inserts after prev
        void insert(int newKey); // Inserts at the end of the list
        Node *search(int key);
        void displayAll(); // Displays all nodes in the list
        void displayFirst100(); // Displays the first 100 nodes in the list
};

#endif