#pragma once
#include<string>
#include"GameState.h"
class  Player
{
public:
    Player() {}
    ~Player() {}
    void setPlayerName(const std::string& name){m_playerName=name;}
    virtual int getNextPosition()=0;
    void setGameState(GameState*state){m_state=state;}
    GameState* getGameState(){return m_state;}
    std::string& getPlayerName(){return m_playerName;}
protected:
    int m_playerId;
    std::string m_playerName;
    GameState*m_state;

};

