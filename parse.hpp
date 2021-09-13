//defines the functionality you want to expose
#ifndef PARSE_HPP
#define PARSE_HPP
#include <string.h>
using namespace std;
class Parse {
    public:
        Parse();
        char** tokenize(char* input);
};
#endif
