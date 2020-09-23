#include "Field.h"

int main() {
    Field &field = Field::instance();
    field.showField();
    Point point = field.getEntrance();
    Point point1 = field.getExit();
    std::cout<<point.x<<' '<<point.y<<std::endl;
    std::cout<<point1.x<<' '<<point1.y<<std::endl;
    return 0;
}
