#include <iostream>
using namespace std;
#include "menu.h"

Menu::Menu()
{
    //ctor
    cout<<"Menu ctor\n";
}

Menu::~Menu()
{
    //dtor
}


// -----
ConsoleMenu::ConsoleMenu(int type, int rs, int cs, char** arrayChars)
    : CharPic(type, rs, cs, arrayChars)
{
    cout<<"ConsoleMenu ctor\n";
}

ConsoleMenu::ConsoleMenu(int type, const CharPic& aCenter): CharPic(type, aCenter)
{
    cout<<"ConsoleMenu ctor\n";
}

ConsoleMenu::ConsoleMenu(int type,
                         int rs1, int cs1, char** arrayChars1,
                         int rs2, int cs2, char** arrayChars2)
    : CharPic(type,
              rs1, cs1, arrayChars1,
              rs2, cs2, arrayChars2)
{
    cout<<"ConsoleMenu ctor\n";
}

ConsoleMenu::ConsoleMenu(int type,
                         const CharPic& aLeftOrTop,
                         int rs2, int cs2, char** arrayChars2)
    : CharPic(type, aLeftOrTop,
              rs2, cs2, arrayChars2)
{
    cout<<"ConsoleMenu ctor\n";
}

ConsoleMenu::ConsoleMenu(int type,
                         int rs1, int cs1, char** arrayChars1,
                         const CharPic& aRightOrBottom)
    : CharPic(type,
              rs1, cs1, arrayChars1,
              aRightOrBottom)
{
    cout<<"ConsoleMenu ctor\n";
}

ConsoleMenu::ConsoleMenu(int type,
                         const CharPic& aLeftOrTop,
                         const CharPic& aRightOrBottom)
    : CharPic(type, aLeftOrTop, aRightOrBottom)
{
    cout<<"ConsoleMenu ctor\n";
}

void ConsoleMenu::show()
{
    cout<<"ConsoleMenu display\n";
    display();
}

ConsoleMenu::~ConsoleMenu()
{
}
