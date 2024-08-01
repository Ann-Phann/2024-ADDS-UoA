#include "Pirate.h"

std::string Pirate::getName() const {
    return "Pirate";
}

std::vector<std::string> Pirate::getStrongerAgainst()
{
    strongerAgainst.push_back("Robot");
    strongerAgainst.push_back("Monkey");
    return strongerAgainst;
}