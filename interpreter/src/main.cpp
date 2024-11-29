#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <array>
#include <map>
#include <regex>

enum TokenType {
    END,
    //arithmetics
    ASSIGN,
    PLUS,
    MINUS,
    ASTERISK,
    SLASH,
    MODULO,
    MULTIPLY,
    DIVIDE,
    ADD,
    SUBTRACT,
    //logic
    NOT,
    AND,
    OR,
    EQUAL,
    NOTEQUAL,
    LESSTHAN,
    LESSEQUAL,
    GREATERTHAN,
    GREATEREQUAL,
    //
    INT,
    FLOAT,
    IDENTIFIER,
    //
    BRACKETOPEN,
    BRACKETCLOSE,
    SQUAREBRACKETOPEN,
    SQUAREBRACKETCLOSE,
    CURLYBRACKETOPEN,
    CURLYBRACKETCLOSE,
    APOSTROPHE,
    QUOTATION,
    QUESTIONMARK,
    COMMA,
    COLON,
    DOT,
    BACKSLASH,
    DOUBLESLASH,
    HASHTAG
};

std::map<std::string, TokenType> map = {
    {";", END},
    {"=", ASSIGN},
    {"+", PLUS},
    {"-", MINUS},
    {"*", ASTERISK},
    {"/", SLASH},
    {"%", MODULO},
    {"+=", ADD},
    {"-=", SUBTRACT},
    {"*=", MULTIPLY},
    {"/=", DIVIDE},
    
    {"!", NOT},
    {"&&", AND},
    {"||", OR},
    {"==", EQUAL},
    {"!=", NOTEQUAL},
    {"<", LESSTHAN},
    {"<=", LESSEQUAL},
    {">", GREATERTHAN},

    {"(", BRACKETOPEN},
    {")", BRACKETCLOSE},
    {"[", SQUAREBRACKETOPEN},
    {"]", SQUAREBRACKETCLOSE},
    {"{", CURLYBRACKETOPEN},
    {"}", CURLYBRACKETCLOSE},
    {"'", APOSTROPHE},
    {"\"", QUOTATION},
    {"?", QUESTIONMARK},
    {",", COMMA},
    {":", COLON},
    {".", DOT},
    {"\\", BACKSLASH},
    {"//", DOUBLESLASH},
    {"#", HASHTAG}
};

class Token{
    public:
    std::string value;
    enum TokenType type;
    Token(std::string value = ";",enum TokenType type = END){
        this -> value = value;
        this -> type = type;
    }
};

bool isInt(std::string str){
    std::regex regex ("[-]?[0-9]+");
    return std::regex_match(str, regex);
}

bool isFloat(std::string str) {
    std::regex regex ("[-]?([0-9]+\\.[0-9]+|\\.[0-9]+)");
    return std::regex_match(str, regex);
}

bool isIdentifier(std::string str) {
    std::regex regex ("[_a-zA-Z][_a-zA-Z0-9]*");
    return std::regex_match(str, regex);
}


void split(std::string str, std::vector<std::string> &arr, char symbol = ' ') {
    size_t start = 0, end = str.find(symbol);//int with different name
    while (end != std::string::npos) {
        if(start != end)
        arr.push_back(str.substr(start, end - start));
        start = end + 1;
        end = str.find(symbol, start);
    }
    if(str.substr(start) != " " && str.substr(start) != "")
    arr.push_back(str.substr(start)); // Add the last word
}

bool isPartOfElement(std::string str, std::vector<std::string> arr){
    return true;
}

bool splitChunks(std::string str, std::vector<std::string> &arr, int i) {
    //std::cout << i<<"\n";
    //if(i>10) return false;
    std::array<std::string, 34> symbols = {"==","!=","<=",">=","&&","||","+=","-=","*=","/=","//","=","+","*","/","!","-","<",">","%","(",")","[","]","{","}","'","\"","?",",",":",".","\\","#"};
    size_t start, end;
    bool change = false;
    std::vector<std::string> ignore;
    for (std::string& s : symbols) {
        start = 0;
        end = str.find(s);
        if(change){
            break;
        }
        while (end < std::string::npos) {
            if(start != end){
                splitChunks(str.substr(start, end - start), arr, i+1);
                arr.push_back(str.substr(end - start, s.length()));
                change = true;
            }
            start = end + (s.length()>0 ? s.length() : 1);
            end = str.find(s, start);
            splitChunks(str.substr(start), arr, i+1);
            break;
        }
    }
    if(!change){
        arr.push_back(str);
    }
    return change;
}

void replace(std::string &str, std::string from, std::string to) {
    str = std::regex_replace(str, std::regex(from), to);
}

void makeToken(std::string &str, std::vector<Token> &tokens){  
}

void tokenize(std::vector<std::string> arr, std::vector<Token> &tokens){
    for (std::string str : arr) {
        if(str.length()<=2){
            tokens.push_back(Token(str,map[str]));
        } else if(isIdentifier(str)){
            continue;
        } else if(isInt(str)){
            continue;
        } else if(isFloat(str)){
            continue;
        }
    }
    //tokens.push_back(Token());
}

void parse(std::string &str, std::vector<Token> &tokens){
    std::vector<std::string> words;
    replace(str, "\n", " ");
    split(str, words);
    std::vector<std::string> arr;
    for (std::string w : words) {
        //std::cout <<"words: |" << w <<"|" << std::endl;
        if(!splitChunks(w, arr, 0)){
            arr.push_back(w);
            std::cout << "add: " << w << "\n";
        }
        arr.push_back(";");
    }
    //arr.push_back("");
    tokenize(arr, tokens);
    //std::cout << "arr:\n";
    for (std::string w : arr) {//debug
        std::cout <<"arr: |" << w <<"|" << std::endl;
    }
    
}            //tokens.push_back("END");

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
    std::vector<Token> tokens;
    split(content, statements, ';');
    
    for (std::string& w : statements) {//debug
        parse(w, tokens);
        //std::cout << " statement: "<< w << std::endl;
    }
    for (Token& w : tokens) {
        std::cout << " token: "<< w.type << " value: " << w.value << std::endl;
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

