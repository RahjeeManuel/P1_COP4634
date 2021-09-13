//implements the command line parser of the shell
#include "parse.hpp"
#include <iostream>
Parse::Parse(char input[]) {
    numArgs = 0;
    char* token = strtok(input, " ");
    while (token != NULL) {
        arguments[numArgs++] = token;
        token = strtok(NULL, " ");
    }
}
int Parse::getNumArgs() {
    return numArgs;
}
char** Parse::getArguments() {
    return arguments;
}