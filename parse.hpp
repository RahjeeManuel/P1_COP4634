//defines the functionality you want to expose
#ifndef PARSE_HPP
#define PARSE_HPP
#include <string.h>
using namespace std;
class Parse {
    private:
        int numArgs;
        char* arguments[];
    public:
        Parse(char input[]);
        int getNumArgs();
        char** getArguments();
};
#endif
