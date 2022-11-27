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
    RecipeParser(const std::string rawString) : rawRecipe(rawString)
    {
        // parseRawRecipe();
    }

    std::string getRecipe() const
    {
        std::stringstream recipeStream;
        for (const Ingredient &ingredient : ingredients)
        {
            recipeStream << std::endl;
            recipeStream << ingredient.amount << " " << ingredient.displayName;
        }
        return recipeStream.str();
    }

    // TODO : remove it, abusive and dirty UT
    bool TestParseOneIngredientRecipe()
    {
        // first item of Recipe_Alternate_ClassicBattery_C
        const std::string testStr{"((ItemClass=BlueprintGeneratedClass'\"/Game/FactoryGame/Resource/RawResources/Sulfur/Desc_Sulfur.Desc_Sulfur_C\"',Amount=6))"};
        parseRawRecipe(testStr);

        if ((ingredients.size() == 1) and (ingredients.at(0).displayName == "Desc_Sulfur_C") and ((ingredients.at(0).amount == 6)))
        {
            return true;
        }
        std::cout << std::endl
                  << getRecipe() << std::endl;
        return false;
    }

    // TODO : remove it, abusive and dirty UT
    bool TestParseFullRecipe()
    {
        // Full Recipe_Alternate_ClassicBattery_C
        const std::string testStr{"((ItemClass=BlueprintGeneratedClass'\"/Game/FactoryGame/Resource/RawResources/Sulfur/Desc_Sulfur.Desc_Sulfur_C\"',Amount=6),(ItemClass=BlueprintGeneratedClass'\"/Game/FactoryGame/Resource/Parts/AluminumPlate/Desc_AluminumPlate.Desc_AluminumPlate_C\"',Amount=7),(ItemClass=BlueprintGeneratedClass'\"/Game/FactoryGame/Resource/Parts/Plastic/Desc_Plastic.Desc_Plastic_C\"',Amount=8),(ItemClass=BlueprintGeneratedClass'\"/Game/FactoryGame/Resource/Parts/Wire/Desc_Wire.Desc_Wire_C\"',Amount=12))"};
        parseRawRecipe(testStr);

        if ((ingredients.size() == 4) and
            ((ingredients.at(0).displayName == "Desc_Sulfur_C") and ((ingredients.at(0).amount == 6))) and
            ((ingredients.at(1).displayName == "Desc_AluminumPlate_C") and ((ingredients.at(1).amount == 7))) and
            ((ingredients.at(2).displayName == "Desc_Plastic_C") and ((ingredients.at(2).amount == 8))) and
            ((ingredients.at(3).displayName == "Desc_Wire_C") and ((ingredients.at(3).amount == 12))))
        {
            return true;
        }
        std::cout << std::endl
                  << getRecipe() << std::endl;
        return false;
    }

private:
    void parseRawRecipe(const std::string s)
    {
        ingredients.clear();
        /* regex \.(.*?)\\ matches Desc_Sulfur_C in 1rst UT input string */
    }

    // TODO : make UT to ensure all items from recipes are correctly readable
    // E.G. get raw string, use regex to have a key, and check this key exists in Item list
    const std::string rawRecipe;
    IngredientList ingredients{};
};