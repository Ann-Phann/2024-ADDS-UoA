#ifndef NINJA_H
#define NINJA_H

#include <iostream>
#include "Move.h"
#include "Pirate.h"
#include "Zombie.h"
class Ninja : public Move
{
public:
    std::string getName() const override;
    std::vector<std::string> getStrongerAgainst() override;
};
#endif