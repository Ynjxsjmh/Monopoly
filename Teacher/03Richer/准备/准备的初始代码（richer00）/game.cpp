///======================================================================
///  Project:   Richer00
/// FileName:	game.cpp
///     Desc:   Richer 00
///   Author:	Chen Wei
///======================================================================
#include "game.h"
#include "menu.h"

void Game::init()
{
    setCurMenu(MenuID::MAIN_MENU);
}
void Game::run()
{
    bool running = true;
    while(running) {
        running = curMenu->process();
    }
}
void Game::term()
{
    delete curMenu;
}
void Game::setCurMenu(int menuID)
{
    delete curMenu;
    if(menuID == MenuID::MAIN_MENU) {
        curMenu = new MainMenu;
    } else if(menuID == MenuID::LOAD_MENU) {
        curMenu = new LoadMenu;
    } else {
        curMenu = new MainMenu;
    }
}
