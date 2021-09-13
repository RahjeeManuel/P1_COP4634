#ifndef MYSHELL_HPP
#define MYSHELL_HPP
#include <iostream>
#include <string.h>
#include "parse.hpp"
#include "param.hpp"
using namespace std;
class Myshell
{
    private:
        string prompt;
        string exit;
    public:
        Myshell(string prompt = "$$$", string exit = "exit");
        void start(bool debug = false);
};
#endif