#include"Searcher.h"
class MinmaxSearcher : public Searcher
{
public:
    MinmaxSearcher();
    virtual ~MinmaxSearcher();
    virtual int searchBestPlay(const GameState&state,int depth);
    int minMaxAlphaBeta(const GameState& state,int depth,int a,int b,int maxPlayerId);
        
};
