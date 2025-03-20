#include <WordReader.h>
#include <iostream>
#include <ctime>

// Constructor - opens file and determines file length
WordReader::WordReader(const std::string& filePath) 
{
    fp.open(filePath, std::ios::binary);
    if (!fp) {
        throw std::runtime_error("Failed to open file.");
    }

    fp.seekg(0, std::ios::end);   // Move pointer to end of file
    file_len = fp.tellg();         // Store file length
    fp.seekg(0, std::ios::beg);   // Return to beginning

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

// Extracts a random word from the file
std::string WordReader::extract_word() 
{
    if (!fp) 
    {
        throw std::runtime_error("File not open.");
    }

    size_t random_spot = std::rand() % file_len; // Random byte position
    fp.seekg(random_spot, std::ios::beg);

    // Backup character by character until newline boundary is found
    char c;
    while (random_spot > 0) 
    {
        fp.seekg(-1, std::ios::cur);
        c = fp.peek();
        if (c == '\n') 
        {
            fp.seekg(1, std::ios::cur);
            break;
        }
        random_spot--;
    }

    // Extract the word
    std::string read_word;
    std::getline(fp, read_word);
    return read_word;
}

// Destructor - closes file
WordReader::~WordReader() 
{
    if (fp.is_open()) 
    {
        fp.close();
    }
}
