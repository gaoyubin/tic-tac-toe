#pragma once
#include"Evaluator.h"
class FeEvaluator :public Evaluator
{

public:
    FeEvaluator();
    ~FeEvaluator();
    virtual int evaluate(GameState&state,int max_player_id); 
    void  countPlayerChess(GameState&state,int player_id,int& countOne,int& countTwo,int& countTree);
};
