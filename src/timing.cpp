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
    if (!Timing::file.is_open())
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

    // Seed the random number generator with computer's time
    srand(time(NULL));
}

// Destructor
Timing::~Timing()
{
}

void Timing::timing_BST()
{
    for (size_t i = 0; i < Timing::file_content.size(); i = i + 100)
    {
        std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
        for (size_t j = i; j < (i + 100); j++)
        {
        }
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        // std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }
}

void Timing::timing_LL()
{
    // Creates a linked list and adds elements to it from file_content, times how long search and insert
    // operations take as data is added

    LinkedList list;

    // Create time_point objects to keep track of how long operations take
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point end;

    for (int k = 0; k < 40; k++)
    {
        // Insert 100 elements and time the operation
        start = std::chrono::steady_clock::now();
        for (int i = k * 100; i < (k + 1) * 100; i++)
        {
            list.insert(file_content[i]);
        }
        end = std::chrono::steady_clock::now();

        // *** Store insert time ***

        // Search for 100 elements and time the operation
        int index = 0;
        int key = 0;
        LLNode *node = nullptr;
        start = std::chrono::steady_clock::now();
        for (int i = k * 100; i < (k + 1) * 100; i++)
        {
            index = rand() % (k * 100);
            key = file_content[index];

            node = list.search(key);

            // *** Checks for accuracy of search function, remove for actual testing
            if (node->key != key)
            {
                std::cout << "Linked list search function is incorrect";
            }
            // *********************************************************************
        }
        end = std::chrono::steady_clock::now();

        // *** Store search time divided by 100 ***
    }
}

void Timing::timing_Hash()
{
}

void Timing::output2file()
{
}