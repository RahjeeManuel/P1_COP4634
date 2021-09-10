#ifndef MYSHELL_HPP
#define MYSHELL_HPP
#include <iostream>
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