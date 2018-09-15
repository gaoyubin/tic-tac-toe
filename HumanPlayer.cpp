#include <iostream>
#include "HumanPlayer.h"
HumanPlayer::HumanPlayer()
{
    
}

HumanPlayer::HumanPlayer(const std::string&name)
{
    setPlayerName(name);
}

HumanPlayer::~HumanPlayer()
{

}

int HumanPlayer::getNextPosition()
{
    return 1;
}

