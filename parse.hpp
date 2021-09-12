//defines the functionality you want to expose
#ifndef PARSE_HPP
#define PARSE_HPP

class Parse{
    private:
        std::string inputstr;
        char str[]; //store input str into char array
        char *ptr; 
    public:
        Parse(std::string inputstr);// string i/p 
        void tokenizer(); //tokenize each string into tokens w delimiters
        char * getPtr(); //return pointer of tokinzed arr

};
#endif
