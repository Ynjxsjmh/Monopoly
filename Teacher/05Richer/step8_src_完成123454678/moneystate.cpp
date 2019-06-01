///======================================================================
///  Project:   Richer04
/// FileName:	moneystate.cpp
///     Desc:   Richer04
///   Author:	Chen Wei
///======================================================================
#include "global.h"
#include "moneystate.h"

MoneyState* MoneyState::createState(int moneyStateID, int ts )
{
    MoneyState* result = nullptr;
    if(moneyStateID == MoneyStateID::MONEY_STATE_HURT) {
        result = new HurtMoneyState;
    } else if(moneyStateID == MoneyStateID::MONEY_STATE_LUCK) {
        result = new LuckMoneyState;
    } else {
        throw "dsfsdfdsfdsfds";
    }
    result->setTurns(ts);
    return result;
}

