#include "algo.h"



void Skip(string& str, int& pos, int indent, int n){
    if (str.length() >= n) {
        // Вывод удаляемых символов
        ProceedOutput(str.substr(0, n), indent);
        str = str.substr(n);
        pos++;
    }
}

bool FindWord (string& str, int& pos, int indent, const char* word){
    int len = strlen(word);
    // Сравнение начала строки с word
    if (!str.compare(0, len, word) && (len == str.length() || (len < str.length() && (!isalnum(str[len]) || !isalnum(word[0]))))){
        Skip(str, pos, indent, len);
        return true;
    }
    return false;
}

bool CheckLetter(string& str, int& pos, int indent){
    // Проверка, является ли первый символ строки буквой
    if ((str.length() == 1 && isalpha(str[0])) || (str.length() > 1 && isalpha(str[0]) && !isalnum(str[1]))) {
        Skip(str, pos, indent);
        return true;
    }
    return false;
}

// AND | OR
bool Operation (string& str, int& pos, int indent){
    if (FindWord(str, pos, indent, AND_S)) {
        return true;
    }
    else if (FindWord(str, pos, indent, OR_S )) {
        return true;
    }
    return false;
}

// Operand | Operand, OperandList
bool Operands(std::string& str, int& pos, int indent) {
    if (Statement(str, pos, indent + 1)) {
        if (FindWord(str, pos, indent, COMMA )) {
            return Operands(str, pos, indent);
        }
        return true;
    }
    return false;
}

bool Statement (string& str, int& pos, int indent){
    Info(indent, START);
    if (FindWord(str, pos, indent, TRUE_S )) {
        Info(indent, END);
        return true;
    }
    else if (FindWord(str, pos, indent, FALSE_S )) {
        Info(indent, END);
        return true;
    }
    else if (CheckLetter(str, pos, indent)) {
        Info(indent, END);
        return true;
    }
    else if (FindWord(str, pos, indent, NOT_S )) {
        if (FindWord(str, pos, indent, OPEN_BRACKET )) {
            if (Statement(str, pos, indent + 1) && FindWord(str, pos, indent, CLOSE_BRACKET )) {
                Info(indent, END);
                return true;
            }
            else ProceedErr("')' expected", pos);
        }
        else ProceedErr("'(' expected", pos);
    }
    else if (Operation(str, pos, indent + 1)) {
        if (FindWord(str, pos, indent, OPEN_BRACKET )) {
            if (Operands(str, pos, indent + 1) && FindWord(str, pos, indent, CLOSE_BRACKET )) {
                Info(indent, END);
                return true;
            }
            else ProceedErr("')' expected", pos);
        }
        else ProceedErr("'(' expected", pos);
    }
    ProceedErr("Statement expected", pos);
    Info(indent, END);
    return false;
}

bool CheckString(string& str){
    std::string copy = string(str);
    int position = 0;
    if (Statement(copy, position, 1)) {
        if (copy.empty()) {
            return true;
        }
        else ProceedErr("End of string expected. \"" + copy + "\" left", position);
    }
    // Вывод ошибки
    cout << "> " << str << endl << "> ";
    for (int i = 0; i < str.length() - copy.length(); ++i) {
        cout << " ";
    }
    cout << "^" << endl;
    return false;
}