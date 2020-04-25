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
        std::string id;                         // Our object ID for file output

        std::ifstream file;                     // Our file ifstream object
        std::vector<int> file_content;          // Will hold all the data to be used with every method

        // Vector that will hold timing in 100 sample intervals
        // Layer 1:                             Vector
        // Layer 2:       BST Vector          LL Vector          Hash Vector
        // Layer 3:     Insert-Search       Insert-Search       Insert-Search
        std::vector<std::vector<std::vector<float>>> recordedTime;

        void LL_outHelper();                    // Helper function to output the timing results for LinkedList
        void BST_outHelper();                   // Helper function to output the timing results for Binary Search Tree
        void LLHash_outHelper();                // Helper function to output the timing results for Chaining Hash Table
        void LinHash_outHelper();               // Helper function to output the timing results for Linear Probing Hash Table
        void QuadHash_outHelper();              // Helper function to output the timing results for Quadratic Probing Hash Table

    public:
        Timing();                               // Default Constructor
        Timing(std::string file, std::string id);       // File Loading Constructor

        ~Timing();                              // Default Destructor

        void timing_BST();                      // Timing function for Binary Search Tree
        void timing_LL();                       // Timing function for Linked List
        void timing_LinHash();                  // Timing function for Linear Probing Hash Table
        void timing_QuadHash();                 // Timing function for Quadratic Probing Hash Table
        void timing_LLHash();                   // Timing function for Chaining Hash Table

        void output2file();                     // Will output the recordedTime vector to respective file
};

#endif