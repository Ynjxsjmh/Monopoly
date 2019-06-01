///======================================================================
///  Project:   Richer02
/// FileName:	mapdirector.cpp
///     Desc:   Richer 02
///   Author:	Chen Wei
///======================================================================
#include "global.h"
#include "map.h"
#include "mapbuilder.h"
#include "mapdirector.h"
#include "mapimp.h"
#include "block.h"
MapDirector::MapDirector(MapBuilder* aBuilder)
    : builder(aBuilder)
{
    //ctor
}

MapDirector::~MapDirector()
{
    //dtor
}

void MapDirector::makeMap()
{
    aMap = new Map(new MapImp);

    int layout[BlockID::BLOCK_ROWS][BlockID::BLOCK_COLS] = {
        {1, 1, 1, 1, 1},
        {2, 0, 0, 0, 2},
        {3, 0, 0, 0, 3},
        {4, 0, 0, 0, 4},
        {1, 1, 1, 1, 1}
    };

    for(int r = 0; r < BlockID::BLOCK_ROWS; ++r) {
        for(int c = 0; c < BlockID::BLOCK_COLS; ++c) {
            if(layout[r][c] != BlockID::NONE_BLOCK) {
                Block* block = builder->buildBlock(layout[r][c]);
                block->setPosition(r,c);
                aMap->addBlock(block);
            }
        }
    }
}

Map* MapDirector::getMap()
{
    return aMap;
}
///-----------------------------------------
SunMapDirector::SunMapDirector(MapBuilder* aBuilder)
    : MapDirector(aBuilder)
{
}

void SunMapDirector::makeMap()
{
    aMap = new Map(new MapImp);

    int layout[BlockID::BLOCK_ROWS][BlockID::BLOCK_COLS] = {
        {1, 1, 1, 1, 1},
        {2, 0, 0, 0, 2},
        {3, 3, 3, 3, 3},
        {4, 0, 0, 0, 4},
        {1, 1, 1, 1, 1}
    };

    for(int r = 0; r < BlockID::BLOCK_ROWS; ++r) {
        for(int c = 0; c < BlockID::BLOCK_COLS; ++c) {
            if(layout[r][c] != BlockID::NONE_BLOCK) {
                Block* block = builder->buildBlock(layout[r][c]);
                block->setPosition(r,c);
                aMap->addBlock(block);
            }
        }
    }
}

