//implements the shell
#include "myshell.hpp"

using namespace std;

Myshell::Myshell(string prompt, string exit) {
    this->prompt = prompt;
    this->exit = exit;
}
void Myshell::start(bool debug) {
    string input; //i/p from user
    //Parse p(input);
    do {
        cout << prompt << " ";
        getline(cin, input);
        if (input != this->exit) {
            //parse
            //store into param
            //execute
            if (debug) {
                //print param
            }            
        } else {
            break;
        }
    } while (true);
}
