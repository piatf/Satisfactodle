#include "Parser.hpp"
#include "submodules/json/single_include/nlohmann/json.hpp"
#include <iostream>
#include <algorithm>
#include <sstream>

using json = nlohmann::json;

Parser::Parser()
{
    this->dbStream.open("database.json");
    assert(json::accept(dbStream));
}

std::string Parser::getFirstDisplayNameItem()
{
    std::string nameItemStr;
    // std::string tmpBuff{};
    // std::ifstream dbStream("./database.json");
    // json j = json::parse(dbStream);
    // std::string line;
    // return j.at("ClassName");

    // for (std::string tmpBuff; std::getline(dbStream, tmpBuff);)
    // {
    //     tmpBuff.erase(remove(tmpBuff.begin(), tmpBuff.end(), '\"'), tmpBuff.end());
    //     // std::cout << tmpBuff << std::endl;
    //     if (tmpBuff.find("mDisplayName") != std::string::npos)
    //     {
    //         return tmpBuff;
    //     }
    // }

    // return "";
    return nameItemStr.empty() ? throw std::invalid_argument("No Item found. Check file format, content and encoding")
                               : nameItemStr;
}

std::string Parser::getRecipe()
{
    // TODO : Parse item recipe
    return "";
}