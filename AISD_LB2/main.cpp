#include <iostream>
#include "lisp.h"

int main (int argc, char** argv){
    string input = cuinput(argc, argv);
    if(input.empty()){
        cout<<"\033[1;31mERROR\033[0m\n";
        return 0;
    }
    string copy = string(input);
    int pos = 0;
    errorFlag = false;
    int indent = 1;
    Expression * expression = scanExpression(copy, pos, indent);
    if (!copy.empty() && !errorFlag) {
        cout << pos << ": End of expression expected" << endl;
        errorPos = pos;
        errorFlag = true;
    }
    cout << input << endl;
    if (errorFlag) {
        for (int i = 0; i < errorPos; i++) {
            cout << '.';
        }
        cout << "^" << endl << "\033[1;31mERROR\033[0m\n";
    }
    else {
        cout << "\033[1;32mSUCCESS\033[0m\n";
    }
    if(argc > 1){
        if(errorFlag) {
            ofstream outfile(optarg, ios::app);
            outfile << "ERROR\n";
        } else{
            ofstream outfile(optarg, ios::app);
            outfile << "SUCCESS\n";
        }
    }
    destroy(expression);
    return 0;
}
