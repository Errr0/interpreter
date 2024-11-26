#include <iostream>
#include <fstream>
#include <sstream>
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

void tokenize(std::string str, std::vector<std::string> &tokens){
    std::vector<std::string> arr;
    split(str, arr);
    
}

bool readfile(std::string filename, std::vector<std::string> &arr){
    std::fstream file(filename, std::ios::in);
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return 0;
    }
    std::ostringstream buffer;
    buffer << file.rdbuf();  // Read the entire file buffer into the stream
    std::string content = buffer.str();
    file.close();
    std::cout << content << std::endl;//debug
    split(content, arr, ';');
    for (const auto& w : arr) {//debug
        std::cout << w << std::endl;
    }
}

int main(int argc, char* argv[]){
    //std::cout << "Number of arguments: " << argc << std::endl;
    //for (int i = 0; i < argc; ++i) {std::cout << "Argument " << i << ": " << argv[i] << std::endl;}
    if(argc<2) {
        std::cerr << "Error no path argument!" << std::endl;
        return 1;
    }
    std::vector<std::string> statements;
    if(!readfile(argv[1], statements)) return 2;

    //std::vector<std::string> tokens;
    //std::getline(file, line);
    //std::cout << line << "\n";
    //split(line, tokens);
    // Print the result


    return 0;
}