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

std::string Parser::getRecipeIngredients(const std::string item) const
{
    const json allRecipes = getClassesFromIdx(recipesIdx);
    for (const auto &recipe : allRecipes.items())
    {
        if (recipe.value().at("mDisplayName") == item)
        {
            // TODO : make recipe readable
            return recipe.value().at("mIngredients");
        }
    }
    // TODO : handle no recipe case (e.g. Blue Power Slug)
    return "";
}