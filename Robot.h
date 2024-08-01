#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include "Move.h"
#include "Ninja.h"
#include "Zombie.h"

class Robot : public Move
{
public:
    std::string getName() const override;
    std::vector<std::string> getStrongerAgainst() override;
};
#endif