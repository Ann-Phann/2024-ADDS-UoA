#ifndef ROCK_H
#define ROCK_H

#include <iostream>
#include "Move.h"
#include "Scissors.h"
class Rock : public Move
{
public:
    std::string getName() const override;
    std::vector<std::string> getStrongerAgainst() override;
};
#endif