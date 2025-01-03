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
    INT,
    FLOAT,
    IDENTIFIER,
    KEYWORD,
    DATATYPE,
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
    HASHTAG,
    SPACE,
    SCOPE,
    BRACKETS
};

std::string displayTokenType(TokenType token) {
    switch (token) {
        case END: return "END";
        case ASSIGN: return "ASSIGN";
        case PLUS: return "PLUS";
        case MINUS: return "MINUS";
        case ASTERISK: return "ASTERISK";
        case SLASH: return "SLASH";
        case MODULO: return "MODULO";
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
        case SPACE: return "SPACE";
        default: return "UNKNOWN";
    }
}

std::string display(TokenType token) {
    switch (token) {
        case END: return ";";
        case ASSIGN: return "=";
        case PLUS: return "+";
        case MINUS: return "-";
        case ASTERISK: return "*";
        case SLASH: return "/";
        case MODULO: return "%";
        case INCREMENT: return "++";
        case DECREMENT: return "--";
        case ADDASSIGN: return "+=";
        case SUBASSIGN: return "-=";
        case MULASSIGN: return "*=";
        case DIVASSIGN: return "/=";
        case MODASSIGN: return "%=";
        case NOT: return "!";
        case AND: return "&&";
        case OR: return "||";
        case EQUAL: return "==";
        case NOTEQUAL: return "!=";
        case LESSTHAN: return "<";
        case LESSEQUAL: return "<=";
        case GREATERTHAN: return ">";
        case GREATEREQUAL: return ">=";
        //case NUMBER: return "n";
        case IDENTIFIER: return "id";
        case INT: return "i";
        case FLOAT: return "f";
        case KEYWORD: return "kw";
        case DATATYPE: return "dt";
        case BRACKETOPEN: return "(";
        case BRACKETCLOSE: return ")";
        case SQUAREBRACKETOPEN: return "[";
        case SQUAREBRACKETCLOSE: return "]";
        case CURLYBRACKETOPEN: return "{";
        case CURLYBRACKETCLOSE: return "}";
        case APOSTROPHE: return "'";
        case QUOTATION: return "\"";
        case QUESTIONMARK: return "?";
        case COMMA: return ",";
        case COLON: return ":";
        case DOT: return ".";
        case BACKSLASH: return "\\";
        case DOUBLESLASH: return "//";
        case HASHTAG: return "#";
        case SPACE: return " ";
        case SCOPE: return "SCOPE";
        case BRACKETS: return "BRACKETS";
        default: return "UNKNOWN";
    }
}


std::map<std::string, TokenType> locked = {
    {"~END", END},
    {"~ASSIGN", ASSIGN},
    {"~PLUS", PLUS},
    {"~MINUS", MINUS},
    {"~ASTERISK", ASTERISK},
    {"~SLASH", SLASH},
    {"~MODULO", MODULO},
    {"~INCREMENT", INCREMENT},
    {"~DECREMENT", DECREMENT},
    {"~ADDASSIGN", ADDASSIGN},
    {"~SUBASSIGN", SUBASSIGN},
    {"~MULASSIGN", MULASSIGN},
    {"~DIVASSIGN", DIVASSIGN},
    {"~MODASSIGN", MODASSIGN},
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
    {"~HASHTAG", HASHTAG},
    {"~SPACE", SPACE}
};

std::array<std::string, 39> symbols = {
    "==",
    "!=",
    "<=",
    ">=",
    "&&",
    "||",
    "++",
    "--",
    "+=",
    "-=",
    "*=",
    "/=",
    "%=",
    "//",
    ";",
    " ",
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
    std::string target;
    enum TokenType type;
    Token(std::string value = ";",enum TokenType type = END, std::string targert = ""){
        this -> value = value;
        this -> type = type;
        this -> target = target;
    }
};

void print(std::vector<std::vector<Token>> &tokens){
    std::cout << "|SCOPES = "<< tokens.size() <<"|\n";
    for(std::vector<Token> s : tokens){
    std::cout << "|SCOPE|";
        for(Token token : s){
            
            if(token.type == SCOPE || token.type == BRACKETS){
                std::cout <<" "<<token.value << "-"<< display(token.type) <<" ";
            }else
            if(token.type == IDENTIFIER || token.type == NUMBER || token.type == INT || token.type == FLOAT || token.type == KEYWORD || token.type == DATATYPE){
                std::cout <<token.value;
            } else{
                std::cout << display(token.type);
            }
        }
        std::cout << "|\n";
        }
}

void addSpaceToken(std::vector<Token> &tokens){
    if(!tokens.empty()){
        if(tokens.back().type == SPACE){
            return;
        }
    }
    tokens.push_back(Token("",SPACE));
}

