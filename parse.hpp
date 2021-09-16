#ifndef PARSE_HPP
#define PARSE_HPP
#include <vector>
#include <string.h>
using namespace std;
class Parse
{
    private:
        vector<char*> argumentArray;
    public:
       // Parse(char input[])
        void tokenize(char input[]);
        vector<char*> getArgumentArray();
        //setInput(char* input);
};
#endif