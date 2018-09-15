#include <iostream>
#include"GameControl.h"
void GameControl::setPlayer(Player*player,int player_id)
{
    m_players[player_id]=player;
}

Player* GameControl::getPlayer(int player_id){
    auto it=m_players.find(player_id);
    if(it!=m_players.end()){
        return it->second;
    }
    else
        return NULL;
}
void GameControl::run()
{
    while(!m_gameState.isGameOver()){
        int playerId=m_gameState.getCurrentPlayer();
        Player*currentPlayer=getPlayer(playerId);
        int np=currentPlayer->getNextPosition();
        m_gameState.setGameCell(np,playerId);
        m_gameState.printGame();
        m_gameState.switchPlayer();

    }
    int winner=m_gameState.getWinner();
    if(winner==PLAYER_NULL){
        std::cout<<"gameover,draw!"<<std::endl;

    }
    else{
        Player*winnerPlayer=getPlayer(winner);
        std::cout<<"gameover "<<winnerPlayer->getPlayerName()<<std::endl;
    }
}

