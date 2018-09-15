#include<iostream>
#include"ComputerPlayer.h"
#include"GameConst.h"
#include"HumanPlayer.h"
#include"GameState.h"
#include"MinmaxSearcher.h"
#include"FeEvaluator.h"
#include"GameControl.h"
int main(){
    
    MinmaxSearcher ms;
    ComputerPlayer computer("KA47");
    computer.setSearcher(&ms,SEARCH_DEPTH);
    HumanPlayer human("apple");
    FeEvaluator feFunc;
    GameState init_state;
    init_state.initGameState(PLAYER_A);

    init_state.setEvaluator(&feFunc);
    GameControl gc;
    gc.setPlayer(&computer,PLAYER_A);
    gc.setPlayer(&human,PLAYER_B);
    gc.initGameState(init_state);
    gc.run();


    return 1;

}
