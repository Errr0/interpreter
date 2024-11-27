#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>

enum TokenType {
    END = 0
};

class Token{
    std::string value;
    enum TokenType type;
    Token(std::string value = "",enum TokenType type = END){
        this -> value = value;
        this -> type = type;
    }
};


void split(std::string str, std::vector<std::string> &arr, char symbol = ' ') {
    size_t start = 0, end = str.find(symbol);//int with different name
    while (end != std::string::npos) {
        if(start != end)
        arr.push_back(str.substr(start, end - start));
        start = end + 1; // Move past the space
        end = str.find(symbol, start);
    }
    if(str.substr(start) != " " && str.substr(start) != "")
    arr.push_back(str.substr(start)); // Add the last word
}

void replace(std::string &str, std::string from, std::string to) {
    str = std::regex_replace(str, std::regex(from), to);
}

void parse(std::string str, std::vector<std::string> &tokens){
    std::vector<std::string> words;
    replace(str, "\n", " ");
    split(str, words);
    for (std::string w : words) {
        std::cout << w << std::endl;
            //tokens.push_back("END");
    }
}

bool readfile(std::string filename, std::vector<std::string> &statements){
    std::fstream file(filename, std::ios::in);
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return 0;
    }
    std::ostringstream buffer;
    buffer << file.rdbuf();  // Read the entire file buffer into the stream
    std::string content = buffer.str();
    file.close();
    //std::cout << content << std::endl;//debug
    std::vector<std::string> tokens;
    split(content, statements, ';');

    for (auto& w : statements) {//debug
        parse(w, tokens);

        //std::cout << " statement: "<< w << std::endl;
    }
    return 1;
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