#include "Parser.hpp"
#include "RecipeParser.hpp"
#include <iostream>
#include <algorithm>
#include <sstream>

Parser::Parser()
{
    std::ifstream dbStream;
    // TODO : Make a database auto-finder in user file system
    dbStream.open("D:/Documents/DEV/Sandbox/Satisfactodle/database.json");
    this->j_complete = json::parse(dbStream); // Input file must be UTF-8 encoded
    dbStream.close();
}

const json Parser::getClassesFromIdx(const uint8_t idx) const
{
    return j_complete.at(idx).at("Classes");
}

std::string Parser::getRandomItem() const
{
    const json allItems = getClassesFromIdx(itemsIdx);
    auto randIt = allItems.begin();
    std::advance(randIt, std::rand() % allItems.size());
    std::string item = randIt.value().at("mDisplayName");

    // TODO: ignore FICSMAS items
    return item.empty() ? throw std::invalid_argument("No Item found. Check file format, content and encoding")
                        : item;
}

// FullRecipe = Item + ingredients
std::string Parser::getFullRecipe(const std::string item) const
{
    const json allRecipes = getClassesFromIdx(recipesIdx);
    for (const auto &recipe : allRecipes.items())
    {
        if (recipe.value().at("mDisplayName") == item)
        {
            // RecipeParser recipeParser(recipe.value().at("mIngredients"));
            // // TODO : make recipe readable
            // return recipeParser.getRecipe();
            return recipe.value().at("mIngredients");
        }
    }
    // TODO : handle no recipe case (e.g. Blue Power Slug)
    return "";
}