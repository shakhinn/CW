#ifndef ALGO_H
#define ALGO_H

#include "structs.h"
#include "inputoutput.h"

#define TRUE_S "TRUE"
#define FALSE_S "FALSE"
#define NOT_S "NOT"
#define AND_S "AND"
#define OR_S "OR"
#define OPEN_BRACKET "("
#define CLOSE_BRACKET ")"
#define COMMA ","

bool Statement (string& str, int& pos, int indent);

bool Operands(string& str, int& pos, int indent);

bool Operation (string& str, int& pos, int indent);

bool FindWord (string& str, int& pos, int indent, const char* word);

bool CheckLetter(string& str, int& pos, int indent);

bool CheckString(string& str);

void Skip (string& str, int& pos, int indent, int n = 1);
#endif

