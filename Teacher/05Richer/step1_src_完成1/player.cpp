///======================================================================
///  Project:   Richer04
/// FileName:	player.cpp
///     Desc:   Richer 04
///   Author:	Chen Wei
///======================================================================
#include <iostream>
#include <string>
#include <deque>
using namespace std;
#include "player.h"
#include "menumgr.h"
#include "mapmgr.h"
#include "map.h"
#include "block.h"

Players& Players::getPlayers()
{
    static Players players;
    return players;
}
Player* Players::getFirst()
{
    return players.front();
}
Player* Players::getLast()
{
    return players.back();
}
Players::Players()
{
    //Player* ps[3] = {new HumanPlayer, new AutoPlayer, new AutoPlayer};
    //ps[0]->setName("111");
    //ps[1]->setName("222");
    //ps[2]->setName("333");
    Player* ps[2] = {new HumanPlayer, new AutoPlayer};
    ps[0]->setName("111");
    ps[1]->setName("222");
    ps[0]->setMoney(1000);
    ps[1]->setMoney(500);

    players.push_back(ps[0]);
    players.push_back(ps[1]);
    //players.push_back(ps[2]);
}

Players::~Players()
{
    while(players.size() > 0) {
        Player* player = players.front();
        delete player;
        players.pop_front();
    }
}

void Players::play(bool showed)
{
    Player* player = players.front();
    while(player->play(showed)) {
        showed = true;
        players.pop_front();
        players.push_back(player);
        player = players.front();
    }
}

///-----------------------------------------
Player::Player()
{
    stand = MapMgr::getMgr()->getCurMap()->getBlock(0);
    inDir = DirID::DIR_NONE;
    money = 0;
}
void Player::setName(const string& str)
{
    strName = str;
}
void Player::advance()
{
    int steps = caculateMoveSteps();
    while(steps > 0) {
        int destDir = stand->getDestDir(inDir);
        Block* destBlock = stand->getNeighbor(destDir);
        stand = destBlock;
        inDir = destDir;

        steps = destBlock->passBy(this, steps);
    }
}
///-----------------------------------------
bool AutoPlayer::play(bool showed)
{
    cout << "Name = " << name() << endl;
    advance();
    MapMgr::getMgr()->getCurMap()->show();
    return true;
}
int AutoPlayer::caculateMoveSteps()
{
    return 2;
}
///-----------------------------------------
bool HumanPlayer::play(bool showed)
{
    cout << "Name = " << name() << endl;
    if(showed) {
        MapMgr::getMgr()->getCurMap()->show();
        MenuMgr::getMgr()->setCurMenu(MenuID::PLAY_MENU);
        return false;
    } else {
        advance();
        MapMgr::getMgr()->getCurMap()->show();
        return true;
    }
}
int HumanPlayer::caculateMoveSteps()
{
    return 3;
}
