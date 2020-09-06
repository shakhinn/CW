#include "structs.h"
#include "algo.h"
#include "inputoutput.h"

int main(int argc, char** argv) {
    string expression = Cuinput(argc, argv);
    if(expression == "HELP"){
        return 0;
    }
    cout<<"Вы ввели: "<< expression<<endl;
    bool result = CheckString(expression);
    if(result){
        cout<<"SUCCESS\n";
    } else{
        cout<<"NOT_CORRECT\n";
    }
    if(argc > 1){
        if(result) {
            ofstream outfile(optarg, ios::app);
            outfile << "SUCCESS\n";
        } else{
            ofstream outfile(optarg, ios::app);
            outfile << "NOT_CORRECT\n";
        }
    }
    return 0;
}
