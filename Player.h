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

/*
S: Handles basic player attributes (name) and declares virtual functions. The base class itself adheres to SRP.
O: The base class is open for extension, as it declares a virtual function that derived classes can override. Open for extension through derived classes (e.g., Human, Computer) but closed for modification.
L: Derived classes (Human, Computer) can be used interchangeably with Player references or pointers.
I: Player Class: Only declares the necessary virtual functions. This follows ISP since it doesn't force derived classes to implement unnecessary methods.
*/