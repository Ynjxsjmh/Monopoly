///======================================================================
///  Project:   Richer04
/// FileName:	gender.h
///     Desc:   Richer04
///   Author:	Chen Wei
///======================================================================
#ifndef GENDER_H
#define GENDER_H

class Visitor;
class Player;
class Gender
{
public:
    Gender() {}
    virtual ~Gender() {}
    void setPlayer(Player * p){ player = p;}
    Player * getPlayer() { return player;}
    virtual void accept(Visitor& v) = 0;
private:
    Player * player;
};
class Male: public Gender
{
public:
    Male() {}
    virtual ~Male() {}
    virtual void accept(Visitor& v) ;
public:
    void addPower(int n){}
};
class Female: public Gender
{
public:
    Female() {}
    virtual ~Female() {}
    virtual void accept(Visitor& v) ;
public:
    void addBeauty(int n){}
};
#endif // GENDER_H
