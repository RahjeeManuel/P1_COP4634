#include"myshell.hpp"
#include"param.hpp"
#include"parse.hpp"
#include<iostream>

int main(int argc, char* argv[]) {
    Myshell s();

    s.start(false);
    return 0;
}