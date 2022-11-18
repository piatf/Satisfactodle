#pragma once

#include <string>
#include <fstream>

class Parser
{
    std::ifstream dbStream;

public:
    Parser();
    std::string getFirstDisplayNameItem();
    std::string getRecipe();
};