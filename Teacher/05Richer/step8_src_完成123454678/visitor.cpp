///======================================================================
///  Project:   Richer04
/// FileName:	visitor.cpp
///     Desc:   Richer04
///   Author:	Chen Wei
///======================================================================
#include "global.h"
#include "player.h"
#include "visitor.h"
#include "moneystate.h"
#include "gender.h"
void  LuckVisitor::visitMale(Male* male)
{
    MoneyState* s = MoneyState::createState(MoneyStateID::MONEY_STATE_LUCK, 3);
    male->getPlayer()->addMoneyState(s);
    male->addPower(22);
}
void  LuckVisitor::visitFemale(Female* female)
{
    MoneyState* s = MoneyState::createState(MoneyStateID::MONEY_STATE_LUCK, 4);
    female->getPlayer()->addMoneyState(s);
    female->addBeauty(100);
}
