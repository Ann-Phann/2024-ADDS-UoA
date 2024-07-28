#include <iostream>
#include "Human.h"
#include "Computer.h"
#include "Referee.h"

int main()
{
    // Assuming the Human class is defined and included correctly
    Player* p1 = new Human("Annn");
    Player* p2 = new Computer();

    Referee ref; 

    Player* winner = ref.refGame(p1,p2);

    if (winner == nullptr) {
        std::cout << "It's a Tie." <<std::endl;

    } else {
        std::cout << winner->getName() << " Wins." <<std::endl;
    }

    // Clean up dynamically allocated memory
    delete p1;
    delete p2;


    return 0;
}