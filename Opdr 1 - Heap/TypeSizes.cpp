#include "TypeSizes.h"

void TypeSizes::DisplayTypeSizes() {
    bool boolValFalse = false;
    bool boolValTrue = true;
    int intVal;
    float floatVal;
    char charVal;
    std::string stringVal;


    unsigned int boolSizeFalse = sizeof(boolValFalse);
    unsigned int boolSizeTrue = sizeof(boolValFalse);
    unsigned int intSize = sizeof(intVal);
    unsigned int floatSize = sizeof(floatVal);
    unsigned int charSize = sizeof(charVal);
    unsigned int stringSize = sizeof(stringVal);

    std::cout
        << "Bool size false: "
        << boolSizeFalse
        << "\n"
        << "Bool size true: "
        << boolSizeTrue
        << "\n"
        << "Int size: "
        << intSize
        << "\n"
        << "Float size: "
        << floatSize
        << "\n"
        << "Char size: "
        << charSize
        << "\n"
        << "String size: "
        << stringSize
        << "\n"
        ;
}
