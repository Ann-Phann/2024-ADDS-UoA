#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class Player {
private:
    char move;
    std::string name;
public:
    Player();
    Player(std::string& name);
    virtual char makeMove() = 0;
    // virtual std::string getName() = 0;
    std::string getName();
    void setName(std::string name);
};
#endif