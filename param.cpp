//class to hold parsed input data
#include "param.hpp"
Param::Param(char* arguments[], int numArgs) { 
    //place arguments into params
    for (int i = 0; i < numArgs; i++) {
        argumentVector[i] = arguments[i];
    }
    argumentCount = numArgs;
    inputRedirect = argumentCount >= 3 ? argumentVector[3] + 1 : NULL;  //these will need error protection
    outputRedirect = argumentCount >= 4 ? argumentVector[4] + 1: NULL;  //can break easily
    background = argumentCount >= 5 ? strcmp(argumentVector[5], "&") == 0 ? 1 : 0 : 0;
}
void Param::printParams() {
    cout << "InputRedirect: [" << ((inputRedirect != NULL) ? inputRedirect : "NULL") << "]" << endl <<
        "OutputRedirect: [" << ((outputRedirect != NULL) ? outputRedirect : "NULL") << "]" << endl <<
        "Background: [" << background << "]" << endl <<
        "ArgumentCount: [" << argumentCount << "]" << endl;
    for (int i = 0; i < argumentCount; i++)
        cout << "ArgumentVector[" << i << "]: [" << argumentVector[i] << "]" << endl;
}