#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"
class Computer : public Player{
public:
    Computer();
    char makeMove() override;
};
#endif
/*
S: Manages the computer player's move, which is fixed as R. It adheres to SRP by only handling computer-specific functionality.
O: These classes extend Player without modifying it, adhering to OCP.
*/