/**
 * @file BST.cpp
 * @brief The main source file for the BST Class
 */

#include "BST.hpp"
#define COUNT 10

BST::BST()
{
    BST::root = nullptr;
}

BST::~BST()
{
     destroyNode(BST::root);
}

Node* BST::getRoot()
{
    return BST::root;
}

void BST::destroyNode(Node *currNode){
     if(currNode != nullptr)
     {
         destroyNode(currNode->left);
         destroyNode(currNode->right);

         delete currNode;
         currNode = nullptr;
     }
 }

/*
Prints a binary tree in a 2D fashion.
Note: The image of the tree is left rotated by 90 degrees.
*/
void BST::print2DUtilHelper(Node *currNode, int space)
{
    // Base case
    if (currNode == nullptr)
    {
        return;
    }

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtilHelper(currNode->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", currNode->key);

    // Process left child
    print2DUtilHelper(currNode->left, space);
}

void BST::print2DUtil(int space)
{
    print2DUtilHelper(BST::root, space);
}



//---------------------------- INSERT NODE IN THE TREE --------------------------------------

/**
Create a node with key as data
**/
Node* BST::createNode(int data)
{
    Node* newNode = new Node;
    newNode->key = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

/**
This function will add the data in the tree rooted at currNode.
We will call this function from addNode.
**/
Node* BST:: addNodeHelper(Node* currNode, int data)
{
    if(currNode == nullptr)
    {
        return createNode(data);
    }
    else if(currNode->key < data)
    {
        currNode->right = addNodeHelper(currNode->right,data);
    }
    else if(currNode->key > data)
    {
        currNode->left = addNodeHelper(currNode->left,data);
    }
    return currNode;
}

void BST:: addNode(int data)
{
    BST::root = addNodeHelper(BST::root, data);
    std::cout << data << " has been added" << std::endl;
}

//-----------------------------------------PRINT TREE (INORDER TRAVERSAL)--------------------------------

/** This function will traverse the tree in-order and print out the node elements.
printTree() function will call this function.
**/

void BST:: printTreeHelper(Node* currNode)
{
     if(currNode)
     {
        printTreeHelper( currNode->left);
        std::cout << " "<< currNode->key;
        printTreeHelper( currNode->right);
     }
 }

void BST:: printTree()
{
     printTreeHelper(BST::root);
     std::cout << std::endl;
}

 //------------------------------------------------SEARCH A KEY------------------------------------------
 /** This function will search the data in a tree
     We will call this function from searchKey.
 **/

Node* BST::searchKeyHelper(Node* currNode, int data)
{
    if(currNode == nullptr)
    {
        return nullptr;
    }

    if(currNode->key == data)
    {
        return currNode;
    }

    if(currNode->key > data)
    {
        return searchKeyHelper(currNode->left, data);
    }
    return searchKeyHelper (currNode->right, data);
}

// This function will return whether a key is in the tree
bool BST::searchKey(int key)
{
    Node* tree = searchKeyHelper(BST::root, key);
    if(tree != nullptr) 
    {
        return true;
    }
    std::cout << "Key not present in the tree" << std::endl;
    return false;
}
