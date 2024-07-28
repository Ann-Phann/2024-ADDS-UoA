#include "Player.h"

Player::Player()
{

    name = "Null";
}
Player::Player(const std::string& name)
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