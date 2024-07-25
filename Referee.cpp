#include "Referee.h"

Referee::Referee(){}
Player* Referee::refGame(Player * player1, Player * player2)
{
    char move1 = player1->makeMove();
    char move2 = player2->makeMove();

    if(move1 == move2)
    {
        return nullptr;
    } 
    else if (move1 == 'S' && move2 == 'R'|| move1 == 'P' && move2 == 'S' || move1 == 'R' && move2 == 'P') {
        return player2;
    } else {
        return player1;
    }
}