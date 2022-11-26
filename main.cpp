#include <iostream>

#include "Parser.hpp"

int main()
{
    Parser p;
    // TODO : Look for a way to add GUI

    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        auto item = p.getRandomItem();
        std::cout << item << std::endl
                  << "Recipe : " << p.getRecipeIngredients(item) << std::endl;
        std::cout << std::endl;
    }

    return 0;
}