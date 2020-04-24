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
    std::srand(std::time(nullptr));
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
    for (size_t i = 0; i < Timing::file_content.size(); i = i + 100)
    {
        //--------------------------------
        // Insert data into the BST and time it.
        //--------------------------------
        start = std::chrono::high_resolution_clock::now();
        for (size_t j = i; j < (i + 100); j++)
        {
            bstObject.addNode(Timing::file_content[j]);
        }
        end = std::chrono::high_resolution_clock::now();

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
            int randomindex = rand() % (i + 100);
            keySet.push_back(Timing::file_content[randomindex]);
        }

        // Now perform the 100 searches and time it
        start = std::chrono::high_resolution_clock::now();
        for (auto &i : keySet)
        {
            bstObject.searchKey(i);
        }
        end = std::chrono::high_resolution_clock::now();

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
    // Creates a linked list and adds elements to it from file_content, times how long search and insert
    // operations take as data is added
    int test = file_content[0];

    LinkedList list;

    // Create time_point objects to keep track of how long operations take
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point end;

    // Create the vectors to store the time values
    std::vector<std::vector<float>> LLvector;
    std::vector<float> insertVector;
    std::vector<float> searchVector;

    for (int k = 0; k < 400; k++)
    {
        // Insert 100 elements and time the operation
        start = std::chrono::high_resolution_clock::now();
        for (size_t i = k * 100; i < (k + 1) * 100; i++)
        {
            list.insert(file_content[i]);
        }
        end = std::chrono::high_resolution_clock::now();

        // Store the average insert time so divide the count by 100 to get average and then store in respective vector
        float avgInsertTime = (std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()) / 100.f;
        insertVector.push_back(avgInsertTime);

        // Search for 100 random elements and time the operation
        int randomIndices[100];
        for (size_t i = 0; i < 100; i++)
        {
            randomIndices[i] = rand() % ((k + 1) * 100);
        }

        int key = 0;
        LLNode *node = nullptr;
        start = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < 100; i++)
        {
            key = file_content[randomIndices[i]];
            node = list.search(key);
        }
        end = std::chrono::high_resolution_clock::now();

        // Store the average search time so divide the count by 100 to get average and then store in respective vector
        float avgSearchTime = (std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()) / 100.f;
        searchVector.push_back(avgSearchTime);
    }

    // Place the insert and search vectors into the BST vector
    LLvector.push_back(insertVector);
    LLvector.push_back(searchVector);

    // Place the BSTvector into the recordedTime vector
    Timing::recordedTime.push_back(LLvector);
}

void Timing::timing_LinHash()
{
    // Creates a hash table using linear probing and adds elements to it from file_content, times how long search and insert
    // operations take as data is added

    HashTable table(40000);

    // Create time_point objects to keep track of how long operations take
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point end;

    // Create the vectors to store the time values
    std::vector<std::vector<float>> hashVector;
    std::vector<float> insertVector;
    std::vector<float> searchVector;

    for (int k = 0; k < 400; k++)
    {
        // Insert 100 elements and time the operation
        start = std::chrono::high_resolution_clock::now();
        for (size_t i = k * 100; i < (k + 1) * 100; i++)
        {
            table.insertLinearitem(file_content[i]);
        }
        end = std::chrono::high_resolution_clock::now();

        // Store the average insert time so divide the count by 100 to get average and then store in respective vector
        float avgInsertTime = (std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()) / 100.f;
        insertVector.push_back(avgInsertTime);

        // Search for 100 random elements and time the operation
        int randomIndices[100];
        for (size_t i = 0; i < 100; i++)
        {
            randomIndices[i] = rand() % ((k + 1) * 100);
        }

        int key = 0;
        node *node = nullptr;
        start = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < 100; i++)
        {
            key = file_content[randomIndices[i]];

            node = table.searchLinearItem(key);

            // *** Checks for accuracy of search function, remove for actual testing
            if (node->key != key)
            {
                std::cout << "Linear hash search function is incorrect";
            }
            // *********************************************************************
        }
        end = std::chrono::high_resolution_clock::now();

        // Store the average search time so divide the count by 100 to get average and then store in respective vector
        float avgSearchTime = (std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()) / 100.f;
        searchVector.push_back(avgSearchTime);
    }

    // Place the insert and search vectors into the BST vector
    hashVector.push_back(insertVector);
    hashVector.push_back(searchVector);

    // Place the BSTvector into the recordedTime vector
    Timing::recordedTime.push_back(hashVector);
}

