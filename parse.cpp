//implements the command line parser of the shell
#include"parse.hpp"
#include<sstream>
#include<stdio.h>
#include<string.h>
#include<string>

Parse::Parse(std::string inputstr){
    this->inputstr = inputstr; 
    this->str[] = inputstr; //store input string into char array
}
void Parse::tokenizer(){
    this->ptr = strtok(this->strArray, "%s%t\n"); 
}
void Parse::loadVector(){ //load argument vector argument vector

}