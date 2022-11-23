#include <iostream>

#include "Parser.hpp"

int main()
{
    Parser p;
    // TODO : Look for a way to add GUI

    srand(time(NULL));
    std::cout << p.getFirstDisplayNameItem() << std::endl;
    std::cout << p.getFirstDisplayNameItem() << std::endl;
    std::cout << p.getFirstDisplayNameItem() << std::endl;
    std::cout << p.getFirstDisplayNameItem() << std::endl;
    return 0;
}