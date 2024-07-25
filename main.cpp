#include <iostream>
#include "Human.h"
#include "Computer.h"
#include "Referee.h"

int main()
{
    Player* p1 = new Human();
    Player* p2 = new Computer();

    Referee ref; 

    Player* winner = ref.refGame(p1,p2);

    if (winner == nullptr) {
        std::cout << "It's a Tie." <<std::endl;

    } else {
        std::cout << winner->getName() << "Wins." <<std::endl;
    }
    return 0;
}