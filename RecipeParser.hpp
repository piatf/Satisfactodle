#pragma once

#include <string>
#include <vector>
#include <regex>
#include <sstream>
#include <iostream>

class RecipeParser
{
public:
    struct Ingredient
    {
        uint8_t amount;
        std::string displayName;
    };

    using IngredientList = std::vector<Ingredient>;

    RecipeParser() = delete;
    RecipeParser(const std::string rawString);

    std::string getRecipe() const;

    // TODO : remove it, abusive and dirty UT
    bool TestParseOneIngredientRecipe();
    // TODO : remove it, abusive and dirty UT
    bool TestParseFullRecipe();

private:
    void parseRawRecipe(const std::string s);

    // TODO : make UT to ensure all items from recipes are correctly readable
    // E.G. get raw string, use regex to have a key, and check this key exists in Item list
    const std::string rawRecipe;
    IngredientList ingredients{};
};