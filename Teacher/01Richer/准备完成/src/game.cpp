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
        running = curMenu->process(this);
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
    } else if(menuID == MenuID::PLAYERS_MENU) {
        curMenu = new PlayersMenu;
    } else if(menuID == MenuID::LOAD_MENU) {
        curMenu = new LoadMenu;
    } else if(menuID == MenuID::SAVE_MENU) {
        curMenu = new SaveMenu;
    } else if(menuID == MenuID::OPTION_MENU) {
        curMenu = new OptionMenu;
    } else if(menuID == MenuID::VOLUME_MENU) {
        curMenu = new VolumeMenu;
    } else if(menuID == MenuID::RESOLUTION_MENU) {
        curMenu = new ResolutionMenu;
    } else {
        curMenu = new MainMenu;
    }
}
