#include "class_b.h"
#include "lib2.h"

std::string Class_b::method() {
    Lib2 lib2;
    return lib2.method();
}
