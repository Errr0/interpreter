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
    ADD,
    SUBTRACT,
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

std::array<std::string, 33> symbols = {
    "==",
    "!=",
    "<=",
    ">=",
    "&&"
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
    Token(std::string value = ";",enum TokenType type = END){
        this -> value = value;
        this -> type = type;
    }
};

bool splitChunks(std::string str, std::vector<std::string> &arr, int i) {
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
    if(!change && str != " " && str != ""){
        arr.push_back(str);
    }
    return change;
}

void deconstructStatement(std::string &str, std::vector<std::string> &arr){
    //arr.push_back(str);
    //bool change = false;
    std::vector<std::string> words;
    words.push_back(str);
    //arr.push_back(str);
    for (std::string& symbol : symbols) {
        std::vector<std::string> temp;
        //std::cout<<symbol<<"\n";
        for (std::string& substr : words) {
            if(str.find(symbol) != std::string::npos){
                split(substr, temp, symbol, true, true);
            } else {
                temp.push_back(substr); // Keep unchanged if no symbol found
            }
        }
        words = std::move(temp); // Replace help with the updated vector
    }
    std::cout<<"done\n";
    arr.insert(arr.end(), words.begin(), words.end());
    for (std::string& substr : arr) {
        std::cout <<""<< substr <<"";
    }
}

void tokenize(std::vector<std::string> arr, std::vector<Token> &tokens){
    for (std::string str : arr) {
        if(isIdentifier(str)){
            tokens.push_back(Token(str,IDENTIFIER));
        } else if(isInt(str)){
            tokens.push_back(Token(str,NUMBER));
        } else if(str.length()<=2){
            tokens.push_back(Token(str,map[str]));
        } else{
            std::cout <<" |no valid token: "<< str <<"| ";
        }
    }
}

void parse(std::string &str){
    std::vector<std::string> statements;
    std::vector<std::string> words;
    replace(str, "\n", " ");
    split(str, statements, ";", true);
    std::cout << "str:" << str << std::endl;
    //std::vector<Token> tokens;
    std::cout << "statements:\n";
    for (std::string& statement : statements) {
        deconstructStatement(statement, words);
        std::cout << "|" << statement << "|" << std::endl;
    }
    std::cout << "words:\n";
    for (std::string& word : words) {
        std::cout << "" << word << "";
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
