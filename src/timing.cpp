/**
 * @file timing.cpp
 * @brief The timing source file for the timing class
 */

#include "timing.hpp"

// Constructor
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

}

void Timing::timing_LL()
{

}

void Timing::timing_Hash()
{
    
}