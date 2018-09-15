#pragma once
#include"GameConst.h"
#include"Evaluator.h"
class GameState
{
public:
    GameState() {}
    ~GameState() {}
    void setCurrentPlayer(int player_id){m_playerId=player_id;}
    int getCurrentPlayer() const{return m_playerId;}
    //int setGameCell
    int evaluate(int max_player_id);
    int getWinner();
    void initGameState(int firstPlayer);
    void setEvaluator(Evaluator*evaluator){m_evaluator=evaluator;}
    bool isGameOver(); 
    int countThreeLine(int player_id);
    void setGameCell(int cell,int player_id);
    void printGame();
    char getCellType(int player_id);
    void switchPlayer();
    bool isEmptyCell(int)const;
    int getGameCell(int cell){return m_board[cell];}
private:
    Evaluator*m_evaluator;
    int m_playerId;
    int m_board[BOARD_CELLS];
};

