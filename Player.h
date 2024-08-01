//abstract class

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Move.h"
#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"
#include "Robot.h"
#include "Monkey.h"
#include "Pirate.h"
#include "Ninja.h"
#include "Zombie.h"
class Player 
{
private:
    std::string name;

public:
    Player();
    Player(const std::string name);
    std::string getName() const;
    void setName(std::string name);

    virtual Move* makeMove() = 0;
    ~Player() = default;

};
#endif