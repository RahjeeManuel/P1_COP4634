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
        //Param(vector<char*> arguments);
        void loadArr(vector<char*> arguments);
        void printParams();
        char* getArgumentVector();
        int getArgumentCount();
};
#endif