void addNumberToken(std::string str, std::vector<Token> &tokens){
    if(tokens.size()>=2){
        if(tokens[tokens.size() - 1].type == DOT && (tokens[tokens.size() - 2].type == NUMBER || tokens[tokens.size() - 2].type == INT)){
            tokens.pop_back();
            std::string temp = tokens.back().value;
            tokens.pop_back();
            if(!tokens.empty()){
                if(tokens.back().type == MINUS){
                    tokens.pop_back();
                    tokens.push_back(Token("-"+temp+"."+str,FLOAT));
            return;
                }
            }
            tokens.push_back(Token(temp+"."+str,FLOAT));
            return;
        }
    }
    if(tokens.back().type == MINUS){
        tokens.pop_back();
        tokens.push_back(Token("-"+str,INT));
    }
    tokens.push_back(Token(str,INT));
}

void addKeyword(std::string str, std::vector<Token> &tokens){
    if(dataTypes.find(str) != dataTypes.end()){
        tokens.push_back(Token(str,DATATYPE));
    } else {
        tokens.push_back(Token(str,KEYWORD));
    }
}

long long unsigned int scope = 0;
long long unsigned int bracket = 0;
std::stack<Token> unclosedScopes;
std::stack<Token> unclosedBrackets;


void tokenize(std::vector<std::string> arr, std::vector<std::vector<Token>> &tokens){
    //std::vector<Token> tokens;
    std::vector<std::vector<Token>> scopes;
    scopes.push_back(std::vector<Token>());
    for (long long unsigned int i = 0; i<arr.size(); i++) {
        if(scope+bracket>0){std::cout<<scope+bracket<<" SCOPES\n";}
        if(scope+bracket<0){std::cout<<scope+bracket<<" NEGATIVE SCOPE\n";}else
        if(arr[i][0]=='~'){
            if(arr[i]=="~END" && scopes[scope+bracket].back().type != END){
                scopes[scope+bracket].push_back(Token());
            } else if(arr[i]=="~SPACE"){
                addSpaceToken(scopes[scope+bracket]);
            } else if(arr[i]=="~BRACKETOPEN"){
                //std::cout <<i<<"."<< scopes.size()<<" "<<arr[i]<<" "<<scope<<"."<<unclosedScopes.size()<<" "<<bracket<<"."<<unclosedBrackets.size()<<"\n";
                std::cout <<"adding bracket: "<<scope+bracket;
                scopes[scope+bracket].push_back(Token(std::to_string(tokens.size()+scopes.size()),BRACKETS));
                unclosedBrackets.push(scopes[scope+bracket].back());
                bracket++;
                if(scope+bracket>=scopes.size()){
                    std::cout <<"adding bracket: "<<scope+bracket;
                    scopes.push_back(std::vector<Token>());
                }
            } else if(arr[i]=="~CURLYBRACKETOPEN"){
                scopes[scope+bracket].push_back(Token(std::to_string(tokens.size()+scopes.size()),SCOPE));
                unclosedScopes.push(scopes[scope+bracket].back());
                scope++;
                if(scope+bracket>=scopes.size()){
                    scopes.push_back(std::vector<Token>());
                }
                
            } else if(arr[i]=="~BRACKETCLOSE"){
                scopes[scope+bracket].push_back(Token(unclosedBrackets.top().value,BRACKETS));
                unclosedBrackets.pop();
                bracket--;
            } else if(arr[i]=="~CURLYBRACKETCLOSE"){
                scopes[scope+bracket].push_back(Token(unclosedScopes.top().value,SCOPE));
                unclosedScopes.pop();
                scope--;
            } else{
                scopes[scope+bracket].push_back(Token("",locked[arr[i]]));
            }
        } else if(isNumber(arr[i])){
            addNumberToken(arr[i], scopes[scope+bracket]);
        } else if(isIdentifier(arr[i])){
            if(isKeyword(arr[i])){
                addKeyword(arr[i], scopes[scope+bracket]);
            } else {
                scopes[scope+bracket].push_back(Token(arr[i],IDENTIFIER));
            }
        } else{
            //std::cout <<" |no valid token: "<< arr[i] <<"| ";
        }
        std::cout <<i<<"."<< scopes.size()<<" "<<arr[i]<<" "<<scope<<"."<<unclosedScopes.size()<<" "<<bracket<<"."<<unclosedBrackets.size()<<"\n";
    }
    //std::cout<<"`"<<scopes.size()<<"`";
    //for(std::vector<Token> s : scopes){
        //std::cout<<"``"<<s.size()<<"``";
        //for(Token t : s){
        //    std::cout<<display(t.type)<<"";
        //}
    //}
    if(scopes.size()==1 && scopes[0].empty())return;
    tokens.insert(tokens.end(), scopes.begin(), scopes.end());
    print(tokens);
    
}

void deconstructStatement(std::string &str, std::vector<std::vector<Token>> &arr){
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



void parse(std::string &str, std::vector<std::vector<Token>> &tokens){
    std::vector<std::string> statements;
    replace(str, "\n", " ");
    split(str, statements, ";", false, false, false);
    for (std::string& statement : statements) {
        //std::vector<Token> statementTokens;
        deconstructStatement(statement, tokens);
        //print(tokens);
    }
    std::cout<<"\nDONE!\n";
    //print(tokens);
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
