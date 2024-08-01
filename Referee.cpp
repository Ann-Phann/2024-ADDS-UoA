#include "Referee.h"
Referee::Referee() {}
Player* Referee:: refGame(Player * player1, Player * player2)
{
    Move* move1 = player1->makeMove();
    Move* move2 = player2->makeMove();

    if (move1->getName() == move2->getName())
    {
        return nullptr;
    }

    for(int i = 0; i < move1->getStrongerAgainst().size(); i++)
    {
        if (move2->getName() == move1->getStrongerAgainst()[i])
        {
            return player1;
        }
    }
    return player2;

    
}