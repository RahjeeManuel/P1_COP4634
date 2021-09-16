#include "parse.hpp"

/*Parse::Parse(char input[]) {
    char* token = strtok(input, " \t\n");
    while (token != NULL) {
        argumentArray.push_back(token);
        token = strtok(NULL, " \t\n");
    }
}*/
void Parse::tokenize(char input[]){
    char* token = strtok(input, " \t\n");
    while (token != NULL) {
        argumentArray.push_back(token);
        token = strtok(NULL, " \t\n");
    }
}
vector<char*> Parse::getArgumentArray() {
    return argumentArray;
}
/*
void Parse::setInput(char* input){
    this->input = input;
}