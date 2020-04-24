/**
 * @file main.cpp
 * @brief The main source file for the code bases
 */
#include "timing.hpp"


int main(int argc, char **argv)
{
    Timing dataSet1("../DataSets/dataSetA.csv");
    dataSet1.timing_LL();
    dataSet1.timing_BST();
    dataSet1.timing_Hash();
    
    Timing dataSet2("../DataSets/dataSetB.csv");
    return 0;
}