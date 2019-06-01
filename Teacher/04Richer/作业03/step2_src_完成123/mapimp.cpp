///======================================================================
///  Project:   Richer02
/// FileName:	mapimp.cpp
///     Desc:   Richer 01
///   Author:	Chen Wei
///======================================================================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "mapimp.h"
#include "block.h"

MapImp::MapImp()
{
    //ctor
}

MapImp::~MapImp()
{
    //dtor
}

void MapImp::addBlock(Block* block)
{
    blocks.push_back(block);
}
Block* MapImp::getBlock(int index)
{
    return blocks[index];
}
void MapImp::show() const
{
    vector<Block*> temps(blocks);
    sort(temps.begin(), temps.end(), [](Block * b1, Block * b2) {
        if(b1->getRow() == b2->getRow()) {
            return b1->getCol() < b2->getCol();
        } else {
            return b1->getRow() < b2->getRow();
        }
    });

    int row = 0;
    int col = 0;
    for(Block* block : temps) {
        int r = block->getRow();
        int c = block->getCol();
        for(int i = row; i < r; ++i) {
            cout << endl;
            col = 0;
        }
        for(int i = col; i < c; ++i) {
            cout << "  ";
        }
        cout << block->name()<<" ";
        row = r;
        col = c + 1;
    }
    cout << endl;
}
