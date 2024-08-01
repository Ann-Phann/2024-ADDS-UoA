#ifndef SCISSORS_H
#define SCISSORS_H

#include <iostream>
#include "Move.h"
#include "Paper.h"

class Scissors : public Move
{
public:
    std::string getName() const override;
    std::vector<std::string> getStrongerAgainst() override;
};
#endif