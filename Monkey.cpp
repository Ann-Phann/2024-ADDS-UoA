#include "Monkey.h"

std::string Monkey::getName() const {
    return "Monkey";
}

std::vector<std::string> Monkey::getStrongerAgainst()
{
    strongerAgainst.push_back("Ninja");
    strongerAgainst.push_back("Robot");
    return strongerAgainst;
}