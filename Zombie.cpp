#include "Zombie.h"

std::string Zombie::getName() const {
    return "Zombie";
}

std::vector<std::string> Zombie::getStrongerAgainst()
{
    strongerAgainst.push_back("Pirate");
    strongerAgainst.push_back("Monkey");
    return strongerAgainst;
}