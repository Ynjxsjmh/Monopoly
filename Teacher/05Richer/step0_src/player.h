///======================================================================
///  Project:   Richer03
/// FileName:	player.h
///     Desc:   Richer 02
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
private:
    deque<Player*> players;
};


class Player
{
public:
    Player() {}
    virtual ~Player() {}
    virtual bool play(bool showed = true) = 0;
public:
    const string& name() const { return strName;}
    void setName(const string& str);
protected:
    string strName;
};

class AutoPlayer: public Player
{
public:
    AutoPlayer() {}
    virtual ~AutoPlayer() {}
    virtual bool play(bool showed = true);
};
class HumanPlayer: public Player
{
public:
    HumanPlayer() {}
    virtual ~HumanPlayer() {}
    virtual bool play(bool showed = true);
};
#endif // PLAYER_H
