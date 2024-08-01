#include "Human.h"

Human::Human() : Player("Human") {}

Human::Human(const std::string name) : Player(name) {}

Move* Human::makeMove()
{

    std::cout << "Enter Move: ";
    std::string moveName;
    std::cin >> moveName;
    
    if (moveName == "Rock")
    {
        return new Rock();
    } else if (moveName == "Paper")
    {
        return new Paper();
    } else if (moveName == "Scissors")
    {
        return new Scissors();
    } else if (moveName == "Monkey")
    {
        return new Monkey();
    } else if (moveName == "Pirate")
    {
        return new Pirate();
    } else if (moveName == "Ninja")
    {
        return new Ninja();
    } else if (moveName == "Zombie")
    {
        return new Zombie();
    } else
    {
        return nullptr;
    }   
}