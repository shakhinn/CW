#include "Field.h"

int main() {
    Field &field = Field::instance();
    field.showField();
    return 0;
}
