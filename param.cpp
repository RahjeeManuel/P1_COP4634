//class to hold parsed input data
#include "param.hpp"
using namespace std;
Param::Param() { 
}
void Param::printParams() {
    cout << "InputRedirect: [" << ((inputRedirect != NULL) ? inputRedirect : "NULL") << "]" << endl <<
        "OutputRedirect: [" << ((outputRedirect != NULL) ? outputRedirect : "NULL") << "]" << endl <<
        "Background: [" << background << "]" << endl <<
        "ArgumentCount: [" << argumentCount << "]" << endl;
    for (int i = 0; i < argumentCount; i++)
        cout << "ArgumentVector[" << i << "]: [" << argumentVector[i] << "]" << endl;
}
void Param::fillParams(char** args) {
    //fill params with args array
    inputRedirect = *(args + 0);
    /*parsed args
    char* a = *(args + 0);
    char* b = *(args + 1);
    char* c = *(args + 2);
    char* d = *(args + 3);
    char* e = *(args + 4);
    char* f = *(args + 5);
    */
}