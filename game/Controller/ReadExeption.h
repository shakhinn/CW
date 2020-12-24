#ifndef OOP_READEXEPTION_H
#define OOP_READEXEPTION_H

#include <string>

class ReadException {
    std::string error;

public:
    ReadException(std::string e);
    std::string& getError();
};



#endif //OOP_READEXEPTION_H
