#include "myshell.hpp"
#include <string>
int main(int argc, char** argv) {
    Myshell shell;
    string debug(argv[1]);
    shell.start(debug == "-Debug");
    
    return 0;
}