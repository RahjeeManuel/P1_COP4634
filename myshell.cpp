//implements the shell
#include "myshell.hpp"
Myshell::Myshell(string prompt, string exit) {
    this->prompt = prompt;
    this->exit = exit;
}
void Myshell::start(bool debug) {
    string input; //i/p from user
    do {
        cout << prompt << " ";
        getline(cin, input);
        if (input != exit) {
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
int main(int argc, char* argv[]) {
    Myshell s;
    s.start(false);
    return 0;
}