//implements the shell .
#include "myshell.hpp"
Myshell::Myshell(string prompt, string exit) {
    this->prompt = prompt;
    this->exit = exit;
}
void Myshell::start(bool debug) {
    Parse parser;
    Param params;
    string input;
    do {
        cout << prompt << " ";
        getline(cin, input);
        if (input != exit) {
            params.fillParams(parser.tokenize(&input[0]));
            if (debug) {
                params.printParams();
            }            
        } else {
            break;
        }
    } while (true);
}