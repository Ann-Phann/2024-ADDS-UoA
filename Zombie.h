#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include "Move.h"
#include "Pirate.h"
#include "Monkey.h"
class Zombie : public Move
{
public:
    std::string getName() const override;
    std::vector<std::string> getStrongerAgainst() override;
};
#endif