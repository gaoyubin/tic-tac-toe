#include <iostream>
#include"FeEvaluator.h"
#include<limits.h>
#include"GameState.h"
FeEvaluator::FeEvaluator()
{

}

FeEvaluator::~FeEvaluator()
{

}

int FeEvaluator::evaluate(GameState&state,int max_player_id)
{
    int peer=getPeerPlayer(max_player_id);
    int aOne,aTwo,aThree,bOne,bTwo,bThree;
    countPlayerChess(state,max_player_id,aOne,aTwo,aThree);
    countPlayerChess(state,peer,bOne,bTwo,bThree);
    if(aThree>0)
        return INT_MAX;
    if(bThree>0)
        return INT_MIN;
    return (aTwo-bTwo)*DOUBLE_WEIGHT+(aOne-bOne);

}

void  FeEvaluator::countPlayerChess(GameState&state,int player_id,int& countOne,int& countTwo,int& countThree)
{
    countOne=countTwo=countThree=0;
    
    for(int i=0;i<LINE_DIRECTION;i++){
        int sameCount=0;
        int empty=0;
        for(int j=0;j<LINE_CELLS;j++){
            if(state.getGameCell(line_idx_tbl[i][j])==player_id)
                sameCount++;
            if(state.getGameCell(line_idx_tbl[i][j])==PLAYER_NULL)
                empty++;
        }    
        if(sameCount==1 && empty==2)
            countOne++;
        if(sameCount==2 && empty==1)
            countTwo++;
        if(sameCount==3 && empty==0)
            countThree++;
    }
}

