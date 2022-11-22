#include <iostream>

#include "Parser.hpp"

int main()
{
    Parser p;
    // TODO : Look for a way to add GUI
    // TODO : Choose game item randomly
    std::cout << p.getFirstDisplayNameItem() << std::endl;
    return 0;
}