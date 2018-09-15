#include"Player.h"
#include<string>
#include"Searcher.h"
class ComputerPlayer:public Player
{
public:
    ComputerPlayer();
    ComputerPlayer(const std::string&name);
    virtual ~ComputerPlayer();
    void setSearcher(Searcher* searcher,int depth);
    virtual int getNextPosition();
protected:
    Searcher* m_searcher;
    int m_depth;
};
