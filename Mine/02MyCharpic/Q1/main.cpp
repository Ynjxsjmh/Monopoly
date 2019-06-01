#include <iostream>
#include <stdlib.h>

using namespace std;
#include "CharPic.h"

int main()
{
    char** arrayChar = new char *[3];
    char** arrayChar2 = new char *[3];

    arrayChar[0] = (char *)" a   ";
    arrayChar[1] = (char *)" bccd";
    arrayChar[2] = (char *)"bb   ";

    CharPic* charPic = new CharPic(1, 3, 5, arrayChar);
    charPic->display();

    CharPic* charPic2 = new CharPic(2, *charPic);
    charPic2->display();


    arrayChar2[0] = (char *)"t     ";
    arrayChar2[1] = (char *)" y igi";
    CharPic* charPic3 = new CharPic(1, 2, 6, arrayChar2);

    CharPic* vcharPic = new CharPic(3, *charPic2, 2, 6, arrayChar2);
    vcharPic->display();

    free(charPic);
    free(charPic2);
}
