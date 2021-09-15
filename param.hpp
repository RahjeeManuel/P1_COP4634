#ifndef PARAM_HPP
#define PARAM_HPP
#define MAXARGS 32
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
class Param
{
    private:
        char* inputRedirect;
        char* outputRedirect;
        int background;
        int argumentCount;
        char* argumentVector[MAXARGS];
    public:
        Param(vector<char*> arguments);
        void printParams();
        void getArgumentVector();
};
#endif