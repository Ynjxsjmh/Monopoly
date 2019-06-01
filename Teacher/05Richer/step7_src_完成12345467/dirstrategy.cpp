///======================================================================
///  Project:   Richer04
/// FileName:	dirstrategy.cpp
///     Desc:   Richer04
///   Author:	Chen Wei
///======================================================================
#include <iostream>
#include <vector>
#include <random>
using namespace std;
#include "global.h"
#include "block.h"
#include "player.h"
#include "dirstrategy.h"

///-----------------------------------------
DirStrategy& DirStrategy::getDirStrategy(int strategyID)
{
    if(strategyID == StrategyID::STRATEGY_RANDOM) {
        static RandomStrategy strategy;
        return strategy;
    } else if(strategyID == StrategyID::STRATEGY_USER1) {
        static UserStrategy1 strategy;
        return strategy;
    }
}

///-----------------------------------------
int RandomStrategy::getDestDir(Player* player)
{
    Block* stand = player->getStand();
    int inDir = player->getInDir();

    vector<int> dirs;
    for(int dir = DirID::DIR_NONE + 1; dir < DirID::DIR_COUNT; ++dir) {
        if(stand->getNeighbor(dir) && dir != inDir) {
            dirs.push_back(dir);
        }
    }
    if(dirs.empty()) {
        return inDir;
    } else {
        return dirs.at(rand() % dirs.size());
    }
}

int UserStrategy1::getDestDir(Player* player)
{
    Block* stand = player->getStand();
    int inDir = player->getInDir();

    ///所有可能的前进方向
    vector<int> dirs;
    for(int dir = DirID::DIR_NONE + 1; dir < DirID::DIR_COUNT; ++dir) {
        if(stand->getNeighbor(dir) && dir != inDir) {
            dirs.push_back(dir);
        }
    }

    if(inDir == DirID::DIR_NONE) {
        if(dirs.empty()) {
            return inDir;
        } else {
            return dirs.at(rand() % dirs.size());
        }
    } else {
        int dirCount = dirs.size();
        int directDir = DirID::oppositeDir(inDir);
        int leftDir  = DirID::leftDir(inDir);
        int rightDir = DirID::rightDir(inDir);
        int probality = rand() % 100 + 1; ///[1,100]

        if(dirCount == 3) {
            cout<<"probality="<<probality<<endl;
            if(probality <= 50) {
                return directDir;
            } else if(probality <= 75) {
                return leftDir;
            } else {
                return rightDir;
            }
        } else  if(dirCount == 2) {
            if(stand->getNeighbor(directDir)) {
                ///可直行
                cout<<"probality="<<probality<<endl;
                if(probality <= 60) {
                    return directDir;
                } else {
                    ///....
                    return (stand->getNeighbor(leftDir)) ? leftDir : rightDir;
                }
            } else {
                ///只能转弯
                return probality <= 50 ? leftDir : rightDir;
            }
        } else  if(dirCount == 1) {
            return dirs[0];
        } else  if(dirCount == 0) {
            return inDir;
        }
    }
}
