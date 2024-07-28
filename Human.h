#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <string>
#include "Player.h"
class Human : public Player{

public:
    Human();
    Human(const std::string& name);
    char makeMove();
   
};
#endif
/*
S: Handles input for the human player's move. It adheres to SRP by only managing human-specific functionality.
O: Human and Computer Classes: These classes extend Player without modifying it, adhering to OCP.
L: Human and Computer Classes: These classes can be used interchangeably with Player references or pointers, adhering to LSP.
I: Human Class: Implements the necessary makeMove method. This follows ISP since it only implements the required methods. Implement only the methods they need, adhering to ISP.
*/