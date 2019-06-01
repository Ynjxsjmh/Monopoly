///======================================================================
///  Project:   Richer04
/// FileName:	block.cpp
///     Desc:   Richer 04
///   Author:	Chen Wei
///======================================================================
#include <vector>
#include <random>
using namespace std;
#include "block.h"
#include "blockmgr.h"
#include "player.h"
Block::Block()
{
    //ctor
}

Block::~Block()
{
    //dtor
}
int Block::getDestDir(int inDir)
{
    return DirID::DIR_NONE;
}

///-----------------------------------------

MoneyBlock* MoneyBlock::clone()
{
    return new MoneyBlock(*this);
}
int MoneyBlock::passBy(Player* player, int steps)
{
    if(steps == 1) {
        player->addMoney(50);
    }
    return --steps;
}
///-----------------------------------------
TripBlock* TripBlock::clone()
{
    return new TripBlock(*this);
}
int TripBlock::passBy(Player* player, int steps)
{
    if(steps == 1) {
        player->reduceMoney(100);
    }
    return --steps;
}
///-----------------------------------------

BarBlock* BarBlock::clone()
{
    return new BarBlock(*this);
}
int BarBlock::passBy(Player* player, int steps)
{
    return 0;
}
///-----------------------------------------

SlideBlock* SlideBlock::clone()
{
    return new SlideBlock(*this);
}

int SlideBlock::passBy(Player* player, int steps)
{
    if(steps == 1) {
        steps += 2;
    }
    return --steps;
}
///-----------------------------------------

EBlock* EBlock::clone()
{
    return new EBlock(*this);
}

FBlock* FBlock::clone()
{
    return new FBlock(*this);
}
///--------------------------------

LinkedBlock::LinkedBlock(int kernelID)
{
    kernel = BlockMgr::getMgr()->cloneBlock(kernelID);
    for(int dir = DirID::DIR_NONE; dir < DirID::DIR_COUNT; ++dir) {
        neighbors[dir] = nullptr;
    }
}
LinkedBlock::~LinkedBlock()
{
    delete kernel;
}
const char* LinkedBlock::name() const
{
    return kernel->name();
}

Block* LinkedBlock::clone()
{
    LinkedBlock* newOne = new LinkedBlock(*this);
    newOne->kernel = kernel->clone();
    for(int dir = DirID::DIR_NONE; dir < DirID::DIR_COUNT; ++dir) {
        neighbors[dir] = nullptr;
    }
    return newOne;
}
void LinkedBlock::setNeighbor(int dir, Block* b)
{
    if(dir > DirID::DIR_NONE && dir < DirID::DIR_COUNT) {
        neighbors[dir] = b;
    }
}
Block* LinkedBlock::getNeighbor(int dir)
{
    return neighbors[dir];
}
int LinkedBlock::getDestDir(int inDir)
{
    vector<int> dirs;
    for(int dir = DirID::DIR_NONE + 1; dir < DirID::DIR_COUNT; ++dir) {
        if(neighbors[dir] && dir != DirID::oppositeDir(inDir)) {
            dirs.push_back(dir);
        }
    }
    if(dirs.empty()) {
        return DirID::oppositeDir(inDir);
    } else {
        return dirs.at(rand() % dirs.size());
    }
}
int LinkedBlock::passBy(Player* player, int steps)
{
    return kernel->passBy(player, steps);
}
