/**
 * @file main.cpp
 * @brief The main source file for the code bases
 */

/*********************************************************************/
/*                                                                   */
/*                      CSCI2270 - Final Project                     */
/*                                                                   */
/*                                                                   */
/*                           Jason Popich                            */
/*                        Matthew Januszewski                        */
/*                                                                   */
/*                         MAIN SOURCE FILE                          */
/*                                                                   */
/*********************************************************************/

#include "timing.hpp"


int main(int argc, char **argv)
{
    Timing dataSet1("../DataSets/dataSetA.csv", "1");
    dataSet1.timing_LL();
    dataSet1.timing_BST();
    dataSet1.timing_LLHash();
    dataSet1.timing_LinHash();
    dataSet1.timing_QuadHash();
    dataSet1.output2file();
    
    Timing dataSet2("../DataSets/dataSetB.csv", "2");
    dataSet2.timing_LL();
    dataSet2.timing_BST();
    dataSet2.timing_LLHash();
    dataSet2.timing_LinHash();
    dataSet2.timing_QuadHash();
    dataSet2.output2file();
    return 0;
}