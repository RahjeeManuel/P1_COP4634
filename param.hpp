#ifndef PARAM_HPP
#define PARAM_HPP
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Param
{
    private:
        string inputRedirect;
        string outputRedirect;
        vector<string> argumentVector;
        int background;
    public:
        Param(vector<string> tokens);
        string getInputRedirect();
        string getOuputRedirect();
        vector<string> getArgumentVector();
        int getBackground();
        void printParams();
};
#endif