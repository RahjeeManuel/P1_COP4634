#include "myshell.hpp"
#include<sys/wait.h>
#include<unistd.h>
#include<iostream>


void Myshell::execute(Param params) {//creates children

     char* arg_list[32];//max 32
     int status;//keeps track of children
     int cpid = fork();

     if(cpid == 0){
         for(int i = 0; i < (int)params.getArgumentVector().size(); i++){
            // arg_list[i] = params.getArgumentVector().at(i);
            if(params.getArgumentVector().at(i) != "&")
            arg_list[i] = strdup(params.getArgumentVector().at(i).c_str());
        }
        arg_list[params.getArgumentVector().size()] = NULL;

        execvp(arg_list[0], arg_list);
     }
    
    children.push_back(cpid);
 
    if(params.getBackground() == 0){//if background exists
        waitpid(cpid, &status, 0);
    }
    if(params.getBackground() == 1){
        children.push_back(cpid);
       // waitpid(cpid, &status, 0);
    }
}
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
            Param params(Parse::tokenize(input));
            execute(params);
                /*if(params.getBackground == 0){
                    fork(); //pid

                }*/
            if (debug) {
                std::cout << std::endl;
                params.printParams();
            }
        } else {
            int status;
            for(int i = 0; i < (int)children.size(); i++){
                if(waitpid(children.at(i), &status, 0) == -1){ //-1 or null == still running process
                    if(WIFEXITED(status) == 0) //child exited normaly
                        break;
                }
            }
            break;
        }
    } while (true);
}
int main(int argc, char* argv[]) {
    Myshell s;
    s.start(argc >=2 ? (!strcmp(argv[1], "-Debug")) : false);
    return 0;
}