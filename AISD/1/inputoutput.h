#ifndef INPUTOUTPUT_H
#define INPUTOUTPUT_H
#include "structs.h"

string Cuinput(int argc, char** argv);

void ProceedOutput(string output, int indent);

void ProceedErr(const string& err, int& pos);

#endif