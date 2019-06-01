///======================================================================
///  Project:   Richer04
/// FileName:	movestate.h
///     Desc:   Richer04
///   Author:	Chen Wei
///======================================================================
#ifndef MOVESTATE_H
#define MOVESTATE_H

class Player;
class MoveState
{
public:
    static MoveState* createState(int moveStateID, int ts = 1);
public:
    MoveState() {}
    virtual ~MoveState() {}
    virtual int caculateMoveSteps() = 0;
    void  setPlayer(Player* p) {player = p;}
    void  setTurns(int t) {turns = t;}
    Player* getPlayer() { return player;}
    int   getTurns() const { return turns;}
protected:
    Player* player;
    int      turns;
};

class NormalState: public MoveState
{
public:
    NormalState() {}
    virtual ~NormalState() {}
    virtual int caculateMoveSteps();
};

class FlyState: public MoveState
{
public:
    FlyState() {}
    virtual ~FlyState() {}
    virtual int caculateMoveSteps();
};
class FreezeState: public MoveState
{
public:
    FreezeState() {}
    virtual ~FreezeState() {}
    virtual int caculateMoveSteps();
};
#endif // MOVESTATE_H
