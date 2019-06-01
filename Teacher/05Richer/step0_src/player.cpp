///======================================================================
///  Project:   Richer03
/// FileName:	player.cpp
///     Desc:   Richer 02
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
Players& Players::getPlayers()
{
    static Players players;
    return players;
}

Players::Players()
{
    Player* ps[3] = {new HumanPlayer, new AutoPlayer, new AutoPlayer};
    ps[0]->setName("111");
    ps[1]->setName("222");
    ps[2]->setName("333");

    players.push_back(ps[0]);
    players.push_back(ps[1]);
    players.push_back(ps[2]);
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
void Player::setName(const string& str)
{
    strName = str;
}
///-----------------------------------------
bool AutoPlayer::play(bool showed)
{
    cout<<"Name = "<<name()<<endl;
    MapMgr::getMgr()->getCurMap()->show();
    return true;
}
///-----------------------------------------
bool HumanPlayer::play(bool showed)
{
    cout<<"Name = "<<name()<<endl;
    if(showed) {
        MapMgr::getMgr()->getCurMap()->show();
        MenuMgr::getMgr()->setCurMenu(MenuID::PLAY_MENU);
        return false;
    } else {
        MapMgr::getMgr()->getCurMap()->show();
        return true;
    }
}
