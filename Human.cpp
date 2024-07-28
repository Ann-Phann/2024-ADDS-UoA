#include "Human.h"

Human::Human() 
{
    Player::setName("Human");
}

Human::Human(const std::string &name) : Player(name)
{}

char Human::makeMove()
{
    char move;
    do {
        std::cout << "Enter move: ";
        std::cin >> move;
        
    } while (move != 'R' && move != 'P' && move != 'S');
    return move;
}