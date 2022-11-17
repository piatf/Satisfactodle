#include <iostream>

#include "Parser.hpp"
#include "Parser.cpp"

int main()
{
    Parser p;
    std::cout << p.getFirstDisplayNameItem() << std::endl;
    return 0;
}