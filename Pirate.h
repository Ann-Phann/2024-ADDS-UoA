#ifndef PIRATE_H
#define PIRATE_H

#include "Move.h"


class Pirate : public Move
{
public:
    std::string getName() const override;
    std::vector<std::string> getStrongerAgainst() override;
};
#endif