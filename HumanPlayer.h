#include"Player.h"
#include<string>
class HumanPlayer:public Player
{
public:
    HumanPlayer();
    HumanPlayer(const std::string&name);
    virtual ~HumanPlayer();
    virtual int getNextPosition();
};
