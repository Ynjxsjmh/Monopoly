///======================================================================
///  Project:   Richer02
/// FileName:	map.h
///     Desc:   Richer 02
///   Author:	Chen Wei
///======================================================================
#ifndef MAP_H
#define MAP_H

#include "global.h"

class MapImp;
class Block;
class Map
{
public:
    Map(MapImp * aImp);
    virtual ~Map();
    void show() const;
    void    addBlock(Block * block);
    Block * getBlock(int index);
    //void    setBlock(int r,int c,Block * block);
    //Block * getBlock(int r,int c) { return blocks[r][c];}
protected:
    MapImp * imp ;
};

#endif // MAP_H
