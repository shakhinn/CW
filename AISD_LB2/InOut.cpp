#include "InOut.h"

bool errorFlag;
int errorPos;

string cuinput(int argc, char** argv){
    if(argc == 1) {
        cout<<"Введите выражение: ";
        string res;
        getline(cin, res);
        return res;
    }
    int option = 0;
    while ((option = getopt(argc,argv,"hf:"))!=-1){
        switch (option) {
            case 'h': cout<<"Для того чтобы прочитать выражение из файла используйте флаг -f <название файла>.\n"; return "HELP";
            case 'f': cout<<"read from file - "<<optarg<<endl;
                ifstream infile(optarg);
                if (!infile) {
                    cout << "> File can't be open!" << endl;
                    return "";
                }
                string str;
                getline(infile, str);
                return str;
        }
    }
    return "";
}

void proceedOutput(string output, int indent){
    if(output != " ") {
        for (int i = 0; i < indent; i++) {
            cout << "  ";
        }
        cout << output << endl;
    }
}

void proceedErr(const string& err, int& pos){
    if (!errorFlag) {
        errorFlag = true;
        errorPos = pos;
        cout << "> " << pos << ": " << err << endl;
    }
}

void info(int indent, int flag){
    for(int i = 0; i < indent; i++){
        cout<<"  ";
    }
    if(flag == 1){
        cout <<"\033[1;34mSTART FUNCTION SCAN_EXPRESSION\033[0m\n";
    } else if(flag == 2){
        cout <<"\033[1;34mEND FUNCTION SCAN_EXPRESSION\033[0m\n";
    }else if(flag == 3){
        cout <<"\033[1;35mSTART FUNCTION SCAN_NODE\033[0m\n";
    }else if(flag == 4){
        cout <<"\033[1;35mEND FUNCTION SCAN_NODE\033[0m\n";
    }else if(flag == 5){
        cout <<"\033[1;36mSTART FUNCTION SCAN_TAIL\033[0m\n";
    }else if(flag == 6){
        cout <<"\033[1;36mEND FUNCTION SCAN_TAIL\033[0m\n";
    }
}