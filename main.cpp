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
            item.clear();
            fullRecipe.clear();
            item = p.getRandomItem();
            fullRecipe = p.getFullRecipe(item);
        } while (fullRecipe.empty() or (item.find("FICSMAS") != std::string::npos));
        // TODO : remove FICSMAS condition when it is Xmas time IRL

        std::cout << fullRecipe << std::endl
                  << std::endl;
    }

    //////////////// UNIT TESTS ////////////////
    RecipeParser rp{""};
    std::stringstream res;
    if (not rp.TestParseOneIngredientRecipe())
    {
        res << "FAILED UT TestParseOneIngredientRecipe " << std::endl;
    }
    if (not rp.TestParseFullRecipe())
    {
        res << "FAILED UT TestParseOneIngredientRecipe" << std::endl;
    };

    if (res.str().empty())
    {
        std::cout << "All UT passed" << std::endl;
    }
    else
    {
        std::cout << res.str();
    }
    return 0;
}