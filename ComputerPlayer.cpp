#include <iostream>
#include "ComputerPlayer.h"
#include "GameState.h"
ComputerPlayer::ComputerPlayer()
{
    m_searcher=NULL;
    m_depth=3;
}
ComputerPlayer::ComputerPlayer(const std::string&name)
{
    m_searcher=NULL;
    m_depth=3;
    setPlayerName(name);
}

ComputerPlayer::~ComputerPlayer()
{

}

int ComputerPlayer::getNextPosition()
{
    int np=m_searcher->searchBestPlay(*m_state,m_depth);
    int row=np/BOARD_COL;
    int col=np%BOARD_COL;
    std::cout<<"computer play at ["<<row+1<<","<<col+1<<"]"<<std::endl;
    return np;
}
void ComputerPlayer::setSearcher(Searcher* searcher,int depth)
{
    Searcher* tmp=m_searcher;
    m_searcher=searcher;
    m_depth=depth;

}

