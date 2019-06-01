#include <iostream>

using namespace std;
#include "charpic.h"
#include "menu.h"


int main()
{
    char** arrayChar = new char *[3];

    arrayChar[0] = (char *)" a   ";
    arrayChar[1] = (char *)" bccd";
    arrayChar[2] = (char *)"bb   ";

    CharPic* simpleCharPic = new CharPic(1, 3, 5, arrayChar);
    Menu* consoleMenu = new ConsoleMenu(simpleCharPic);
    consoleMenu->show();

    for (int i=0; i<3; i++)
    {
        free(arrayChar);
    }
    free(arrayChar);

    delete simpleCharPic;

    return 0;
}
