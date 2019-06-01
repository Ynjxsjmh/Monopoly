///======================================================================
///  Project:   Richer04
/// FileName:	player.cpp
///     Desc:   Richer 04
///   Author:	Chen Wei
///======================================================================
#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;
#include "player.h"
#include "menumgr.h"
#include "mapmgr.h"
#include "map.h"
#include "block.h"
#include "dirstrategy.h"
#include "command.h"
#include "movestate.h"
#include "moneystate.h"
#include "gender.h"
Players& Players::getPlayers()
{
    static Players players;
    return players;
}

Players::Players()
{
    //Player* ps[3] = {new HumanPlayer, new AutoPlayer, new AutoPlayer};
    //ps[0]->setName("111");
    //ps[1]->setName("222");
    //ps[2]->setName("333");
    Player* ps[2] = {new HumanPlayer, new AutoPlayer};
    ps[0]->setGender(new Male);
    ps[1]->setGender(new Female);

    autoCount = 1;
    humanCount = 1;

    ps[0]->setName("111");
    ps[1]->setName("222");
    ps[0]->setMoney(1000);
    ps[1]->setMoney(500);
    ps[0]->setDirStrategy(&DirStrategy::getDirStrategy(StrategyID::STRATEGY_USER1));
    ps[1]->setDirStrategy(&DirStrategy::getDirStrategy(StrategyID::STRATEGY_RANDOM));

    ps[0]->setMoveState(MoveState::createState(MoveStateID::MOVE_STATE_NORMAL));
    ps[1]->setMoveState(MoveState::createState(MoveStateID::MOVE_STATE_NORMAL));

    vctPlayers.push_back(ps[0]);
    vctPlayers.push_back(ps[1]);

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

        bool isBankrupt = (player->getMoney() <= 0);
        if(isBankrupt) {
            ///....
            removePlayer(player);
            break;
        }
        showed = true;
        players.pop_front();
        players.push_back(player);
        player = players.front();
    }

    if(humanCount <= 0) {
        /// return Main_menu
        cout << "LOST" << endl;
        MenuMgr::getMgr()->setCurMenu(MenuID::MAIN_MENU);
    } else if(autoCount <= 0) {
        cout << "WIN" << endl;
        MenuMgr::getMgr()->setCurMenu(MenuID::MAIN_MENU);
    }
}
void Players::removePlayer(Player* p)
{
    players.pop_front();
    vctPlayers.erase(find(vctPlayers.begin(), vctPlayers.end(), p));

    ///if(dynamic_cast<HumanPlayer*>(p)) {
    if(p->type() == PlayerTypeID::PLAYER_TYPE_HUMAN) {
        --humanCount;
    } else {
        --autoCount;
    }

    for(Player* player : vctPlayers) {
        player->setMoney(player->getMoney() / 2);
    }

    TripBlock::setPenality(200);

    delete p;
}
///-----------------------------------------
///
///-----------------------------------------
CppPlayerIterator::CppPlayerIterator(Players* ps)
{
    vctPlayers.assign((ps->players).begin(), (ps->players).end());
    index = 0;
    total = vctPlayers.size();
}
void CppPlayerIterator::first()
{
    index = 0;
}
void CppPlayerIterator::next()
{
    ++index;
}
bool CppPlayerIterator::isLast() const
{
    return index >= total;
}
Player* CppPlayerIterator::current()
{
    return vctPlayers[index];
}
int CppPlayerIterator::count() const
{
    return total;
}
///-----------------------------------------
///
///-----------------------------------------
JavaPlayerIterator::JavaPlayerIterator(Players* ps)
{
    vctPlayers.assign((ps->players).begin(), (ps->players).end());
    index = 0;
    total = vctPlayers.size();
}
Player* JavaPlayerIterator::next()
{
    return vctPlayers[index++];
}
bool JavaPlayerIterator::hasNext() const
{
    return index < total;
}
int JavaPlayerIterator::count() const
{
    return total;
}
///-----------------------------------------
///
///-----------------------------------------
JavaPlayerIterator2::JavaPlayerIterator2(Players* ps)
{
    //vctPlayers.assign((ps->players).begin(), (ps->players).end());
    players = ps;
    index = 0;
    total = players->count();
}
Player* JavaPlayerIterator2::next()
{
    return players->getPlayer(index++);
}
bool JavaPlayerIterator2::hasNext() const
{
    return index < total;
}
int JavaPlayerIterator2::count() const
{
    return total;
}

///-----------------------------------------
Player::Player()
{
    stand = MapMgr::getMgr()->getCurMap()->getBlock(0);
    inDir = DirID::DIR_NONE;
    money = 0;
}
Player::~Player()
{
    delete state;
    delete gender;
}
void Player::setGender(Gender* g)
{
    gender = g;
    gender->setPlayer(this);
}
void Player::setName(const string& str)
{
    strName = str;
}
void Player::setMoveState(MoveState* aState)
{
    delete state;
    state = aState;
    state->setPlayer(this);
}
void Player::advance()
{
    int steps = state->caculateMoveSteps();
    ///.....
    for(MoneyState* ms : moneyStates) {

        money += ms->moneyChanged();
    }

    while(steps > 0) {
        int destDir = strategy->getDestDir(this);
        Block* destBlock = stand->getNeighbor(destDir);
        stand = destBlock;
        inDir = DirID::oppositeDir(destDir);

        steps = state->passBy(this, destBlock, steps);
        //steps = destBlock->passBy(this, steps);
    }
    state->toggleState();
    checkMoneyStates();
}
void Player::checkMoneyStates()
{
    for(MoneyState* ms : moneyStates) {
        if(ms->getTurns() <= 0) {
            removeMoneyState(ms);
            delete ms;
        }
    }
}
void Player::addMoneyState(MoneyState* s)
{
    moneyStates.push_back(s);
}
void Player::removeMoneyState(MoneyState* s)
{
    moneyStates.erase(find(moneyStates.begin(), moneyStates.end(), s));
}
void Player::apply(Command* cmd)
{
    cmd->excute();
}
/**
void Player::applyRobCard(Player* target)
{
    int other = target->getMoney();
    target->setMoney(other / 2);
    setMoney(money + other / 2);
}

void Player::applyMeanCard()
{
    int sum = 0;
    JavaPlayerIterator2 it(&Players::getPlayers());
    while(it.hasNext()) {
        sum += it.next()->getMoney();
    }

    JavaPlayerIterator2 it2(&Players::getPlayers());
    int num = it2.count();
    while(it2.hasNext()) {
        it2.next()->setMoney(sum / num);
    }
}

void Player::applyReturnSpell(Player* target)
{
    target->setInDir(DirID::DIR_NONE);
    target->setStand(MapMgr::getMgr()->getCurMap()->getBlock(0));
}
*/
///-----------------------------------------
bool AutoPlayer::play(bool showed)
{
    cout << "Name= " << name() << "\tMoney(Before)=" << money << endl;
    advance();
    MapMgr::getMgr()->getCurMap()->show();
    cout << "Name= " << name() << "\tMoney(After)=" << money << endl;
    return true;
}

///-----------------------------------------
bool HumanPlayer::play(bool showed)
{
    cout << "Name= " << name() << "\tMoney(Before)=" << money << endl;
    if(showed) {
        MapMgr::getMgr()->getCurMap()->show();
        MenuMgr::getMgr()->setCurMenu(MenuID::PLAY_MENU);
        return false;
    } else {
        advance();
        MapMgr::getMgr()->getCurMap()->show();
        cout << "Name= " << name() << "\tMoney(After)=" << money << endl;
        return true;
    }
}