void Timing::timing_QuadHash()
{
    // Creates a hash table using quadratic probing and adds elements to it from file_content, times how long search and insert
    // operations take as data is added

    HashTable table(40000);

    // Create time_point objects to keep track of how long operations take
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point end;

    // Create the vectors to store the time values
    std::vector<std::vector<float>> hashVector;
    std::vector<float> insertVector;
    std::vector<float> searchVector;

    for (int k = 0; k < 400; k++)
    {
        // Insert 100 elements and time the operation
        start = std::chrono::high_resolution_clock::now();
        for (size_t i = k * 100; i < (k + 1) * 100; i++)
        {
            table.insertQuaditem(file_content[i]);
        }
        end = std::chrono::high_resolution_clock::now();

        // Store the average insert time so divide the count by 100 to get average and then store in respective vector
        float avgInsertTime = (std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()) / 100.f;
        insertVector.push_back(avgInsertTime);

        // Search for 100 random elements and time the operation
        int randomIndices[100];
        for (size_t i = 0; i < 100; i++)
        {
            randomIndices[i] = rand() % ((k + 1) * 100);
        }

        int key = 0;
        node *node = nullptr;
        start = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < 100; i++)
        {
            key = file_content[randomIndices[i]];

            node = table.searchQuadItem(key);

            // *** Checks for accuracy of search function, remove for actual testing
            if (node->key != key)
            {
                std::cout << "Quad hash search function is incorrect";
            }
            // *********************************************************************
        }
        end = std::chrono::high_resolution_clock::now();

        // Store the average search time so divide the count by 100 to get average and then store in respective vector
        float avgSearchTime = (std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()) / 100.f;
        searchVector.push_back(avgSearchTime);
    }

    // Place the insert and search vectors into the BST vector
    hashVector.push_back(insertVector);
    hashVector.push_back(searchVector);

    // Place the BSTvector into the recordedTime vector
    Timing::recordedTime.push_back(hashVector);
}

void Timing::timing_LLHash()
{
    // Creates a hash table using linear probing and adds elements to it from file_content, times how long search and insert
    // operations take as data is added

    HashTable table(40000);

    // Create time_point objects to keep track of how long operations take
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point end;

    // Create the vectors to store the time values
    std::vector<std::vector<float>> hashVector;
    std::vector<float> insertVector;
    std::vector<float> searchVector;

    for (int k = 0; k < 400; k++)
    {
        // Insert 100 elements and time the operation
        start = std::chrono::high_resolution_clock::now();
        for (size_t i = k * 100; i < (k + 1) * 100; i++)
        {
            table.insertLLitem(file_content[i]);
        }
        end = std::chrono::high_resolution_clock::now();

        // Store the average insert time so divide the count by 100 to get average and then store in respective vector
        float avgInsertTime = (std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()) / 100.f;
        insertVector.push_back(avgInsertTime);

        // Search for 100 random elements and time the operation
        int randomIndices[100];
        for (size_t i = 0; i < 100; i++)
        {
            randomIndices[i] = rand() % ((k + 1) * 100);
        }

        int key = 0;
        node *node = nullptr;
        start = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < 100; i++)
        {
            key = file_content[randomIndices[i]];

            node = table.searchLLItem(key);

            // *** Checks for accuracy of search function, remove for actual testing
            if (node->key != key)
            {
                std::cout << "LL hash search function is incorrect";
            }
            // *********************************************************************
        }
        end = std::chrono::high_resolution_clock::now();

        // Store the average search time so divide the count by 100 to get average and then store in respective vector
        float avgSearchTime = (std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()) / 100.f;
        searchVector.push_back(avgSearchTime);
    }

    // Place the insert and search vectors into the BST vector
    hashVector.push_back(insertVector);
    hashVector.push_back(searchVector);

    // Place the BSTvector into the recordedTime vector
    Timing::recordedTime.push_back(hashVector);
}

void Timing::LL_outHelper()
{
    std::ofstream LL_out("LL_out.csv");
    std::stringstream ss;

    for (size_t i = 0; i < Timing::recordedTime[0][0].size(); i++)
    {
        ss << std::setprecision(16) << Timing::recordedTime[0][0][i] << "," << Timing::recordedTime[0][1][i] << "\n";
    }
    LL_out << ss.str();

    LL_out.close();
}

void Timing::BST_outHelper()
{
    std::ofstream BST_out("BST_out.csv");
    std::stringstream ss;

    for (size_t i = 0; i < Timing::recordedTime[1][0].size(); i++)
    {
        ss << std::setprecision(16) << Timing::recordedTime[1][0][i] << "," << Timing::recordedTime[1][1][i] << "\n";
    }
    BST_out << ss.str();

    BST_out.close();
}

void Timing::LLHash_outHelper()
{
    std::ofstream LLHash_out("LLHash_out.csv");
    std::stringstream ss;

    for (size_t i = 0; i < Timing::recordedTime[2][0].size(); i++)
    {
        ss << std::setprecision(16) << Timing::recordedTime[2][0][i] << "," << Timing::recordedTime[2][1][i] << "\n";
    }
    LLHash_out << ss.str();

    LLHash_out.close();
}

void Timing::LinHash_outHelper()
{
    std::ofstream LinHash_out("LinHash_out.csv");
    std::stringstream ss;

    for (size_t i = 0; i < Timing::recordedTime[3][0].size(); i++)
    {
        ss << std::setprecision(16) << Timing::recordedTime[3][0][i] << "," << Timing::recordedTime[3][1][i] << "\n";
    }
    LinHash_out << ss.str();

    LinHash_out.close();
}

void Timing::QuadHash_outHelper()
{
    std::ofstream QuadHash_out("QuadHash_out.csv");
    std::stringstream ss;

    for (size_t i = 0; i < Timing::recordedTime[4][0].size(); i++)
    {
        ss << std::setprecision(16) << Timing::recordedTime[4][0][i] << "," << Timing::recordedTime[4][1][i] << "\n";
    }
    QuadHash_out << ss.str();

    QuadHash_out.close();
}

void Timing::output2file()
{
    Timing::LL_outHelper();
    Timing::BST_outHelper();
    Timing::LLHash_outHelper();
    Timing::LinHash_outHelper();
    //Timing::QuadHash_outHelper();
}