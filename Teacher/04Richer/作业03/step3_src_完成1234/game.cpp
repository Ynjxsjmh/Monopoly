///======================================================================
///  Project:   Richer02
/// FileName:	game.cpp
///     Desc:   Richer 01
///   Author:	Chen Wei
///======================================================================
#include "global.h"

#include "game.h"
#include "menu.h"
#include "menumgr.h"
#include "menufactory.h"
#include "blockmgr.h"
#include "map.h"
#include "mapmgr.h"

Game* Game::game = nullptr;

Game* Game::getGame()
{
    if(game == nullptr) {
        game = new Game;
    }
    return game;
}
void  Game::releaseGame()
{
    delete game;
    game = nullptr;
}

void Game::init()
{
    MenuMgr::getMgr()->setMenuFactory(new MenuFactory);
    MenuMgr::getMgr()->setCurMenu(MenuID::MAIN_MENU);
    MapMgr::getMgr()->createMap();
}
void Game::run()
{
    bool running = true;
    while(running) {
        running = MenuMgr::getMgr()->getCurMenu()->process();
    }
}
void Game::term()
{
    MenuMgr::releaseMgr();
    MapMgr::releaseMgr();
    BlockMgr::releaseMgr();
}

/**
void Game::createMap()
{
    delete curMap;
    curMap = nullptr;

    //MapBuilder* builder = new MapBuilder;
    //MapDirector* director = new MapDirector(builder);
    MapBuilder* builder = new EFMapBuilder;
    MapDirector* director = new SunMapDirector(builder);

    director->makeMap();
    curMap = director->getMap();
    delete director;
    delete builder;
**/

    /**
    curMap = new Map;

    int layout[BlockID::BLOCK_ROWS][BlockID::BLOCK_COLS] = {
        {1, 1, 1, 1, 1},
        {2, 0, 0, 0, 2},
        {3, 0, 0, 0, 3},
        {4, 0, 0, 0, 4},
        {1, 1, 1, 1, 1}
    };

    BlockFactory* blockFac  = new BlockFactory;
    for(int r = 0; r < BlockID::BLOCK_ROWS; ++r) {
        for(int c = 0; c < BlockID::BLOCK_COLS; ++c) {
            curMap->setBlock(r, c, blockFac->createBlock(layout[r][c]));
        }
    }
    delete blockFac;
    **/
//}

