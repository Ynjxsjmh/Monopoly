///======================================================================
///  Project:   Richer02
/// FileName:	menu.cpp
///     Desc:   Richer 02
///   Author:	Chen Wei
///======================================================================
#include <iostream>
#include <sstream>
#include <windows.h>
using namespace std;

#include "global.h"
#include "menu.h"
#include "menumgr.h"
#include "map.h"
#include "mapmgr.h"
#include "game.h"
#include "block.h"
#include "blockmgr.h"
#include "outdevice.h"
#include "player.h"
#include "command.h"
bool Menu::process(const OutDevice& dev)
{
    //OutDevice& dev = OutDevice::getTabConsole();
    show(dev);
    int choice = getChoice();
    return doChoice(choice, dev);
}
int  Menu::getChoice() const
{
    int choice = 0;
    cin >> choice;
    return choice;
}
///-----------------------------------------
void MainMenu::show(const OutDevice& dev) const
{
    dev.drawLn();
    dev.drawLn("\t主菜单");
    dev.drawLn("1: New");
    dev.drawLn("2: Load");
    dev.drawLn("3: Option");
    dev.drawLn("4: Play...");
    dev.drawLn("5: Change To EF");
    dev.drawLn("0: Exit");
    dev.draw(" Your selected:");
}

bool MainMenu::doChoice(int choice, const OutDevice& dev)
{
    switch(choice) {
    case 1:
        MenuMgr::getMgr()->setCurMenu(MenuID::PLAYERS_MENU);
        break;
    case 2:
        MenuMgr::getMgr()->setCurMenu(MenuID::LOAD_MENU);
        break;
    case 3:
        MenuMgr::getMgr()->setCurMenu(MenuID::OPTION_MENU);
        break;
    case 4:
        dev.drawLn("Playing ....");
        Players::getPlayers().play();
        //MapMgr::getMgr()->getCurMap()->show();
        break;
    case 5:
        BlockMgr::getMgr()->setPrototype(BlockID::MONEY_BLOCK, new EBlock);
        BlockMgr::getMgr()->setPrototype(BlockID::BAR_BLOCK, new FBlock);
        ///Game::getGame()->createMap();
        MapMgr::getMgr()->createMap();
        break;
    default:
        return false;
    }
    return true;
}

///------玩家人数菜单--------------------------------
void PlayersMenu::show(const OutDevice& dev) const
{
    dev.drawLn();
    dev.drawLn("\tSet number of players(2-8):");
    dev.drawLn("2. 2");
    dev.drawLn("3. 3");
    dev.drawLn("4. 4");
    dev.drawLn("5. 5");
    dev.drawLn("6. 6");
    dev.drawLn("7. 7");
    dev.drawLn("8. 8");
    dev.draw(" Your selected:");
}
bool PlayersMenu::doChoice(int choice, const OutDevice& dev)
{
    switch(choice) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        dev.drawLn("Set Players count");
        break;
    default:
        MenuMgr::getMgr()->setCurMenu(MenuID::MAIN_MENU);
    }
    return true;
}
///-------载入菜单----------------------------------
void LoadingMenu::show(const OutDevice& dev) const
{
    dev.drawLn();
    dev.drawLn("\tSelect the Record to be loaded(1-5):");
    dev.drawLn("1. 1");
    dev.drawLn("2. 2");
    dev.drawLn("3. 3");
    dev.drawLn("4. 4");
    dev.drawLn("5. 5");
    dev.drawLn("0. Back");
    dev.draw(" Your selected:");
}

bool LoadingMenu::doChoice(int choice, const OutDevice& dev)
{
    switch(choice) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        dev.drawLn("Load Recording...");
        ///执行players....
        Players::getPlayers().play();
        break;
    default:
        MenuMgr::getMgr()->setCurMenu(MenuID::MAIN_MENU);
    }
    return true;
}
///-------保存菜单----------------------------------
void SaveMenu::show(const OutDevice& dev) const
{
    dev.drawLn();
    dev.drawLn("\tSelect the Record to save(1-5):");
    dev.drawLn("1. 1");
    dev.drawLn("2. 2");
    dev.drawLn("3. 3");
    dev.drawLn("4. 4");
    dev.drawLn("5. 5");
    dev.drawLn("0. Back");
    dev.draw(" Your selected:");
}
bool SaveMenu::doChoice(int choice, const OutDevice& dev)
{
    switch(choice) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        dev.drawLn("Save Recording...");
        break;
    default:
        break;
    }
    MenuMgr::getMgr()->setCurMenu(MenuID::PLAY_MENU);
    return true;
}

