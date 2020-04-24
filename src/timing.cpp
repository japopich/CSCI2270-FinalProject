/**
 * @file timing.cpp
 * @brief The timing source file for the timing class
 */

#include "timing.hpp"

// Default Constructor
Timing::Timing()
{

}

// File Loading Constructor
// Places all the contents of the file into a vector for usage
Timing::Timing(std::string file)
{
    // Open the file
    Timing::file.open(file);

    // Check to see if the file is open else return error
    if(!Timing::file.is_open())
    {
        std::cout << "Failed to open the file." << std::endl;
        return;
    }

    // Buffer that will hold our data from the file temporarily and allow us to manipulate it
    std::stringstream ss;

    // Read from the file into the stringstream
    ss << Timing::file.rdbuf();

    // Add a comma on the end to get the last item
    std::string data = ss.str();
    data = data + ",";

    // Define our delimiter
    std::string delimiter = ",";

    // Declare our token string that will hold the current string
	std::string token;

    // Declare our variable that will keep track of our position
    size_t pos = 0;

    // Start the loop placing into the file_content vector
    while ((pos = data.find(delimiter)) != std::string::npos) 
	{
		token = data.substr(0, pos);
		data.erase(0, pos + delimiter.length());
        Timing::file_content.push_back(std::stoi(token));
    }

    // Close the file
    Timing::file.close();
}

// Destructor
Timing::~Timing()
{

}

void Timing::timing_BST()
{
    // The chrono timepoint objects that will be used to time the data structures
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point end;

    // Create the vectors to store the time values
    std::vector<std::vector<float>> BSTvector;
    std::vector<float> insertVector;
    std::vector<float> searchVector;

    // Create the BST Object
    BST bstObject;

    // Insert the Data into the BST and time while doing so using chrono every 100 samples
    // Also search the BST and time it after every 100
    for (size_t i = 0; i < Timing::file_content.size(); i = i+100)
    {
        //--------------------------------
        // Insert data into the BST and time it.
        //--------------------------------
        start = std::chrono::steady_clock::now();
        for (size_t j = i; j < (i+100); j++)
        {
            bstObject.addNode(Timing::file_content[j]);
        }
        end = std::chrono::steady_clock::now();

        // Store the average insert time so divide the count by 100 to get average and then store in respective vector
        float avgInsertTime = (std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()) / 100.f;
        insertVector.push_back(avgInsertTime);

        //--------------------------------
        // Search the BST and time it.
        //--------------------------------

        // First create a random vector of 100 datapoint indexes to pull and search
        std::vector<int> keySet;
        for (size_t k = 0; k < 100; k++)
        {
            int randomindex = rand() % (i+100);
            keySet.push_back(Timing::file_content[randomindex]);
        }

        // Now perform the 100 searches and time it
        start = std::chrono::steady_clock::now();
        for (auto &i : keySet)
        {
            bstObject.searchKey(i);
        }
        end = std::chrono::steady_clock::now();

        // Store the average search time so divide the count by 100 to get average and then store in respective vector
        float avgSearchTime = (std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()) / 100.f;
        searchVector.push_back(avgSearchTime);
    }

    // Place the insert and search vectors into the BST vector
    BSTvector.push_back(insertVector);
    BSTvector.push_back(searchVector);

    // Place the BSTvector into the recordedTime vector
    Timing::recordedTime.push_back(BSTvector);
}

void Timing::timing_LL()
{

}

void Timing::timing_Hash()
{
    
}

void Timing::output2file()
{

}