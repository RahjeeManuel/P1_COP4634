//implements the command line parser of the shell
#include"parse.hpp"
#include<iostream>
#include<sstream>
#include<stdio.h>
#include<string.h>


using namespace std;

//string line stored in char array on myshell
Parse::Parse(char *strArray){
    char *p;
    p = strtok(strArray, "%s%t\n");
}