#include "myshell.hpp"
void Myshell::execute(Param params) {
    int status;
    int pid = fork();
    char** args = params.getExecArray();
    if (pid == 0) {
        if (params.getOuputRedirect().size() != 0) {    //redirect output if a output redirect exists
            freopen(strdup(params.getOuputRedirect().c_str()), "w", stdout);
        }
        execvp(args[0], args);
    }
    if (params.getBackground() == 0) {  //wait for child if background == 0
        waitpid(pid, &status, 0);
    } else {
        cpids.push_back(pid);   //add to the list if the child will run in background
    }
    delete[] args;
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
            if (debug) {
                params.printParams();
            }
        } else {
            for (unsigned int i = 0; i < cpids.size(); ++i) {
                int status;
                while (waitpid(cpids[i], &status, 0) == -1);    //wait for child to finish
                if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) {   //break if child is finished
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