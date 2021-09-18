#include "parse.hpp"
vector<string> Parse::tokenize(string input) {
    vector<string> tokens;
    stringstream ss(input); 
    string token;
    while(getline(ss, token, ' ')) {
        tokens.push_back(token);
    }
    return tokens;
}