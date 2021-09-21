#include "param.hpp"
#include <string.h>
Param::Param(vector<string> tokens) {
    argumentVector = tokens;
    /*
    for (unsigned int i = 0; i < argumentVector.size(); i++) {
        if (argumentVector.at(i).find("<") == 0) {
            inputRedirect = argumentVector.at(i).substr(1);
        } else if (argumentVector.at(i).find(">") == 0) {
            outputRedirect = argumentVector.at(i).substr(1);
        }
    }*/

    for(unsigned int i = 0; i <argumentVector.size(); i++){

        if(tokens.at(i).find("<") == 0){
            inputRedirect = tokens.at(i).substr(1);
        }else if(tokens.at(i).find(">") == 0){
            outputRedirect = tokens.at(i).substr(1);
        }else 
            this->argumentVector.at(i) == tokens.at(i);
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