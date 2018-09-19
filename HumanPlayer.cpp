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
	std::cout<<"please input :"<<std::endl;
	int row,col;
	std::cin>>row>>col;
	return row*BOARD_COL+col;
}