///-------选项菜单----------------------------------
void OptionMenu::show(const OutDevice& dev) const
{
    dev.drawLn();
    dev.drawLn("\tSet options :");
    dev.drawLn("1.Set the value of Volume(0-100)");
    dev.drawLn("2.Set the resolution");
    dev.drawLn("0. Back");
    dev.draw(" Your selected:");
}
bool OptionMenu::doChoice(int choice, const OutDevice& dev)
{
    switch(choice) {
    case 1:
        MenuMgr::getMgr()->setCurMenu(MenuID::VOLUME_MENU);
        break;
    case 2:
        MenuMgr::getMgr()->setCurMenu(MenuID::RESOLUTION_MENU);
        break;
    default:
        MenuMgr::getMgr()->setCurMenu(MenuID::MAIN_MENU);
        break;
    }
    return true;
}
///-------音量选项菜单----------------------------------
void VolumeMenu::show(const OutDevice& dev) const
{
    dev.drawLn();
    dev.drawLn("\tSet Volume");
    dev.draw(" input value(0-100)：");
}
bool VolumeMenu::doChoice(int choice, const OutDevice& dev)
{
    stringstream ss;
    ss << " Set Volume = " << choice;
    dev.drawLn(ss.str().c_str());

    MenuMgr::getMgr()->setCurMenu(MenuID::OPTION_MENU);
    return true;
}
///-------分辨率选项菜单----------------------------------
void ResolutionMenu::show(const OutDevice& dev) const
{
    dev.drawLn();
    dev.drawLn("\tSet resolution");
    dev.drawLn("1. 640X320");
    dev.drawLn("2. 800X600");
    dev.drawLn("3. 1024X768");
    dev.draw(" Your selected:");
}
bool ResolutionMenu::doChoice(int choice, const OutDevice& dev)
{
    switch(choice) {
    case 1:
        dev.drawLn("640x320");
        break;
    case 2:
        dev.drawLn("800x600");
        break;
    case 3:
        dev.drawLn("1024x768");
        break;
    default:
        break;
    }
    MenuMgr::getMgr()->setCurMenu(MenuID::OPTION_MENU);
    return true;
}
///-------Play菜单----------------------------------
void PlayMenu::show(const OutDevice& dev) const
{
    dev.drawLn();
    dev.drawLn("\tPlay Menu");
    dev.drawLn("1. Go...");
    dev.drawLn("2. ApplyRobCard");
    dev.drawLn("3. ApplyMeanCard");
    dev.drawLn("4. ApplyReturnSpell");
    dev.drawLn("5. Load");
    dev.drawLn("6. Save");
    dev.drawLn("0. Back To MainMenu");
    dev.draw(" Your selected:");
}
bool PlayMenu::doChoice(int choice, const OutDevice& dev)
{
    switch(choice) {
    case 1:
        ///........
        Players::getPlayers().play(false);
        break;
    case 2: {
        Player* cur    = Players::getPlayers().curPlayer();
        Player* target = Players::getPlayers().getPlayer(1);
        Command* cmd = new RobCardCommand(cur, target);
        cur->apply(cmd);
        delete cmd;
        break;
    }
    case 3: {
        Player* cur    = Players::getPlayers().curPlayer();
        Command* cmd = new MeanCardCommand();
        cur->apply(cmd);
        delete cmd;
        break;
    }
    case 4: {
        Player* cur    = Players::getPlayers().curPlayer();
        Player* target = Players::getPlayers().getPlayer(1);
        Command* cmd = new ReturnSpellCommand(target);
        cur->apply(cmd);
        delete cmd;
        break;
    }
    case 5:
        MenuMgr::getMgr()->setCurMenu(MenuID::LOAD_MENU);
        break;
    case 6:
        MenuMgr::getMgr()->setCurMenu(MenuID::SAVE_MENU);
        break;
    default:
        MenuMgr::getMgr()->setCurMenu(MenuID::MAIN_MENU);
        break;
    }
    return true;
}

///-----------------------------------------
///
///-----------------------------------------
bool ProcessDecorator::process(const OutDevice& dev)
{
    return menu.process(dev);
}
void ProcessDecorator::show(const OutDevice& dev) const
{
}
bool ProcessDecorator::doChoice(int choice, const OutDevice& dev)
{
    return false;
}
///-----------------------------------------
bool SoundDecorator::process(const OutDevice& dev)
{
    startSound();
    bool result = ProcessDecorator::process(dev);
    endSound();
    return result;
}
void SoundDecorator::startSound()
{
    //PlaySound("windows_sound.wav", 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
void SoundDecorator::endSound()
{
    //PlaySound(0, 0, SND_PURGE);
}
///-----------------------------------------
bool TitleDecorator::process(const OutDevice& dev)
{
    drawTitle(dev);
    return ProcessDecorator::process(dev);
}
void TitleDecorator::drawTitle(const OutDevice& dev)
{
    dev.drawLn("===============================");
    dev.drawLn("=                             =");
    dev.drawLn("===============================");
}

