///======================================================================
///  Project:   Richer00
/// FileName:	menu.cpp
///     Desc:   Richer 00
///   Author:	Chen Wei
///======================================================================
#include <iostream>
using namespace std;

#include "menu.h"

bool Menu::process()
{
    show();
    int choice = getChoice();
    return doChoice(choice);
}
int  Menu::getChoice() const
{
    int choice = 0;
    cin >> choice;
    return choice;
}
///-----------------------------------------
void MainMenu::show() const
{
    cout << "\n\t" << "主菜单" << endl;
    cout << "1: New" << endl;
    cout << "2: Load" << endl;
    cout << "3: Save" << endl;
    cout << "4: Option" << endl;
    cout << "5: Play..." << endl;
    cout << "0: Exit" << endl;
    cout << " Your selected:";
}

bool MainMenu::doChoice(int choice)
{
    switch(choice) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        return true;
    default:
        return false;
    }
}

///------玩家人数菜单--------------------------------
void PlayersMenu::show() const
{
    cout << "\n\tSet number of players(2-8):" << endl;
    cout << "2. 2" << endl;
    cout << "3. 3" << endl;
    cout << "4. 4" << endl;
    cout << "5. 5" << endl;
    cout << "6. 6" << endl;
    cout << "7. 7" << endl;
    cout << "8. 8" << endl;
    cout << "0. Back" << endl;
    cout << " Your selected:";
}
bool PlayersMenu::doChoice(int choice)
{

}
///-------载入菜单----------------------------------
void LoadMenu::show() const
{
    cout << "\n\tSelect the Record to be loaded(1-5):" << endl;
    cout << "1. 1" << endl;
    cout << "2. 2" << endl;
    cout << "3. 3" << endl;
    cout << "4. 4" << endl;
    cout << "5. 5" << endl;
    cout << "0. Back" << endl;
    cout << " Your selected:";
}
bool LoadMenu::doChoice(int choice)
{
}
///-------保存菜单----------------------------------
void SaveMenu::show() const
{
    cout << "\n\tSelect the Record to save(1-5):" << endl;
    cout << "1. 1" << endl;
    cout << "2. 2" << endl;
    cout << "3. 3" << endl;
    cout << "4. 4" << endl;
    cout << "5. 5" << endl;
    cout << "0. Back" << endl;
    cout << " Your selected:";
}
bool SaveMenu::doChoice(int choice)
{
}

///-------选项菜单----------------------------------
void OptionMenu::show() const
{
    cout << "\n\tSet options :" << endl;
    cout << "1.Set the value of Volume(0-100)" << endl;
    cout << "2.Set the resolution" << endl;
    cout << "0. Back" << endl;
    cout << " Your selected:";
}
bool OptionMenu::doChoice(int choice)
{
}
///-------音量选项菜单----------------------------------
void VolumeMenu::show() const
{
    cout << "\n\tSet Volume" << endl;
    cout << "input value(0-100)：";
}
bool VolumeMenu::doChoice(int choice)
{
}
///-------分辨率选项菜单----------------------------------
void ResolutionMenu::show() const
{
    cout << "\n\tSet resolution" << endl;
    cout << "1. 640X320" << endl;
    cout << "2. 800X600" << endl;
    cout << "3. 1024X768" << endl;
    cout << " Your selected:";
}
bool ResolutionMenu::doChoice(int choice)
{
}

