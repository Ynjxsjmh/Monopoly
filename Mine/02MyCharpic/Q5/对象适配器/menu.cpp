#include "menu.h"

Menu::Menu()
{
    //ctor
}

Menu::~Menu()
{
    //dtor
}

// -------
ConsoleMenu::ConsoleMenu(CharPic* charPic)
{
    this->charPic = charPic;
}

void ConsoleMenu::show()
{
    charPic->display();
}

ConsoleMenu::~ConsoleMenu()
{
    delete charPic;
}
