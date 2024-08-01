#include "Rock.h"

std::string Rock::getName() const {
    return "Rock";
}

std::vector<std::string> Rock::getStrongerAgainst()
{
    strongerAgainst.push_back("Scissors");
    return strongerAgainst;
}