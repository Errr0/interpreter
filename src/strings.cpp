#include "include.cpp"

void split(std::string str, std::vector<std::string> &arr, std::string symbol = " ", bool include = false, bool separate = false) {
    size_t start = 0, end = str.find(symbol);//int with different name
    while (end != std::string::npos) {
        if(start != end){
        arr.push_back(str.substr(start, (include ? (separate ? end - start : end - start + symbol.length()) : end - start)));
        if(separate) arr.push_back(str.substr(end - start, symbol.length()));
        //if(include)arr.push_back(str.substr());
        }
        start = end + (include ? symbol.length() : 1);
        end = str.find(symbol, start);
    }
    if(str.substr(start) != " " && str.substr(start) != "")
    arr.push_back(str.substr(start)); // Add the last word
}

int numberOfOcurrences(std::string str, std::string substr){
    int count = 0;
    size_t start = 0, end = str.find(substr);
    while (end != std::string::npos) {
        count++;
        start = end + 1;
        end = str.find(substr, start);
    }
    return count;
}

std::string merge(std::vector<std::string> &arr){
    std::string str = "";
    for (std::string& s : arr) {
        str+=" "+s;
    }
    return str;
}

void replace(std::string &str, std::string from, std::string to) {
    str = std::regex_replace(str, std::regex(from), to);
}