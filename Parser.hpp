#pragma once

#include <string>
#include <fstream>
#include "submodules/json/single_include/nlohmann/json.hpp"

using json = nlohmann::json;

class Parser
{

public:
    Parser();
    std::string getRandomItem() const;
    std::string getRecipeIngredients(const std::string item) const;

private:
    json j_complete;
};