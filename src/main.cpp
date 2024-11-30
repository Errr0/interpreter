#include "include.cpp"
#include "tokenizer.cpp"

int main(int argc, char* argv[]){
    if(argc<2) {
        std::cerr << "Error no path argument!" << std::endl;
        return 1;
    }
    std::string code;
    if(!readfile(argv[1], code)) return 2;
    std::vector<Token> tokens;
    parse(code,tokens);
    for (Token& token : tokens){
        std::cout << display(token.type) << (token.value == "" ? "" : "=") << token.value <<", ";
    }
    return 0;
}

