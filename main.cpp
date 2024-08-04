#include <iostream>
#include "Human.h"
#include "Computer.h"
#include "Referee.h"

int main() {
    Player* player1 = new Human("An");
    Player* player2 = new Human("you");


    Referee ref;
    Player* winner = ref.refGame(player1, player2);

    if (winner == nullptr)
    {
        std::cout << "It's a Tie." << std::endl;
    } else {
        std::cout << winner->getName() << " wins!" << std::endl;
    }
    return 0;
}
//$ g++ main.cpp Computer.cpp Human.cpp Monkey.cpp Move.cpp Ninja.cpp Paper.cpp Pirate.cpp Player.cpp Referee.cpp Robot.cpp Rock.cpp Scissors.cpp Zombie.cpp -o 1