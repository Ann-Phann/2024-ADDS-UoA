#include "Player.h"

Player::Player() : name{"NULL"} {}

Player::Player(const std::string name) : name{name} {}

std::string Player::getName() const{
    return name;
}

void Player::setName(std::string name)
{
    this->name = name;
}