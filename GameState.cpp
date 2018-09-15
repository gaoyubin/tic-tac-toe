#include <iostream>
#include"GameState.h"

void GameState::initGameState(int firstPlayer)
{
    for(int i=0;i<BOARD_CELLS;i++){
       m_board[i]=0; 
    }
    m_playerId=firstPlayer;
}

bool GameState::isGameOver()
{
    int aThree=countThreeLine(m_playerId);
    if(aThree!=0)
        return true;
    int peer=getPeerPlayer(m_playerId);
    int bTree=countThreeLine(peer);
    if(bTree!=0)
        return true;
    return false;

}

int GameState::countThreeLine(int player_id)
{
    int lines=0;
    for(int i=0;i<LINE_DIRECTION;i++){
        int sameCount=0;
        for(int j=0;j<LINE_CELLS;j++){
            if(m_board[line_idx_tbl[i][j]]==player_id){
                sameCount++;
            }
        }
        if(sameCount==3)
            lines++;        
    }    
    return lines;
}

void GameState::setGameCell(int cell,int player_id)
{
    m_board[cell]=player_id;
}
    
void GameState::printGame()
{
    std::cout<<"current game state:"<<std::endl;
    for(int i=0;i<BOARD_CELLS;i++){
        std::cout<<getCellType(m_board[i]);
        if(i%BOARD_COL==2)
            std::cout<<std::endl;
    }
}
char GameState::getCellType(int player_id)
{
    if(player_id==PLAYER_NULL){
        return CELL_EMPTY;
    }
    else{
        return (player_id==PLAYER_B)?CELL_X:CELL_O;
    }
}

void GameState::switchPlayer()
{
    m_playerId=getPeerPlayer(m_playerId);
}

int GameState::getWinner()
{
    int aThree=countThreeLine(m_playerId);
    if(aThree!=0)
        return m_playerId;
    int peer=getPeerPlayer(m_playerId);
    int bThree=countThreeLine(peer);
    if(bThree!=0)
        return peer;
    return PLAYER_NULL;
}

bool GameState::isEmptyCell(int cell)const
{
    return m_board[cell]==PLAYER_NULL;
}

