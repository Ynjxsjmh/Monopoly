#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;
#include "CharPic.h"
#include "global.h"
#include "charpicfactory.h"

CharPicFactory::CharPicFactory()
{
    //ctor
    charPic = new CharPic;
}

CharPicFactory::~CharPicFactory()
{
    //dtor
    free(charPic);
}


CharPic* CharPicFactory::createCharPic(int type, int rs, int cs, char** arrayChars)
{
    if (PicType::NORMAL_PIC == type)
    {
        charPic->rows = rs;
        charPic->cols = cs;

        charPic->data = new char* [charPic->rows];
        for (int i=0; i<charPic->rows; i++)
        {
            charPic->data[i] = new char[charPic->cols];
        }

        for (int i=0; i<charPic->rows; i++)
        {
            for (int j=0; j<charPic->cols; j++)
            {
                charPic->data[i][j] = arrayChars[i][j];
            }
        }
    }
    else if (PicType::FRAME_PIC == type)
    {
        charPic->rows = rs + 2;
        charPic->cols = cs + 2;
        cout<<"In first\n";
        cout<<charPic->rows<<" " << charPic->cols;

        charPic->data = new char* [charPic->rows];
        for (int i=0; i<charPic->rows; i++)
        {
            charPic->data[i] = new char[charPic->cols];
        }

        for (int i=1; i<(charPic->rows-1); i++)
        {
            for (int j=1; j<(charPic->cols-1); j++)
            {
                charPic->data[i][j] = arrayChars[i-1][j-1];
            }
        }

        for (int i=0; i<charPic->cols; i++)
        {
            charPic->data[0][i] = '-';
            charPic->data[charPic->rows-1][i] = '-';
        }

        for (int i=0; i<charPic->rows; i++)
        {
            charPic->data[i][0] = '|';
            charPic->data[i][charPic->cols-1] = '|';
        }
    }
    return charPic;
}

CharPic* CharPicFactory::createCharPic(int type,
                                       const CharPic& aCenter)
{
    if (PicType::FRAME_PIC == type)
    {
        charPic->rows = aCenter.getRows() + 2;
        charPic->cols = aCenter.getCols() + 2;


        charPic->data = new char* [charPic->rows];
        for (int i=0; i<charPic->rows; i++)
        {
            charPic->data[i] = new char[charPic->cols];
        }

        for (int i=1; i<charPic->rows-1; i++)
        {
            for (int j=1; j<charPic->cols-1; j++)
            {
                charPic->data[i][j] = aCenter.getData()[i-1][j-1];
            }
        }

        for (int i=0; i<charPic->cols; i++)
        {
            charPic->data[0][i] = '-';
            charPic->data[charPic->rows-1][i] = '-';
        }

        for (int i=0; i<charPic->rows; i++)
        {
            charPic->data[i][0] = '|';
            charPic->data[i][charPic->cols-1] = '|';
        }
    }
    return charPic;
}

CharPic* CharPicFactory::createCharPic(int type,
                                       int rs1, int cs1, char** arrayChars1,
                                       int rs2, int cs2, char** arrayChars2)
{
    if (PicType::VCAT_PIC == type)
    {
        charPic->rows = rs1 + rs2;
        charPic->cols = (cs1 > cs2) ? cs1 : cs2;

        charPic->data = new char* [charPic->rows];
        for (int i=0; i<charPic->rows; i++)
        {
            charPic->data[i] = new char[charPic->cols];
        }

        charPic->initData();

        for (int i=0; i<charPic->rows; i++)
        {
            for (int j=0; j<charPic->cols; j++)
            {
                if (i<rs1 && j<cs1)
                {
                    charPic->data[i][j] = arrayChars1[i][j];
                }
                else if (i >= rs1 && j < cs2)
                {
                    charPic->data[i][j] = arrayChars2[i-rs1][j];
                }

            }
        }
    }
    else if (PicType::HCAT_PIC == type)
    {
        charPic->rows = (rs1 > rs2 ? rs1 : rs2);
        charPic->cols = cs1 + cs2;

        charPic->data = new char* [charPic->rows];
        for (int i=0; i<charPic->rows; i++)
        {
            for (int j=0; j<charPic->cols; j++)
            {
                charPic->data[i] = new char[charPic->cols];
            }
        }

        charPic->initData();

        for (int i=0; i<charPic->rows; i++)
        {
            for (int j=0; j<charPic->cols; j++)
            {
                if (i<rs1 && j<cs1)
                {
                    charPic->data[i][j] = arrayChars1[i][j];
                }
                else if (j>=cs1 && i<rs2)
                {
                    charPic->data[i][j] = arrayChars2[i][j-cs1];
                }
            }
        }
    }
    return charPic;
}


