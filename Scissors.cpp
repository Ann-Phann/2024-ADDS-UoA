#include "Scissors.h"

std::string Scissors::getName() const {
    return "Scissors";
}

std::vector<std::string> Scissors::getStrongerAgainst()
{
    strongerAgainst.push_back("Paper");
    return strongerAgainst;
}