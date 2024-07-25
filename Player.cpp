#include "Player.h"

Player::Player()
{
    move = 'N';
    name = "Null";
}
Player::Player(std::string& name)
{
    this->name = name;
}

std::string Player::getName()
{
    return name;
}

void Player::setName(std::string name)
{
    this->name = name;
}