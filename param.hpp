#ifndef PARAM_HPP
#define PARAM_HPP
#define MAXARGS 32
#include"parse.hpp"
#include <iostream>
class Param
{
    private:
        char *inputRedirect;            /* file name or NULL */ // arr
        char *outputRedirect;           /* file name or NULL */
        int background;                 /* either 0 (false) or 1 (true) */
        int argumentCount;              /* number of tokens in argument vector */
        char *argumentVector[MAXARGS];  /* array of strings */
    public:
        void printParams();
        Param();
        ~Param();
        void setBackground(bool num);
        int getBackground();
        void setArgumentCount(int argumentCount);
        int getArgumentCount();

};
#endif