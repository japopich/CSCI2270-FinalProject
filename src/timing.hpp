/**
 * @file timing.hpp
 * @brief The timing header file for the timing class
 */

#ifndef _TIMING_HPP_
#define _TIMING_HPP_

#include "hash.hpp"
#include "LinkedList.hpp"
#include "BST.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>

class Timing
{
    private:
        std::ifstream file;                     // Our file ifstream object
        std::vector<int> file_content;          // Will hold all the data to be used with every method

        // Variables to record timing in 100 sample intervals
        float insert[400];
        float search[400];

    public:
        Timing();                               // Default Constructor
        Timing(std::string file);               // File Loading Constructor

        ~Timing();                              // Default Destructor

        void timing_BST();                      // Timing function for Binary Search Tree
        void timing_LL();                       // Timing function for Linked List
        void timing_Hash();                     // Timing function for Hash Table
};


#endif