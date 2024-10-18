#include <print>

int main()
{
#if defined(ABC)
    std::println("ABC is defined!");
#endif

#if (DEF > 2*4-3)
    std::println("DEF is greater than 5!");
#endif
    return 0;
}
