///======================================================================
///  Project:   Richer04
/// FileName:	dirstrategy.h
///     Desc:   Richer04
///   Author:	Chen Wei
///======================================================================
#ifndef DIRSTRATEGY_H
#define DIRSTRATEGY_H

class Player;
class DirStrategy
{
public:
    static DirStrategy& getDirStrategy(int strategyID);
public:
    DirStrategy(){}
    virtual ~DirStrategy(){}
    virtual int getDestDir(Player* player) = 0;
};

class RandomStrategy:public DirStrategy
{
public:
    RandomStrategy(){}
    virtual ~RandomStrategy(){}
    virtual int getDestDir(Player* player);
};

class UserStrategy1:public DirStrategy
{
public:
    UserStrategy1(){}
    virtual ~UserStrategy1(){}
    virtual int getDestDir(Player* player);
};
#endif // DIRSTRATEGY_H
