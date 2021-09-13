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
Param::Param(char *argumentVector){
    //allocate array to store i/p o/p redirects
    inputRedirect = new char[];
    outputRedirect = new char[];
    this->argumentVector = argumentVector; //ptr to parsed arr
}
Param::~Param(){
    delete[] inputRedirect;
    delete[] outputRedirect;
    delete argumentVector;
}
void Param::setBackground(bool num){
    if(num == 1)
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
