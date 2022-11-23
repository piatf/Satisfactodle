#pragma once

#include <string>
#include <fstream>
#include "submodules/json/single_include/nlohmann/json.hpp"

using json = nlohmann::json;

class Parser
{

public:
    Parser();
    std::string getFirstDisplayNameItem();
    std::string getRecipe();

private:
    json j_complete;
};