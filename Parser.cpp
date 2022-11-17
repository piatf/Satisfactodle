#include "Parser.hpp"
#include <iostream>
#include <algorithm>

Parser::Parser()
{
    this->dbStream.open("database.json");
}

std::string Parser::getFirstDisplayNameItem()
{
    std::string tmpBuff{};
    std::string displayNameKey{"mDisplayName"};

    for (std::string tmpBuff; std::getline(dbStream, tmpBuff);)
    {
        tmpBuff.erase(remove(tmpBuff.begin(), tmpBuff.end(), '\"'), tmpBuff.end());
        std::cout << tmpBuff << std::endl;
        if (tmpBuff.find(displayNameKey) != std::string::npos) // BUG HERE, never go in
        {
            return tmpBuff;
        }
    }
    return "";
}

std::string Parser::getRecipe()
{
    // TODO
    return "";
}