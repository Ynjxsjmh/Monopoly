///======================================================================
///  Project:   Richer02
/// FileName:	block.h
///     Desc:   Richer 02
///   Author:	Chen Wei
///======================================================================
#ifndef BLOCK_H
#define BLOCK_H

#include "global.h"
class Player;
class Block
{
public:
    Block(){}
    virtual ~Block(){}
    virtual const char* name() const = 0;
    virtual Block* clone() = 0;
    void setPosition(int r, int c) { row = r; col = c;}
    int getRow() const { return row;}
    int getCol() const { return col;}
    virtual Block* getNeighbor(int dir) { return this;}
public:
    virtual int passBy(Player * player,int steps) { return 0;}
protected:
    int row;
    int col;
};

class MoneyBlock: public Block
{
public:
    MoneyBlock() {}
    virtual ~MoneyBlock() {}
    virtual const char* name() const { return "A";}
    virtual MoneyBlock* clone() override;
    virtual int passBy(Player * player,int steps);
};
class TripBlock: public Block
{
public:
    static void setPenality(int n);
public:
    TripBlock() {}
    virtual ~TripBlock() {}
    virtual const char* name() const { return "B";}
    virtual TripBlock* clone() override;
    virtual int passBy(Player * player,int steps);
private:
    static int   penality;
};
class BarBlock: public Block
{
public:
    BarBlock() {}
    virtual ~BarBlock() {}
    virtual const char* name() const { return "C";}
    virtual BarBlock* clone() override;
    virtual int passBy(Player * player,int steps);
};
class SlideBlock: public Block
{
public:
    SlideBlock() {}
    virtual ~SlideBlock() {}
    virtual const char* name() const { return "D";}
    virtual SlideBlock* clone() override;
    virtual int passBy(Player * player,int steps);
};

class EBlock: public Block
{
public:
    EBlock() {}
    virtual ~EBlock() {}
    virtual const char* name() const { return "E";}
    virtual EBlock* clone() override;
};

class FBlock: public Block
{
public:
    FBlock() {}
    virtual ~FBlock() {}
    virtual const char* name() const { return "F";}
    virtual FBlock* clone() override;
};

///--------------------------------
class LinkedBlock:public Block
{
public:
    LinkedBlock(int kernelID);
    virtual ~LinkedBlock();
    virtual const char* name() const;
    virtual Block* clone();
    void setNeighbor(int dir,Block * b);
    Block* getNeighbor(int dir);
public:
    virtual int passBy(Player * player,int steps);
protected:
    Block * kernel;
    Block * neighbors[DirID::DIR_COUNT];
};
#endif // BLOCK_H
