#ifndef CHARPICFACTORY_H
#define CHARPICFACTORY_H

#include "charpic.h"

class CharPicFactory
{
public:
    CharPicFactory();
    virtual ~CharPicFactory();


    CharPic* createCharPic(int type, int rs, int cs, char** arrayChars);
    CharPic* createCharPic(int type,
                           const CharPic& aCenter);
    CharPic* createCharPic(int type,
                           int rs1, int cs1, char** arrayChars1,
                           int rs2, int cs2, char** arrayChars2);
    CharPic* createCharPic(int type,
                           const CharPic& aLeftOrTop,
                           int rs2, int cs2, char** arrayChars2);
    CharPic* createCharPic(int type,
                           int rs1, int cs1, char** arrayChars1,
                           const CharPic& aRightOrBottom);
    CharPic* createCharPic(int type,
                           const CharPic& aLeftOrTop,
                           const CharPic& aRightOrBottom);

private:
    CharPic* charPic;
};

#endif // CHARPICFACTORY_H
