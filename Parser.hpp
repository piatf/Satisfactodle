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
    std::string getFullRecipe(const std::string item) const;

private:
    std::string getAllIngredients(const std::string item) const;
    const json getClassesFromIdx(const uint8_t idx) const;

    json j_complete;
    uint8_t itemsIdx{0};
    uint8_t recipesIdx{2};
};