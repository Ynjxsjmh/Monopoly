#ifndef MENU_H
#define MENU_H

#include "charpic.h"

class Menu
{
public:
    Menu();
    virtual ~Menu();

    virtual void show() {}

protected:

private:
};

// ---------
class ConsoleMenu: public Menu
{
public:
    ConsoleMenu(CharPic* charPic);
    virtual ~ConsoleMenu();

    virtual void show();

private:
    CharPic* charPic;

};


#endif // MENU_H
