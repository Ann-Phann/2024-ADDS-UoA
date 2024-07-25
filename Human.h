#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <string>
#include "Player.h"
class Human : public Player{

public:
    Human();
    Human(std::string& name);
    char makeMove();
   
};
#endif