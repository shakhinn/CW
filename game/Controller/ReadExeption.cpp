#include "ReadExeption.h"

ReadException::ReadException(std::string e) : error(e) {}

std::string& ReadException::getError() {
    return error;
}