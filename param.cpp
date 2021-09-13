//class to hold parsed input data
#include "param.hpp"
using std::cout;
using std::endl;

void Param::printParams() {
    cout << "InputRedirect: [" << ((inputRedirect != NULL) ? inputRedirect : "NULL") << "]" << endl <<
        "OutputRedirect: [" << ((outputRedirect != NULL) ? outputRedirect : "NULL") << "]" << endl <<
        "Background: [" << background << "]" << endl <<
        "ArgumentCount: [" << argumentCount << "]" << endl;
    for (int i = 0; i < argumentCount; i++)
        cout << "ArgumentVector[" << i << "]: [" << argumentVector[i] << "]" << endl;
}
Param::Param(char *argumentVector){//token
    //allocate array to store i/p o/p redirects
    inputRedirect = new char[];
    outputRedirect = new char[];
    
    //fill in array w token
    while (argumentVector != NULL) {
        this->argumentVector[i++] = argumentVector;
        // some code idk
    }
}
Param::~Param(){
    delete[] inputRedirect;
    delete[] outputRedirect;
    delete argumentVector;
}
void Param::setBackground(char amp){
    if(amp = '&')
        this->background = 1;
    else 
        this->background = 0;
}
int Param::getBackground(){
    return background;
}
void Param::setArgumentCount(int argumentCount){
    this->argumentCount = argumentCount;
}
int Param::getArgumentCount(){
    return this->argumentCount;
}
