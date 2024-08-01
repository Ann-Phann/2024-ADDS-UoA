#include "Robot.h"

std::string Robot::getName() const {
    return "Robot";
}

std::vector<std::string> Robot::getStrongerAgainst()
{
    strongerAgainst.push_back("Ninja");
    strongerAgainst.push_back("Zombie");
    return strongerAgainst;
}