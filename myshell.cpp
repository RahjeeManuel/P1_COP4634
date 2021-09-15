//implements the shell .
#include "myshell.hpp"
using namespace std;

Myshell::Myshell(string prompt, string exit) {
    this->prompt = prompt;
    this->exit = exit;
}
void Myshell::start(bool debug) {
    string input;
    do {
        cout << prompt << " ";
        getline(cin, input);
        if (input != exit) {
            Parse parser(&input[0]);
            Param params(parser.getArguments(), parser.getNumArgs());
            
            if (debug) {
                params.printParams();
            }            
        } else {
            break;
        }
    } while (true);
}
int main(int argc, char** argv) {
    Myshell shell;
    shell.start(strcmp("-Debug", (argv[1] != NULL ? "-Debug" : "")) == 0);
    
    return 0;
}