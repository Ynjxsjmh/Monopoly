///======================================================================
///  Project:   Richer04
/// FileName:	movestate.cpp
///     Desc:   Richer04
///   Author:	Chen Wei
///======================================================================
#include "global.h"
#include "block.h"
#include "movestate.h"
#include "player.h"

MoveState* MoveState::createState(int moveStateID, int ts)
{
    MoveState* result = nullptr;
    if(moveStateID == MoveStateID::MOVE_STATE_NORMAL) {
        result = new NormalState;
    } else if(moveStateID == MoveStateID::MOVE_STATE_FLY) {
        result = new FlyState;
    } else if(moveStateID == MoveStateID::MOVE_STATE_FREEZE) {
        result = new FreezeState;
    } else if(moveStateID == MoveStateID::MOVE_STATE_EXFLY) {
        result = new ExFlyState;
    } else {
        throw "dsfsdfdsfdsfds";
    }
    result->setTurns(ts);
    return result;
}
int MoveState::passBy(Player* p, Block* b, int steps)
{
    return b->passBy(p,steps);
}
///-----------------------------------------
int NormalState::caculateMoveSteps()
{
    return  player->getNormalSteps();
}

int FlyState::caculateMoveSteps()
{
    return 6;
}
void  FlyState::toggleState()
{
    if(--turns <= 0) {
        MoveState* s = MoveState::createState(MoveStateID::MOVE_STATE_NORMAL);
        player->setMoveState(s);
    }
}
int FreezeState::caculateMoveSteps()
{
    return 1;
}
void  FreezeState::toggleState()
{
    if(--turns <= 0) {
        MoveState* s = MoveState::createState(MoveStateID::MOVE_STATE_NORMAL);
        player->setMoveState(s);
    }
}
///-----------------------------------------
int ExFlyState::caculateMoveSteps()
{
    return 6;
}
void  ExFlyState::toggleState()
{
    if(--turns <= 0) {
        MoveState* s = MoveState::createState(MoveStateID::MOVE_STATE_NORMAL);
        player->setMoveState(s);
    }
}
int ExFlyState::passBy(Player* p, Block* b, int steps)
{
    return --steps;
}
