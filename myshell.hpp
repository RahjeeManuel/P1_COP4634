#ifndef MYSHELL_HPP
#define MYSHELL_HPP
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include "parse.hpp"
#include "param.hpp"
using namespace std;
class Myshell
{
    private:
        string prompt;
        string exit;
        string readFile(string fileName);
        void writeFile(string fileName, string input);
        void execute(Param params);
    public:
        Myshell(string prompt = "$$$", string exit = "exit");
        void start(bool debug = false);
};
#endif