CharPic* CharPicFactory::createCharPic(int type,
                                       const CharPic& aLeftOrTop,
                                       int rs2, int cs2, char** arrayChars2)
{
    if (PicType::VCAT_PIC == type)
    {
        charPic->rows = aLeftOrTop.getRows() + rs2;
        charPic->cols = (aLeftOrTop.getCols() > cs2) ? aLeftOrTop.getCols() : cs2;

        charPic->data = new char* [charPic->rows];
        for (int i=0; i<charPic->rows; i++)
        {
            charPic->data[i] = new char[charPic->cols];
        }

        charPic->initData();

        for (int i=0; i<charPic->rows; i++)
        {
            for (int j=0; j<charPic->cols; j++)
            {
                if (i<aLeftOrTop.getRows() && j<aLeftOrTop.getCols())
                {
                    charPic->data[i][j] = aLeftOrTop.getData()[i][j];
                }
                else if (i >= aLeftOrTop.getRows() && j < cs2)
                {
                    charPic->data[i][j] = arrayChars2[i-aLeftOrTop.getRows()][j];
                }

            }
        }
    }
    else if (PicType::HCAT_PIC == type)
    {
        charPic->rows = (aLeftOrTop.getRows() > rs2 ? aLeftOrTop.getRows() : rs2);
        charPic->cols = aLeftOrTop.getCols() + cs2;

        charPic->data = new char* [charPic->rows];
        for (int i=0; i<charPic->rows; i++)
        {
            for (int j=0; j<charPic->cols; j++)
            {
                charPic->data[i] = new char[charPic->cols];
            }
        }

        charPic->initData();

        for (int i=0; i<charPic->rows; i++)
        {
            for (int j=0; j<charPic->cols; j++)
            {
                if (i<aLeftOrTop.getRows() && j<aLeftOrTop.getCols())
                {
                    charPic->data[i][j] = aLeftOrTop.getData()[i][j];
                }
                else if (j>=aLeftOrTop.getCols() && i<rs2)
                {
                    charPic->data[i][j] = arrayChars2[i][j-aLeftOrTop.getCols()];
                }
            }
        }
    }
    return charPic;
}


CharPic* CharPicFactory::createCharPic(int type,
                                       int rs1, int cs1, char** arrayChars1,
                                       const CharPic& aRightOrBottom)
{
    if (PicType::VCAT_PIC == type)
    {
        charPic->rows = rs1 + aRightOrBottom.getRows();
        charPic->cols = (cs1 > aRightOrBottom.getCols()) ? cs1 : aRightOrBottom.getCols();

        charPic->data = new char* [charPic->rows];
        for (int i=0; i<charPic->rows; i++)
        {
            charPic->data[i] = new char[charPic->cols];
        }

        charPic->initData();

        for (int i=0; i<charPic->rows; i++)
        {
            for (int j=0; j<charPic->cols; j++)
            {
                if (i<rs1 && j<cs1)
                {
                    charPic->data[i][j] = arrayChars1[i][j];
                }
                else if (i >= rs1 && j < aRightOrBottom.getCols())
                {
                    charPic->data[i][j] = aRightOrBottom.getData()[i-rs1][j];
                }

            }
        }
    }
    else if (PicType::HCAT_PIC == type)
    {
        charPic->rows = (rs1 > aRightOrBottom.getRows() ? rs1 : aRightOrBottom.getRows());
        charPic->cols = cs1 + aRightOrBottom.getCols();

        charPic->data = new char* [charPic->rows];
        for (int i=0; i<charPic->rows; i++)
        {
            for (int j=0; j<charPic->cols; j++)
            {
                charPic->data[i] = new char[charPic->cols];
            }
        }

        charPic->initData();

        for (int i=0; i<charPic->rows; i++)
        {
            for (int j=0; j<charPic->cols; j++)
            {
                if (i<rs1 && j<cs1)
                {
                    charPic->data[i][j] = arrayChars1[i][j];
                }
                else if (j>=cs1 && i<aRightOrBottom.getRows())
                {
                    charPic->data[i][j] = aRightOrBottom.getData()[i][j-cs1];
                }
            }
        }
    }
    return charPic;
}


CharPic* CharPicFactory::createCharPic(int type,
                                       const CharPic& aLeftOrTop,
                                       const CharPic& aRightOrBottom)
{
    if (PicType::VCAT_PIC == type)
    {
        charPic->rows = aLeftOrTop.getRows() + aRightOrBottom.getRows();
        charPic->cols = (aLeftOrTop.getCols() > aRightOrBottom.getCols()) ? aLeftOrTop.getCols() : aRightOrBottom.getCols();

        charPic->data = new char* [charPic->rows];
        for (int i=0; i<charPic->rows; i++)
        {
            charPic->data[i] = new char[charPic->cols];
        }
        charPic->initData();

        for (int i=0; i<charPic->rows; i++)
        {
            for (int j=0; j<charPic->cols; j++)
            {
                if (i<aLeftOrTop.getRows() && j<aLeftOrTop.getCols())
                {
                    charPic->data[i][j] = aLeftOrTop.getData()[i][j];
                }
                else if (i >= aLeftOrTop.getRows() && j < aRightOrBottom.getCols())
                {
                    charPic->data[i][j] = aRightOrBottom.getData()[i-aLeftOrTop.getRows()][j];
                }

            }
        }
    }
    else if (PicType::HCAT_PIC == type)
    {
        charPic->rows = (aLeftOrTop.getRows() > aRightOrBottom.getRows() ? aLeftOrTop.getRows() : aRightOrBottom.getRows());
        charPic->cols = aLeftOrTop.getCols() + aRightOrBottom.getCols();

        charPic->data = new char* [charPic->rows];
        for (int i=0; i<charPic->rows; i++)
        {
            for (int j=0; j<charPic->cols; j++)
            {
                charPic->data[i] = new char[charPic->cols];
            }
        }
        charPic->initData();

        for (int i=0; i<charPic->rows; i++)
        {
            for (int j=0; j<charPic->cols; j++)
            {
                if (i<aLeftOrTop.getRows() && j<aLeftOrTop.getCols())
                {
                    charPic->data[i][j] = aLeftOrTop.getData()[i][j];
                }
                else if (j>=aLeftOrTop.getCols() && i<aRightOrBottom.getRows())
                {
                    charPic->data[i][j] = aRightOrBottom.getData()[i][j-aLeftOrTop.getCols()];
                }
            }
        }
    }
    return charPic;
}
