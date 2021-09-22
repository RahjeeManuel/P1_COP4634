#include "myshell.hpp"
void Myshell::execute(Param params) {
    int status;
    int pid = fork();
    char** args = params.getExecArray();

    //begin execvp(3) in the child
    if (pid == 0) {
        //redirect output if an outputredirect exists
        if (params.getOuputRedirect().size() != 0) {  
            freopen(strdup(params.getOuputRedirect().c_str()), "w", stdout);
        }
        execvp(args[0], args);
    }

    //wait for the child if background == 0, otherwise do not wait and add the child to pid vector
    if (params.getBackground() == 0) {  
        waitpid(pid, &status, 0);
    } else {
        cpids.push_back(pid);
    }
    delete[] args;
}
Myshell::waitForChildren() {
    //wait for all children in pid list to finish
    for (unsigned int i = 0; i < cpids.size(); ++i) {
        int status;
        while (waitpid(cpids[i], &status, 0) == -1);    
        if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) {
            break;
        }
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
            //tokenize input then send the params to execute
            Param params(Parse::tokenize(input));
            execute(params);
            
            if (debug) {
                params.printParams();
            }
        } else {
            waitForChildren()
            break;
        }
    } while (true);
}
int main(int argc, char* argv[]) {
    Myshell s;
    s.start(argc >=2 ? (!strcmp(argv[1], "-Debug")) : false);
    return 0;
}