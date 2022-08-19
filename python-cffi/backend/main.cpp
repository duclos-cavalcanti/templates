#include <iostream>
#include <vector>

#include "backend.h"

int main(int argc, char *argv[])
{
    // this is useful to test the C++ code together
    int a = 10;
    int b = 2;

    std::cout << "a is " << a << " and b is " << b << std::endl;
    std::cout << "a + b is " << my_add(a, b) << std::endl;
    std::cout << "a - b is " << my_sub(a, b) << std::endl;
    std::cout << "a x b is " << my_mul(a, b) << std::endl;

    return 0;
}
