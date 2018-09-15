#pragma once
#include<map>
#include"Player.h"
class GameControl
{
public:
    GameControl() {}
    ~GameControl() {}
    void run();
    void setPlayer(Player*player,int player_id);
    Player*getPlayer(int player_id);
    void initGameState(const GameState&state){ m_gameState=state; }
private:
    GameState m_gameState;
    std::map<int,Player*>m_players;
};

