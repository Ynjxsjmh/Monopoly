///======================================================================
///  Project:   Richer02
/// FileName:	map.cpp
///     Desc:   Richer 02
///   Author:	Chen Wei
///======================================================================
#include <iostream>
using namespace std;
#include "global.h"
#include "block.h"

#include "map.h"
#include "mapimp.h"

Map::Map(MapImp* aImp)
    : imp(aImp)
{
}

Map::~Map()
{
    delete imp;
}
void Map::addBlock(Block* block)
{
    imp->addBlock(block);
}
Block* Map::getBlock(int index)
{
    return imp->getBlock(index);
}
void Map::show() const
{
    imp->show();
    /**
    for(int r = 0; r < BlockID::BLOCK_ROWS; ++r) {
        cout << endl;
        for(int c = 0; c < BlockID::BLOCK_COLS; ++c) {
            Block* block = blocks[r][c];
            if(block) {
                cout << block->name() << " ";
            } else {
                cout << "  ";
            }
        }
    }
    cout << endl;
    **/
}
