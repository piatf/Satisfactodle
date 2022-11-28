#include <iostream>

#include "Parser.hpp"
#include "RecipeParser.hpp"

int main()
{
    Parser p;
    // TODO : Look for a way to add GUI

    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        std::string item, fullRecipe;
        do
        {
            item = p.getRandomItem();
            fullRecipe = p.getFullRecipe(item);
        } while (fullRecipe.empty());

        std::cout << item << std::endl
                  << "Recipe : " << fullRecipe << std::endl;
        std::cout << std::endl;
    }

    RecipeParser rp{""};
    std::stringstream res;
    if (not rp.TestParseOneIngredientRecipe())
    {
        res << "UT#1 FAILED" << std::endl;
    }
    if (not rp.TestParseFullRecipe())
    {
        res << "UT#2 FAILED" << std::endl;
    };

    if (res.str() == "")
    {
        std::cout << "All UT passed" << std::endl;
    }
    else
    {
        std::cout << res.str();
    }
    return 0;
}