///======================================================================
///  Project:   Richer00
/// FileName:	menu.h
///     Desc:
///   Author:	Chen Wei
///  History:
///======================================================================
#ifndef MENU_H
#define MENU_H

class MenuID
{
public:
    static const int MAIN_MENU = 0;
    static const int PLAYERS_MENU = 1;
    static const int LOAD_MENU = 2;
    static const int SAVE_MENU = 3;
    static const int OPTION_MENU = 4;
    static const int VOLUME_MENU = 5;
    static const int RESOLUTION_MENU = 6;

    static const int MENU_COUNT = 7;
};

class Game;
class Menu
{
public:
    Menu() {}
    virtual ~Menu() {}
    bool process(Game * game) ;
protected:
    virtual void show() const = 0;
    virtual int  getChoice() const;
    virtual bool doChoice(Game * game,int choice) = 0;
};
///------主菜单--------------------------------
class MainMenu: public Menu
{
protected:
    virtual void show() const;
    virtual bool doChoice(Game * game,int choice);
};
///------玩家人数菜单--------------------------------
class PlayersMenu: public Menu
{
protected:
    virtual void show() const;
    virtual bool doChoice(Game * game,int choice);
};
///-------载入菜单----------------------------------
class LoadMenu: public Menu
{
protected:
    virtual void show() const;
    virtual bool doChoice(Game * game,int choice);
};
///-------保存菜单----------------------------------
class SaveMenu: public Menu
{
protected:
    virtual void show() const;
    virtual bool doChoice(Game * game,int choice);
};
///-------选项菜单----------------------------------
class OptionMenu: public Menu
{
protected:
    virtual void show() const;
    virtual bool doChoice(Game * game,int choice);
};
///-------音量选项菜单----------------------------------
class VolumeMenu: public Menu
{
protected:
    virtual void show() const;
    virtual bool doChoice(Game * game,int choice);
};
///-------分辨率选项菜单----------------------------------
class ResolutionMenu: public Menu
{
protected:
    virtual void show() const;
    virtual bool doChoice(Game * game,int choice);
};
#endif // MENU_H
