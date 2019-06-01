///======================================================================
///  Project:   Richer04
/// FileName:	player.h
///     Desc:   Richer 04
///   Author:	Chen Wei
///======================================================================
#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <string>
#include <deque>
using namespace std;
class Player;

class Players
{
    friend class CppPlayerIterator;
    friend class JavaPlayerIterator;
public:
    static Players& getPlayers();
private:
    Players();
    Players(const Players&);
    Players& operator=(const Players&);
public:
    virtual ~Players();
    virtual void play(bool showed = true);
    int count() const { return vctPlayers.size();}
    Player*  getPlayer(int index)  { return vctPlayers[index];}
    Player* curPlayer()            { return players.front();}
private:
    vector<Player*> vctPlayers;
    deque<Player*> players;

};

class CppIterator
{
public:
    CppIterator() {}
    virtual ~CppIterator() {}
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isLast() const = 0;
    virtual void* current() = 0;
    virtual int count() const = 0;
};

class CppPlayerIterator: public CppIterator
{
public:
    CppPlayerIterator(Players* ps);
    virtual ~CppPlayerIterator() {}
    virtual void first();
    virtual void next();
    virtual bool isLast() const ;
    virtual Player* current();
    virtual int count() const;
private:
    vector<Player*> vctPlayers;
    int index;
    int total;
};
///-----------------------------------------
class JavaIterator
{
public:
    JavaIterator() {}
    virtual ~JavaIterator() {}
    virtual void* next() = 0;
    virtual bool hasNext() const = 0;
    virtual int count() const = 0;
};
class JavaPlayerIterator: public JavaIterator
{
public:
    JavaPlayerIterator(Players* ps);
    virtual ~JavaPlayerIterator() {}
    virtual Player* next();
    virtual bool hasNext() const;
    virtual int count() const;
private:
    vector<Player*> vctPlayers;
    int index;
    int total;
};
class JavaPlayerIterator2: public JavaIterator
{
public:
    JavaPlayerIterator2(Players* ps);
    virtual ~JavaPlayerIterator2() {}
    virtual Player* next();
    virtual bool hasNext() const;
    virtual int count() const;
private:
    //vector<Player*> vctPlayers;
    Players* players;
    int index;
    int total;
};
///-----------------------------------------
class Block;
class DirStrategy;
class Command;
class MoveState;
class MoneyState;
class Player
{
public:
    Player();
    virtual ~Player();
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
    void  setDirStrategy(DirStrategy* s) { strategy = s;}
    void setMoveState(MoveState* aState);
    void checkMoneyStates();
    void addMoneyState(MoneyState * s);
    void removeMoneyState(MoneyState * s);
public:
    virtual void advance();
    virtual void apply(Command* cmd);
    virtual int  getNormalSteps() = 0;
protected:
    string strName;
    Block* stand;
    int    inDir;
    int    money;
    DirStrategy* strategy;
    MoveState*   state;
    vector<MoneyState*>  moneyStates;
};

class AutoPlayer: public Player
{
public:
    AutoPlayer() {}
    virtual ~AutoPlayer() {}
    virtual bool play(bool showed = true);
    virtual int getNormalSteps() { return 2;}
};
class HumanPlayer: public Player
{
public:
    HumanPlayer() {}
    virtual ~HumanPlayer() {}
    virtual bool play(bool showed = true);
    virtual int getNormalSteps() { return 3;}
};
#endif // PLAYER_H
