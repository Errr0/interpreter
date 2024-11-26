#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void split(std::string str, std::vector<std::string> &arr, char symbol = ' ') {
    int start = 0, end = str.find(' ');
    while (end != std::string::npos) {
        arr.push_back(str.substr(start, end - start));
        start = end + 1; // Move past the space
        end = str.find(symbol, start);
    }
    arr.push_back(str.substr(start)); // Add the last word
}

int main(int argc, char* argv[]){
    std::cout << "Number of arguments: " << argc << std::endl;

    // Loop through each argument
    for (int i = 0; i < argc; ++i) {
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    }
    ////////////////////////////////////////
    if(argc<2) {
        std::cerr << "Error no path argument!" << std::endl;
        return 1;
    }
    std::fstream file(argv[1], std::ios::in);
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return 2;
    }
    std::string line;
    std::vector<std::string> tokens;
    std::getline(file, line);
    std::cout << line << "\n";
    split(line, tokens);
    // Print the result
    for (const auto& w : tokens) {
        std::cout << w << std::endl;
    }

    return 0;
}