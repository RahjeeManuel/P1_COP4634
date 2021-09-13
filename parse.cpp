//implements the command line parser of the shell
#include "parse.hpp"
Parse::Parse() {
}
char** Parse::tokenize(char* input) {
    char** args;
    int i = 0;
    char* token = strtok(input, " ");
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    return args;
}