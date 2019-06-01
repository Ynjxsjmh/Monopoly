///======================================================================
///  Project:   Richer04
/// FileName:	moneystate.h
///     Desc:   Richer04
///   Author:	Chen Wei
///======================================================================
#ifndef MONEYSTATE_H
#define MONEYSTATE_H

class Player;
class MoneyState
{
public:
    static MoneyState* createState(int moneyStateID, int ts = 1);
public:
    MoneyState() {}
    virtual ~MoneyState() {}
    virtual int moneyChanged() { return 0;}
public:
    void  setPlayer(Player* p) {player = p;}
    void  setTurns(int t) {turns = t;}
    Player* getPlayer() { return player;}
    int   getTurns() const { return turns;}
protected:
    Player* player;
    int      turns;
};
class HurtMoneyState: public MoneyState
{
public:
    HurtMoneyState() {}
    virtual ~HurtMoneyState() {}
    virtual int moneyChanged() { --turns; return -5;}
};
class LuckMoneyState: public MoneyState
{
public:
    LuckMoneyState() {}
    virtual ~LuckMoneyState() {}
    virtual int moneyChanged() { --turns; return 200;}
};

#endif // MONEYSTATE_H
