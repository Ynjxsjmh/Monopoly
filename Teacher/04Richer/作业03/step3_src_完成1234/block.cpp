///======================================================================
///  Project:   Richer02
/// FileName:	block.cpp
///     Desc:   Richer 02
///   Author:	Chen Wei
///======================================================================
#include "block.h"
#include "blockmgr.h"

Block::Block()
{
    //ctor
}

Block::~Block()
{
    //dtor
}
MoneyBlock* MoneyBlock::clone()
{
    return new MoneyBlock(*this);
}
TripBlock* TripBlock::clone()
{
    return new TripBlock(*this);
}
BarBlock* BarBlock::clone()
{
    return new BarBlock(*this);
}
SlideBlock* SlideBlock::clone()
{
    return new SlideBlock(*this);
}


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


