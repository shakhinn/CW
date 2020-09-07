#ifndef INPUTOUTPUT_H
#define INPUTOUTPUT_H
#include "structs.h"
#define START 1
#define END 0

string Cuinput(int argc, char** argv);

void ProceedOutput(string output, int indent);

void ProceedErr(const string& err, int& pos);

void Info(int indent, int flag);



#endif