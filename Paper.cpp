#include "Paper.h"

std::string Paper::getName() const {
    return "Paper";
}

std::vector<std::string> Paper::getStrongerAgainst()
{
    strongerAgainst.push_back("Rock");
    return strongerAgainst;
}