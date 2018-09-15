#pragma once
#include"GameState.h"
class Searcher{
public:
    virtual int searchBestPlay(const GameState&state,int depth)=0;
};
