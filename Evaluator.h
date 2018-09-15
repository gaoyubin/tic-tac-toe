#pragma once
class GameState;
class Evaluator
{
public:
    Evaluator(){}
    virtual ~Evaluator(){}
    virtual int evaluate(GameState&state,int max_player_id)=0;
};
