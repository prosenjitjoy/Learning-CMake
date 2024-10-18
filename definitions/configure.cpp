#include <print>
#include "configured/configure.h"

// special macros to convert definitions into c-strings:
#define str(s) #s
#define xstr(s) str(s)

int main()
{
#ifdef FOO_ENABLE
    std::println("FOO_ENABLED: ON");
#endif
    std::println("FOO_STRING1: {}", xstr(FOO_STRING1));
    std::println("FOO_STRING2: {}", xstr(FOO_STRING2));
    std::println("FOO_UNDEFINED: {}", xstr(FOO_UNDEFINED));
}
