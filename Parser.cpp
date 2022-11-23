#include "Parser.hpp"
#include <iostream>
#include <algorithm>
#include <sstream>

Parser::Parser()
{
    std::ifstream dbStream;
    // TODO : Make a database auto-finder in user file system
    dbStream.open("D:/Documents/DEV/Sandbox/Satisfactodle/database.json");
    this->j_complete = json::parse(dbStream);
    dbStream.close();
}

std::string Parser::getFirstDisplayNameItem()
{
    json allItems = j_complete.items().begin().value().at("Classes");
    auto randIt = allItems.begin();
    std::advance(randIt, std::rand() % allItems.size());
    std::string nameItemStr = randIt.value().at("mDisplayName");

    return nameItemStr.empty() ? throw std::invalid_argument("No Item found. Check file format, content and encoding")
                               : nameItemStr;
}

std::string Parser::getRecipe()
{
    // TODO : Parse item recipe
    return "";
}