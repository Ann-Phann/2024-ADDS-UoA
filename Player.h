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
    Player(const std::string& name);

    virtual char makeMove() = 0;
    std::string getName();
    void setName(std::string name);

    virtual ~Player() = default;
};
#endif