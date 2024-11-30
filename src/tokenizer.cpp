#include "include.cpp"
#include "checks.cpp"
#include "strings.cpp"

enum TokenType {
    END,
    ASSIGN,
    PLUS,
    MINUS,
    ASTERISK,
    SLASH,
    MODULO,
    MULTIPLY,
    DIVIDE,
    INCREMENT,   // ++
    DECREMENT,   // --
    ADDASSIGN,  // +=
    SUBASSIGN,  // -=
    MULASSIGN,  // *=
    DIVASSIGN,  // /=
    MODASSIGN,  // %=
    NOT,
    AND,
    OR,
    EQUAL,
    NOTEQUAL,
    LESSTHAN,
    LESSEQUAL,
    GREATERTHAN,
    GREATEREQUAL,
    NUMBER,
    IDENTIFIER,
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

std::string display(TokenType token) {
    switch (token) {
        case END: return "END";
        case ASSIGN: return "ASSIGN";
        case PLUS: return "PLUS";
        case MINUS: return "MINUS";
        case ASTERISK: return "ASTERISK";
        case SLASH: return "SLASH";
        case MODULO: return "MODULO";
        case MULTIPLY: return "MULTIPLY";
        case DIVIDE: return "DIVIDE";
        case INCREMENT: return "INCREMENT";
        case DECREMENT: return "DECREMENT";
        case ADDASSIGN: return "ADDASSIGN";
        case SUBASSIGN: return "SUBASSIGN";
        case MULASSIGN: return "MULASSIGN";
        case DIVASSIGN: return "DIVASSIGN";
        case MODASSIGN: return "MODASSIGN";
        case NOT: return "NOT";
        case AND: return "AND";
        case OR: return "OR";
        case EQUAL: return "EQUAL";
        case NOTEQUAL: return "NOTEQUAL";
        case LESSTHAN: return "LESSTHAN";
        case LESSEQUAL: return "LESSEQUAL";
        case GREATERTHAN: return "GREATERTHAN";
        case GREATEREQUAL: return "GREATEREQUAL";
        case NUMBER: return "NUMBER";
        case IDENTIFIER: return "IDENTIFIER";
        case BRACKETOPEN: return "BRACKETOPEN";
        case BRACKETCLOSE: return "BRACKETCLOSE";
        case SQUAREBRACKETOPEN: return "SQUAREBRACKETOPEN";
        case SQUAREBRACKETCLOSE: return "SQUAREBRACKETCLOSE";
        case CURLYBRACKETOPEN: return "CURLYBRACKETOPEN";
        case CURLYBRACKETCLOSE: return "CURLYBRACKETCLOSE";
        case APOSTROPHE: return "APOSTROPHE";
        case QUOTATION: return "QUOTATION";
        case QUESTIONMARK: return "QUESTIONMARK";
        case COMMA: return "COMMA";
        case COLON: return "COLON";
        case DOT: return "DOT";
        case BACKSLASH: return "BACKSLASH";
        case DOUBLESLASH: return "DOUBLESLASH";
        case HASHTAG: return "HASHTAG";
        default: return "UNKNOWN";
    }
}
/*
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
};*/

std::map<std::string, TokenType> locked = {
    {"~END", END},
    {"~ASSIGN", ASSIGN},
    {"~PLUS", PLUS},
    {"~MINUS", MINUS},
    {"~ASTERISK", ASTERISK},
    {"~SLASH", SLASH},
    {"~MODULO", MODULO},
    {"~ADDASSIGN", ADDASSIGN},
    {"~SUBASSIGN", SUBASSIGN},
    {"~MULTIPLY", MULTIPLY},
    {"~DIVIDE", DIVIDE},
    {"~NOT", NOT},
    {"~AND", AND},
    {"~OR", OR},
    {"~EQUAL", EQUAL},
    {"~NOTEQUAL", NOTEQUAL},
    {"~LESSTHAN", LESSTHAN},
    {"~LESSEQUAL", LESSEQUAL},
    {"~GREATERTHAN", GREATERTHAN},
    {"~GREATEREQUAL", GREATEREQUAL},
    {"~BRACKETOPEN", BRACKETOPEN},
    {"~BRACKETCLOSE", BRACKETCLOSE},
    {"~SQUAREBRACKETOPEN", SQUAREBRACKETOPEN},
    {"~SQUAREBRACKETCLOSE", SQUAREBRACKETCLOSE},
    {"~CURLYBRACKETOPEN", CURLYBRACKETOPEN},
    {"~CURLYBRACKETCLOSE", CURLYBRACKETCLOSE},
    {"~APOSTROPHE", APOSTROPHE},
    {"~QUOTATION", QUOTATION},
    {"~QUESTIONMARK", QUESTIONMARK},
    {"~COMMA", COMMA},
    {"~COLON", COLON},
    {"~DOT", DOT},
    {"~BACKSLASH", BACKSLASH},
    {"~DOUBLESLASH", DOUBLESLASH},
    {"~HASHTAG", HASHTAG}
};

std::array<std::string, 34> symbols = {
    "==",
    "!=",
    "<=",
    ">=",
    "&&",
    "||",
    "+=",
    "-=",
    "*=",
    "/=",
    "//",
    "=",
    "+",
    "*",
    "/",
    "!",
    "-",
    "<",
    ">",
    "%",
    "(",
    ")",
    "[",
    "]",
    "{",
    "}",
    "'",
    "\"",
    "?",
    ",",
    ":",
    ".",
    "\\",
    "#"};

class Token{
    public:
    std::string value;
    enum TokenType type;
    Token(std::string value = "",enum TokenType type = END){
        this -> value = value;
        this -> type = type;
    }
};

void tokenize(std::vector<std::string> arr, std::vector<Token> &tokens){
    for (std::string str : arr) {
        if(str[0]=='~'){
            tokens.push_back(Token("",locked[str]));
        } else if(isNumber(str)){
            tokens.push_back(Token(str,NUMBER));
        } else if(isIdentifier(str)){
            tokens.push_back(Token(str,IDENTIFIER));
        } else{
            //std::cout <<" |no valid token: "<< str <<"| ";
        }
    }
}

void deconstructStatement(std::string &str, std::vector<Token> &arr){
    std::vector<std::string> words;
    split(str,words);
    for (std::string& symbol : symbols) {
        std::vector<std::string> temp;
        for (std::string& substr : words) {
            if(substr.find(symbol) != std::string::npos){
                split(substr, temp, symbol, true, true, true);
            } else {
                temp.push_back(substr); // Keep unchanged if no symbol found
            }
        }
        words = std::move(temp); // Replace help with the updated vector
    }
    tokenize(words, arr);
}

void parse(std::string &str, std::vector<Token> &tokens){
    std::vector<std::string> statements;
    replace(str, "\n", " ");
    split(str, statements, ";", true, true, true);
    for (std::string& statement : statements) {
        std::vector<std::string> splittedStatement;
        split(statement,splittedStatement);
        deconstructStatement(statement, tokens);
    }
}

bool readfile(std::string filename, std::string &str){
    std::fstream file(filename, std::ios::in);
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return 0;
    }
    std::ostringstream buffer;
    buffer << file.rdbuf();
    str = buffer.str();
    file.close();
    return 1;
}
