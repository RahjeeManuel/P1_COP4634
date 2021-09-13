#include "parse.hpp"
Parse::Parse(char input[]) {
    char* token = strtok(input, " \t\n");
    while (token != NULL) {
        argumentArray.push_back(token);
        token = strtok(NULL, " \t\n");
    }
}
vector<char*> Parse::getArgumentArray() {
    return argumentArray;
}