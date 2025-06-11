#include <iostream>

#include "add.h"

#include "my_static_lib.h"

int main()
{
    std::cout << "Hello World!" << std::endl;
    std::cout << "call add(3, 4) : " << add(3, 4) << std::endl;

    print_message();

    return 0;
}
