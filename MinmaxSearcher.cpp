#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
#include"MinmaxSearcher.h"
#include"GameState.h"
MinmaxSearcher::MinmaxSearcher()
{

}

MinmaxSearcher::~MinmaxSearcher()
{

}

int MinmaxSearcher::searchBestPlay(const GameState&state,int depth)
{
    std::vector<int>bestCell;
    int bestValue=INT_MIN;
    int bestPos=0;
    for(int i=0;i<BOARD_CELLS;i++){
        GameState tryState=state;
        if(tryState.isEmptyCell(i)){
            tryState.setGameCell(i,tryState.getCurrentPlayer());
            tryState.switchPlayer();
            int value=minMaxAlphaBeta(tryState,depth-1,INT_MIN,INT_MAX,state.getCurrentPlayer());
            if(value>bestValue){
                bestValue=value;
                bestCell.clear();
                bestCell.push_back(i);
            }
            else if(value==bestValue){
                bestCell.push_back(i);
            }
                                      
        }
    }
    if(bestCell.size()>0){
        bestPos=rand()%bestCell.size();
    }
    std::cout<<bestPos<<std::endl;
    return bestCell[bestPos];
}

int MinmaxSearcher::minMaxAlphaBeta(GameState& state,int depth,int a,int b,int maxPlayerId)
{
    if(state.isGameOver() || depth==0){
        return state.evaluate(maxPlayerId);
    }

    for(int i=0;i<BOARD_CELLS;i++){
        GameState tryState=state;
        if(tryState.isEmptyCell(i)){
            tryState.setGameCell(i,tryState.getCurrentPlayer());
            tryState.switchPlayer();
            int value=minMaxAlphaBeta(tryState,depth-1,a,b,maxPlayerId);
            if(state.getCurrentPlayer()==maxPlayerId){
                a=std::max(a,value);
                if(a>=b)
                    return a;
            }
            else{
                b=std::min(b,value);
                if(a>=b)
                    return b;
            }

        }
    }
}

