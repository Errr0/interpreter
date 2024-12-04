#include "include.cpp"
#include "tokenizer.cpp"

int main(int argc, char* argv[]){
    if(argc<2) {
        std::cerr << "Error no path argument!" << std::endl;
        return 1;
    }
    std::string code;
    if(!readfile(argv[1], code)) return 2;
    std::vector<std::vector<Token>> tokens;
    parse(code,tokens);
    std::cout<<"tokens:\n";
    for (std::vector<Token> stokens : tokens){std::cout<< "|";
        for (Token token : stokens){
            if(token.type == IDENTIFIER || token.type == NUMBER || token.type == INT || token.type == FLOAT || token.type == KEYWORD || token.type == DATATYPE || token.type == SCOPE){
                std::cout <<token.value << "("<< display(token.type) <<")";
            } else{
                std::cout << display(token.type);
            }
        }
    std::cout<< "|\n";
    }
    //interpret
    return 0;
}

