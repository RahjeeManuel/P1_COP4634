#include "param.hpp"
#include <string.h>
Param::Param(vector<string> tokens) {
    argumentVector = tokens;
    for (unsigned int i = 0; i < argumentVector.size(); i++) {
        if (argumentVector.at(i).find("<") == 0) {
            inputRedirect = argumentVector.at(i).substr(1);
            argumentVector.at(i) = inputRedirect;
        } else if (argumentVector.at(i).find(">") == 0) {
            outputRedirect = argumentVector.at(i).substr(1);
            argumentVector.at(i) = outputRedirect;
        }
    }
    background = argumentVector.back() == "&" ? 1 : 0;
}
string Param::getInputRedirect() {
    return inputRedirect;
}
string Param::getOuputRedirect() {
    return outputRedirect;
}
vector<string> Param::getArgumentVector() {
    return argumentVector;
}
char** Param::getExecArray() {
    //returns an array without outputredirect and &
    char** args;
    args = new char*[MAXARGS];
    int i = 0;
    for (string s : argumentVector) {
        if (s != outputRedirect) {
            if (s != "&") {
                args[i] = strdup(s.c_str());
                i++;
            }
        }
    }
    args[i] = NULL;
    return args;
}
int Param::getBackground() {
    return background;
}
void Param::printParams() {
    cout << "InputRedirect: [" << ((inputRedirect.size() != 0) ? inputRedirect : "NULL") << "]" << endl <<
    "OutputRedirect: [" << ((outputRedirect.size() != 0) ? outputRedirect : "NULL") << "]" << endl <<
    "Background: [" << background << "]" << endl <<
    "ArgumentCount: [" << argumentVector.size() << "]" << endl;
    for (unsigned int i = 0; i < argumentVector.size(); i++) {
        cout << "ArgumentVector[" << i << "]: [" << argumentVector[i] << "]" << endl;  
    }     
}