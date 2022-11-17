#pragma once

#include <string>
#include <fstream>

class Parser
{
    std::fstream dbStream;

public:
    Parser();
    std::string getFirstDisplayNameItem();
    std::string getRecipe();
};