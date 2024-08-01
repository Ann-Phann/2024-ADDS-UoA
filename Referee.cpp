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
    
    // std::cout<<move1->getStrongerAgainst().size()<<std::endl;
    // for(int i = 0; i < move1->getStrongerAgainst().size(); i++)
    // {
    //     std::cout<<"i="<<i<<std::endl;
    //     if (move2->getName() == move1->getStrongerAgainst()[i])
    //     {
    //        return player1; 
    //     }
    //     // return player1; 
    // }
    int x;
    int y = move1->getStrongerAgainst().size();
    for (x = 0; x < y; x++)
    {
        // std::cout<<"x="<<x<<std::endl;
        if (move2->getName() == move1->getStrongerAgainst()[x])
        {
            return player1;
        }
    }
    return player2;

    
}