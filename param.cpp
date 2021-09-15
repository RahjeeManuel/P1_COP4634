#include "param.hpp"
Param::Param(vector<char*> arguments) {
    inputRedirect = NULL;
    outputRedirect = NULL;
    background = 0;
    argumentCount = arguments.size();
    for (int i = 0; i < argumentCount; i++) { //this can be refactored
        argumentVector[i] = arguments.at(i);
        if (strlen(argumentVector[i]) >= 2) {
            if (*argumentVector[i] == '<') {
                inputRedirect = argumentVector[i] + 1;
            } else if (*argumentVector[i] == '>') {
                outputRedirect = argumentVector[i] + 1;
            }
        } else if (strlen(argumentVector[i]) == 1) {
            if (*argumentVector[i] == '&') {
                background = 1;
            }
        }
    }
}

void Param::printParams() {
    cout << "InputRedirect: [" << ((inputRedirect != NULL) ? inputRedirect : "NULL") << "]" << endl <<
        "OutputRedirect: [" << ((outputRedirect != NULL) ? outputRedirect : "NULL") << "]" << endl <<
        "Background: [" << background << "]" << endl <<
        "ArgumentCount: [" << argumentCount << "]" << endl;
    for (int i = 0; i < argumentCount; i++)
        cout << "ArgumentVector[" << i << "]: [" << argumentVector[i] << "]" << endl;
}
void Param::getArgumentVector(){
    return this->argumentVector;
}
