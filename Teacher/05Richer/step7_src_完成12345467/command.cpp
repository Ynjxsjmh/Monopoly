///======================================================================
///  Project:   Richer04
/// FileName:	command.cpp
///     Desc:   Richer04
///   Author:	Chen Wei
///======================================================================
#include "global.h"
#include "player.h"
#include "command.h"
#include "mapmgr.h"
#include "map.h"
#include "movestate.h"
#include "moneystate.h"
///-----------------------------------------
RobCardCommand::RobCardCommand(Player* src, Player* tgt)
    : source(src), target(tgt)
{
}
void RobCardCommand::excute()
{
    int other = target->getMoney();
    target->setMoney(other / 2);
    source->setMoney(source->getMoney() + other / 2);
}
///-----------------------------------------
void MeanCardCommand::excute()
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
FlyCardCommand::FlyCardCommand(Player* tgt)
    : target(tgt)
{
}
void FlyCardCommand::excute()
{
    MoveState* s = MoveState::createState(MoveStateID::MOVE_STATE_FLY, 2);
    target->setMoveState(s);
}
///-----------------------------------------
LuckCardCommand::LuckCardCommand(Player* tgt)
    : target(tgt)
{
}
void LuckCardCommand::excute()
{
    MoneyState* s = MoneyState::createState(MoneyStateID::MONEY_STATE_LUCK, 3);
    target->addMoneyState(s);
}
///-----------------------------------------
ExFlyCardCommand::ExFlyCardCommand(Player* tgt)
    : target(tgt)
{
}
void ExFlyCardCommand::excute()
{
    MoveState* s = MoveState::createState(MoveStateID::MOVE_STATE_EXFLY, 2);
    target->setMoveState(s);
}
///-----------------------------------------
SuperCardCommand::SuperCardCommand(Player* tgt)
    : target(tgt)
{
}
void SuperCardCommand::excute()
{
    MoveState* s = MoveState::createState(MoveStateID::MOVE_STATE_FLY, 1);
    target->setMoveState(s);

    MoneyState* s2 = MoneyState::createState(MoneyStateID::MONEY_STATE_LUCK, 1);
    target->addMoneyState(s2);
}
///-----------------------------------------
ReturnSpellCommand::ReturnSpellCommand(Player* tgt)
    : target(tgt)
{
}
void ReturnSpellCommand::excute()
{
    target->setInDir(DirID::DIR_NONE);
    target->setStand(MapMgr::getMgr()->getCurMap()->getBlock(0));
}
///-----------------------------------------
FreezeSpellCommand::FreezeSpellCommand(Player* tgt)
    : target(tgt)
{
}
void FreezeSpellCommand::excute()
{
    MoveState* s = MoveState::createState(MoveStateID::MOVE_STATE_FREEZE, 3);
    target->setMoveState(s);
}
///-----------------------------------------
HurtSpellCommand::HurtSpellCommand(Player* tgt)
    : target(tgt)
{
}
void HurtSpellCommand::excute()
{
    MoneyState* s = MoneyState::createState(MoneyStateID::MONEY_STATE_HURT, 2);
    target->addMoneyState(s);
}

