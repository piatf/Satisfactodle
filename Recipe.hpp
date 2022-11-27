#pragma once

#include <string>
#include <vector>
#include <regex>

class Recipe
{
public:
    struct Ingredient
    {
        uint8_t amount;
        std::string displayName;
    };

    Recipe() = delete;
    Recipe(const std::string rawString) : rawRecipe(rawString)
    {
    }

    std::string getRawRecipe() const
    {
        return rawRecipe;
    }

private:
    // TODO : make UT to ensure all items from recipes are correctly readable
    // E.G. get raw string, use regex to have a key, and check this key exists in Item list
    std::string rawRecipe{};
    std::vector<Ingredient> listIngredients{};
};