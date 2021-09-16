#include "myshell.hpp"
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

           this->parser.tokenize(&input[0]);
           this->params.loadArr(parser.getArgumentArray());  //this->params(parser.getArgumentArray()); 

            execute(params.getArgumentVector(), params.getArgumentCount());
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
void Myshell::execute(char* argumentVector, int argumentCount){//takes a ptr to a char arr
        //char* arg_list[]={command,arguments,background};
   
    char* arg_list[argumentCount];
    for(int i = 0 ;i < argumentCount; i++){ 
        arg_list[i] = argumentVector[i];
    }
    /*if(argumentCount == 2)
        arg_list = {argumentVector, argumentVector[1]};
    else if(argumentCount == 3)
        arg_list = {argumentVector, argumentVector[1],argumentVector[2]};
    else if(argumentCount == 4)
        arg_list = {argumentVector, argumentVector[1],argumentVector[2],argumentVector[3]};
*/
        
    execvp(argumentVector, arg_list);
    
    cout << "executed function worked";
        
}