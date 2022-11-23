#include "Parser.hpp"
#include "submodules/json/single_include/nlohmann/json.hpp"
#include <iostream>
#include <algorithm>
#include <sstream>

using json = nlohmann::json;

Parser::Parser()
{
    // TODO : Make a database auto-finder in user file system
}

std::string Parser::getFirstDisplayNameItem()
{
    dbStream.open("D:/Documents/DEV/Sandbox/Satisfactodle/database.json");

    json j_complete = json::parse(dbStream);
    dbStream.close();

    json object = j_complete.items().begin().value();
    std::string nameItemStr = object.at("NativeClass");
    return nameItemStr.empty() ? throw std::invalid_argument("No Item found. Check file format, content and encoding")
                               : nameItemStr;
}

std::string Parser::getRecipe()
{
    // TODO : Parse item recipe
    return "";
}