#include "Parser.hpp"
#include "submodules/json/single_include/nlohmann/json.hpp"
#include <iostream>
#include <algorithm>
#include <sstream>

using json = nlohmann::json;

Parser::Parser()
{
    // this->dbStream.open("database.json");
}

std::string Parser::getFirstDisplayNameItem()
{
    // std::string tmpBuff{};
    std::ifstream dbStream("./database.json");
    // json j = json::parse(dbStream);
    // std::string line;
    // while (std::getline(dbStream, line))
    // {
    //     std::cout << json::parse(line) << std::endl;
    // }
    // return j.at("iii");
    std::cout << std::boolalpha
              << json::accept(dbStream);
    return "";
}

std::string Parser::getRecipe()
{
    // TODO
    return "";
}