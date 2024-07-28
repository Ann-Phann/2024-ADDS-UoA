#ifndef REFEREE_H
#define REFEREE_H

#include <iostream>
#include "Player.h"

class Referee {
public:
    Referee();
    Player* refGame(Player * player1, Player * player2);
};
#endif
/*
S: Manages game adjudication between two players. It adheres to SRP by only handling the game logic.
O: Can be extended to include more complex rules or additional game logic without modifying existing code.
D: Depends on the Player abstraction, not on specific implementations. This adheres to DIP by depending on abstractions rather than concrete classes.
*/