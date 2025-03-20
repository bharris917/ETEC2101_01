#pragma once
#ifndef WORD_READER_H
#define WORD_READER_H

#include <fstream>
#include <string>

class WordReader {
private:
    std::ifstream fp;   // File stream for reading
    size_t file_len;    // File length for random byte calculation

public:
    // Constructor that opens the file in binary mode
    WordReader(const std::string& filePath);

    // Function to extract a random word
    std::string extract_word();

    // Destructor to close the file
    ~WordReader();
};

#endif // WORD_READER_H
