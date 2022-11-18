#include <iostream>

#include "Parser.hpp"
// TODO : Create CMake files / build folder
#include "Parser.cpp"

int main()
{
    Parser p;
    // TODO : Look for a way to add GUI
    // TODO : Choose game item randomly
    std::cout << p.getFirstDisplayNameItem() << std::endl;
    return 0;
}