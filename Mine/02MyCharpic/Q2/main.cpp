#include <iostream>

using namespace std;

#include "charpic.h"
#include "charpicfactory.h"

int main()
{
    CharPicFactory* charPicFactory = new CharPicFactory;

    char** arrayChar = new char *[3];

    arrayChar[0] = (char *)" a   ";
    arrayChar[1] = (char *)" bccd";
    arrayChar[2] = (char *)"bb   ";

    CharPic* simpleChar = charPicFactory->createCharPic(1, 3, 5, arrayChar);

    simpleChar->display();

    delete simpleChar;
    delete charPicFactory;

    for(int i=0; i<3; i++)
    {
        delete[] arrayChar[i];
    }
    delete[] arrayChar;

    return 0;
}
