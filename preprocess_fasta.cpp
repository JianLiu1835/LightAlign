#include"f.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdio>

using namespace std;

void prepro(string input_file)
{
    const string output_file = input_file + ".tmp";

    std::ifstream input(input_file);
    if (!input) {
        std::cout << "Error: Could not open input file: " << input_file << "\n";
    }

    std::ofstream output(output_file);
    if (!output) {
        std::cout << "Error: Could not create output file: " << output_file << "\n";
    }

    std::string line, sequence;
    bool in_sequence = false;
    size_t sequence_count = 0;

    while (std::getline(input, line)) {
        if (!line.empty() && line[0] == '>') 
        {
            if (in_sequence) {
                output << sequence << '\n';
                sequence.clear();
                sequence_count++;
            }
            output << line << '\n';
            in_sequence = true;
        }
        else if (in_sequence) {
            for (char c : line) {
                if (!std::isspace(static_cast<unsigned char>(c))) 
                {
                    sequence += c;
                }
            }
        }
    }

    if (in_sequence && !sequence.empty()) 
    {
        output << sequence << '\n';
        sequence_count++;
    }

    input.close();
    output.close();

    if (!output) 
    {
        std::cout << "Error: Failed to write output file\n";
        std::remove(output_file.c_str());
    }

    if (std::remove(input_file.c_str()) != 0) 
    {
        std::cerr << "Error: Failed to delete original file (" << input_file
            << "). Output saved to " << output_file << "\n";
    }

    // rename
    if (std::rename(output_file.c_str(), input_file.c_str())) 
    {
        std::cout << "Error: Failed to rename output file. Result saved in "
            << output_file << "\n";
    }

    std::cout << "Success! Processed " << sequence_count << " sequences\n"
        << "Original file replaced with reformatted version: " << input_file << "\n";

}