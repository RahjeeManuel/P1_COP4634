#include "myshell.hpp"
#include<process.h>
#include <stddef.h>
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
            Param params(parser.getArgumentArray()); //this can be moved
            execute(params.getArgumentVector());
            //commands will be executed here
            
            if (debug) {
                params.printParams();
            }
        } else {
            break;
        }
    } while (true);
}
int main(int argc, char* argv[]) {
    Myshell s;
    s.start(argc >=2 ? (strcmp(argv[1], "-Debug") == 0) : false);

    return 0;
}
void myshell::execute(char* argumentVector){//takes a ptr to a char arr

    //command first elmnt, arguments rest, background last

    char* arg_list[]={argumentVector[0],/*arguments*/};



}