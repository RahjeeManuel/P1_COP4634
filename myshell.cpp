#include "myshell.hpp"
string Myshell::readFile(string fileName) {
    string output;
    ifstream file(fileName);
    if (file.is_open()) {
        string line;
        while(getline(file, line)) {
            output = output + line;
        }
        file.close();
    }
    return output;
}
void Myshell::writeFile(string fileName, string input) {
    ofstream file(fileName);
    if (file.is_open()) {
        file << input;
        file.close();
    }
}
void Myshell::execute(Param params) {
    //execute here
    //
    //
}
Myshell::Myshell(string prompt, string exit) {
    this->prompt = prompt;
    this->exit = exit;
}
void Myshell::start(bool debug) {
    string input;
    do {
        cout << prompt << " ";
        getline(cin, input);
        if (input != exit) {
            Param params(Parse::tokenize(input));
            execute(params);
            if (debug) {
                params.printParams();
            }
        } else {
            break;
        }
    } while (true);
}
int main(int argc, char* argv[]) {
    Myshell s;
    s.start(argc >=2 ? (!strcmp(argv[1], "-Debug")) : false);
    return 0;
}