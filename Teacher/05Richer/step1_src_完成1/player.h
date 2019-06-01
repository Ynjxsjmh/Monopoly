///======================================================================
///  Project:   Richer04
/// FileName:	player.h
///     Desc:   Richer 04
///   Author:	Chen Wei
///======================================================================
#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <deque>
using namespace std;
class Player;

class Players
{
public:
    static Players& getPlayers();
private:
    Players();
    Players(const Players&);
    Players& operator=(const Players&);
public:
    virtual ~Players();
    virtual void play(bool showed = true);
    Player * getFirst();
    Player * getLast();
private:
    deque<Player*> players;

};


class Block;
class Player
{
public:
    Player();
    virtual ~Player() {}
    virtual bool play(bool showed = true) = 0;
public:
    const string& name() const { return strName;}
    void setName(const string& str);
    void setStand(Block* b) { stand = b;}
    Block* getStand()       { return stand;}
    void  setInDir(int dir) { inDir = dir;}
    int   getInDir() const  { return inDir;}
    void  addMoney(int n)   { money += n;}
    void  reduceMoney(int n) { money -= n;}
    int   getMoney() const  { return money;}
    void  setMoney(int n)   {  money = n;}
    virtual void advance();
protected:
    virtual int caculateMoveSteps() { return 1;}
protected:
    string strName;
    Block* stand;
    int    inDir;
    int    money;
};

class AutoPlayer: public Player
{
public:
    AutoPlayer() {}
    virtual ~AutoPlayer() {}
    virtual bool play(bool showed = true);
protected:
    virtual int caculateMoveSteps();
};
class HumanPlayer: public Player
{
public:
    HumanPlayer() {}
    virtual ~HumanPlayer() {}
    virtual bool play(bool showed = true);
protected:
    virtual int caculateMoveSteps();
};
#endif // PLAYER_H
