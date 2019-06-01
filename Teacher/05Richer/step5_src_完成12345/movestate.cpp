///======================================================================
///  Project:   Richer04
/// FileName:	movestate.cpp
///     Desc:   Richer04
///   Author:	Chen Wei
///======================================================================
#include "global.h"
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
    } else {
        throw "dsfsdfdsfdsfds";
    }
    result->setTurns(ts);
    return result;
}

///-----------------------------------------
int NormalState::caculateMoveSteps()
{
    return  player->getNormalSteps();
}

int FlyState::caculateMoveSteps()
{
    if(--turns <= 0) {
        MoveState* s = MoveState::createState(MoveStateID::MOVE_STATE_NORMAL);
        player->setMoveState(s);
    }
    return 6;
}
int FreezeState::caculateMoveSteps()
{
    if(--turns <= 0) {
        MoveState* s = MoveState::createState(MoveStateID::MOVE_STATE_NORMAL);
        player->setMoveState(s);
    }
    return 1;
}
