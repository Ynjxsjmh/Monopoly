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
    CharPic* charPic;

private:
};


class ConsoleMenu: public Menu, private CharPic
{
public:
    ConsoleMenu(int type, int rs, int cs, char** arrayChars);
    ConsoleMenu(int type,
            const CharPic& aCenter);
    ConsoleMenu(int type,
            int rs1, int cs1, char** arrayChars1,
            int rs2, int cs2, char** arrayChars2);
    ConsoleMenu(int type,
            const CharPic& aLeftOrTop,
            int rs2, int cs2, char** arrayChars2);
    ConsoleMenu(int type,
            int rs1, int cs1, char** arrayChars1,
            const CharPic& aRightOrBottom);
    ConsoleMenu(int type,
            const CharPic& aLeftOrTop,
            const CharPic& aRightOrBottom);

    virtual ~ConsoleMenu();

    virtual void show();
};

#endif // MENU_H
