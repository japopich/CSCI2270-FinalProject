/**
 * @file BST.cpp
 * @brief The main header file for the BST Class
 */

#ifndef _BST_HPP_
#define _BST_HPP_

#include <iostream>

struct Node
{
    int key;
    Node* left;
    Node* right;
};

class BST
{
    private:
        Node* root;                             // Root of BST Tree

        Node* createNode(int data);             // Helper function to create a Node
        Node* addNodeHelper(Node*, int);        // Helper function to create emplace a Node at a location
        Node* searchKeyHelper(Node*, int);      // Helper function to find a Node in a tree

        void printTreeHelper(Node*);            // Helper function to print a tree
        void print2DUtilHelper(Node *, int);    // Helper function to print a 2D tree view

        void destroyNode(Node *root);           // Destroys a subtree from a given Node (Used in Destructor)

    public:

        BST();                                  // Default Constructor
        ~BST();                                 // Default Destructor

        Node* getRoot();                        // Returns the root of the tree;
        void addNode(int);                      // Inserts Node into tree
        bool searchKey(int);                    // Search for a Node in the tree
        void printTree();                       // Prints Tree
        void print2DUtil(int);                  // Prints 2D Version of tree (DO NOT CALL FOR MASSIVE TREES)

};

#endif