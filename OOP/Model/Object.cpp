#include "Object.h"

std::ostream &operator<<(std::ostream &output, Object& object){
    output<<object.print();
    return output;
}