#include "Ninja.h"

std::string Ninja::getName() const {
    return "Ninja";
}

std::vector<std::string> Ninja::getStrongerAgainst()
{
    strongerAgainst.push_back("Pirate");
    strongerAgainst.push_back("Zombie");
    return strongerAgainst;
}