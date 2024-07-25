#include "Human.h"

Human::Human() 
{
    Player::setName("Human");
}

Human::Human(std::string &name) : Player(name)
{}

char Human::makeMove()
{
    char move;
    std::cout << "Enter move: ";
    std::cin >> move;
    return move;
}
