#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;
#include "CharPic.h"
#include "global.h"

void CharPic::initData()
{
    for (int i=0; i<this->rows; i++)
    {
        for (int j=0; j<this->cols; j++)
        {
            this->data[i][j] = ' ';
        }
    }
}

CharPic::CharPic(int type, int rs, int cs, char** arrayChars)
{

    // new a given pic. if type is 1, create a simple pic; if type is 2, create a pic with frame
    if (PicType::NORMAL_PIC == type)
    {
        this->rows = rs;
        this->cols = cs;

        this->data = new char* [this->rows];
        for (int i=0; i<this->rows; i++)
        {
            this->data[i] = new char[this->cols];
        }

        for (int i=0; i<this->rows; i++)
        {
            for (int j=0; j<this->cols; j++)
            {
                this->data[i][j] = arrayChars[i][j];
            }
        }
    }
    else if (PicType::FRAME_PIC == type)
    {
        this->rows = rs + 2;
        this->cols = cs + 2;
        cout<<"In first\n";
        cout<<this->rows<<" " << this->cols;

        this->data = new char* [this->rows];
        for (int i=0; i<this->rows; i++)
        {
            this->data[i] = new char[this->cols];
        }

        for (int i=1; i<(this->rows-1); i++)
        {
            for (int j=1; j<(this->cols-1); j++)
            {
                this->data[i][j] = arrayChars[i-1][j-1];
            }
        }

        for (int i=0; i<this->cols; i++)
        {
            this->data[0][i] = '-';
            this->data[this->rows-1][i] = '-';
        }

        for (int i=0; i<this->rows; i++)
        {
            this->data[i][0] = '|';
            this->data[i][this->cols-1] = '|';
        }
    }
}

CharPic::CharPic(int type,
                 const CharPic& aCenter)
{
    // add frame to the original pic

    if (PicType::FRAME_PIC == type)
    {
        this->rows = aCenter.getRows() + 2;
        this->cols = aCenter.getCols() + 2;


        this->data = new char* [this->rows];
        for (int i=0; i<this->rows; i++)
        {
            this->data[i] = new char[this->cols];
        }

        for (int i=1; i<this->rows-1; i++)
        {
            for (int j=1; j<this->cols-1; j++)
            {
                this->data[i][j] = aCenter.getData()[i-1][j-1];
            }
        }

        for (int i=0; i<this->cols; i++)
        {
            this->data[0][i] = '-';
            this->data[this->rows-1][i] = '-';
        }

        for (int i=0; i<this->rows; i++)
        {
            this->data[i][0] = '|';
            this->data[i][this->cols-1] = '|';
        }
    }
}

CharPic::CharPic(int type,
                 int rs1, int cs1, char** arrayChars1,
                 int rs2, int cs2, char** arrayChars2)
{
    // if type is 3, concatenate the two pic horizontally;
    // if type is 4, concatenate the two pic vertically.

    if (PicType::VCAT_PIC == type)
    {
        this->rows = rs1 + rs2;
        this->cols = (cs1 > cs2) ? cs1 : cs2;

        this->data = new char* [this->rows];
        for (int i=0; i<this->rows; i++)
        {
            this->data[i] = new char[this->cols];
        }

        this->initData();

        for (int i=0; i<this->rows; i++)
        {
            for (int j=0; j<this->cols; j++)
            {
                if (i<rs1 && j<cs1)
                {
                    this->data[i][j] = arrayChars1[i][j];
                }
                else if (i >= rs1 && j < cs2)
                {
                    this->data[i][j] = arrayChars2[i-rs1][j];
                }

            }
        }
    }
    else if (PicType::HCAT_PIC == type)
    {
        this->rows = (rs1 > rs2 ? rs1 : rs2);
        this->cols = cs1 + cs2;

        this->data = new char* [this->rows];
        for (int i=0; i<this->rows; i++)
        {
            for (int j=0; j<this->cols; j++)
            {
                this->data[i] = new char[this->cols];
            }
        }

        this->initData();

        for (int i=0; i<this->rows; i++)
        {
            for (int j=0; j<this->cols; j++)
            {
                if (i<rs1 && j<cs1)
                {
                    this->data[i][j] = arrayChars1[i][j];
                }
                else if (j>=cs1 && i<rs2)
                {
                    this->data[i][j] = arrayChars2[i][j-cs1];
                }
            }
        }
    }
}

CharPic::CharPic(int type,
                 const CharPic& aLeftOrTop,
                 int rs2, int cs2, char** arrayChars2)
{

    if (PicType::VCAT_PIC == type)
    {
        this->rows = aLeftOrTop.getRows() + rs2;
        this->cols = (aLeftOrTop.getCols() > cs2) ? aLeftOrTop.getCols() : cs2;

        this->data = new char* [this->rows];
        for (int i=0; i<this->rows; i++)
        {
            this->data[i] = new char[this->cols];
        }

        this->initData();

        for (int i=0; i<this->rows; i++)
        {
            for (int j=0; j<this->cols; j++)
            {
                if (i<aLeftOrTop.getRows() && j<aLeftOrTop.getCols())
                {
                    this->data[i][j] = aLeftOrTop.getData()[i][j];
                }
                else if (i >= aLeftOrTop.getRows() && j < cs2)
                {
                    this->data[i][j] = arrayChars2[i-aLeftOrTop.getRows()][j];
                }

            }
        }
    }
    else if (PicType::HCAT_PIC == type)
    {
        this->rows = (aLeftOrTop.getRows() > rs2 ? aLeftOrTop.getRows() : rs2);
        this->cols = aLeftOrTop.getCols() + cs2;

        this->data = new char* [this->rows];
        for (int i=0; i<this->rows; i++)
        {
            for (int j=0; j<this->cols; j++)
            {
                this->data[i] = new char[this->cols];
            }
        }

        this->initData();

        for (int i=0; i<this->rows; i++)
        {
            for (int j=0; j<this->cols; j++)
            {
                if (i<aLeftOrTop.getRows() && j<aLeftOrTop.getCols())
                {
                    this->data[i][j] = aLeftOrTop.getData()[i][j];
                }
                else if (j>=aLeftOrTop.getCols() && i<rs2)
                {
                    this->data[i][j] = arrayChars2[i][j-aLeftOrTop.getCols()];
                }
            }
        }
    }
}

CharPic::CharPic(int type,
                 int rs1, int cs1, char** arrayChars1,
                 const CharPic& aRightOrBottom)
{

    if (PicType::VCAT_PIC == type)
    {
        this->rows = rs1 + aRightOrBottom.getRows();
        this->cols = (cs1 > aRightOrBottom.getCols()) ? cs1 : aRightOrBottom.getCols();

        this->data = new char* [this->rows];
        for (int i=0; i<this->rows; i++)
        {
            this->data[i] = new char[this->cols];
        }

        this->initData();

        for (int i=0; i<this->rows; i++)
        {
            for (int j=0; j<this->cols; j++)
            {
                if (i<rs1 && j<cs1)
                {
                    this->data[i][j] = arrayChars1[i][j];
                }
                else if (i >= rs1 && j < aRightOrBottom.getCols())
                {
                    this->data[i][j] = aRightOrBottom.getData()[i-rs1][j];
                }

            }
        }
    }
    else if (PicType::HCAT_PIC == type)
    {
        this->rows = (rs1 > aRightOrBottom.getRows() ? rs1 : aRightOrBottom.getRows());
        this->cols = cs1 + aRightOrBottom.getCols();

        this->data = new char* [this->rows];
        for (int i=0; i<this->rows; i++)
        {
            for (int j=0; j<this->cols; j++)
            {
                this->data[i] = new char[this->cols];
            }
        }

        this->initData();

        for (int i=0; i<this->rows; i++)
        {
            for (int j=0; j<this->cols; j++)
            {
                if (i<rs1 && j<cs1)
                {
                    this->data[i][j] = arrayChars1[i][j];
                }
                else if (j>=cs1 && i<aRightOrBottom.getRows())
                {
                    this->data[i][j] = aRightOrBottom.getData()[i][j-cs1];
                }
            }
        }
    }
}

CharPic::CharPic(int type,
                 const CharPic& aLeftOrTop,
                 const CharPic& aRightOrBottom)
{

    if (PicType::VCAT_PIC == type)
    {
        this->rows = aLeftOrTop.getRows() + aRightOrBottom.getRows();
        this->cols = (aLeftOrTop.getCols() > aRightOrBottom.getCols()) ? aLeftOrTop.getCols() : aRightOrBottom.getCols();

        this->data = new char* [this->rows];
        for (int i=0; i<this->rows; i++)
        {
            this->data[i] = new char[this->cols];
        }
        this->initData();

        for (int i=0; i<this->rows; i++)
        {
            for (int j=0; j<this->cols; j++)
            {
                if (i<aLeftOrTop.getRows() && j<aLeftOrTop.getCols())
                {
                    this->data[i][j] = aLeftOrTop.getData()[i][j];
                }
                else if (i >= aLeftOrTop.getRows() && j < aRightOrBottom.getCols())
                {
                    this->data[i][j] = aRightOrBottom.getData()[i-aLeftOrTop.getRows()][j];
                }

            }
        }
    }
    else if (PicType::HCAT_PIC == type)
    {
        this->rows = (aLeftOrTop.getRows() > aRightOrBottom.getRows() ? aLeftOrTop.getRows() : aRightOrBottom.getRows());
        this->cols = aLeftOrTop.getCols() + aRightOrBottom.getCols();

        this->data = new char* [this->rows];
        for (int i=0; i<this->rows; i++)
        {
            for (int j=0; j<this->cols; j++)
            {
                this->data[i] = new char[this->cols];
            }
        }
        this->initData();

        for (int i=0; i<this->rows; i++)
        {
            for (int j=0; j<this->cols; j++)
            {
                if (i<aLeftOrTop.getRows() && j<aLeftOrTop.getCols())
                {
                    this->data[i][j] = aLeftOrTop.getData()[i][j];
                }
                else if (j>=aLeftOrTop.getCols() && i<aRightOrBottom.getRows())
                {
                    this->data[i][j] = aRightOrBottom.getData()[i][j-aLeftOrTop.getCols()];
                }
            }
        }
    }
}

CharPic::~CharPic()
{
    for (int i=0; i<this->rows; i++)
    {
        free(this->data[i]);
    }
    free(this->data);
}

CharPic::CharPic(const CharPic& charPic)
{
    this->rows = charPic.getRows();
    this->cols = charPic.getCols();

    this->data = new char* [this->rows];
    for (int i=0; i<this->rows; i++)
    {
        this->data[i] = new char[this->cols];
    }

    for (int i=0; i<this->rows; i++)
    {
        for (int j=0; j<this->cols; j++)
        {
            this->data[i][j] = charPic.getData()[i][j];
        }
    }
}


CharPic& CharPic::operator=(const CharPic& charPic)
{
    this->rows = charPic.getRows();
    this->cols = charPic.getCols();

    this->data = new char* [this->rows];
    for (int i=0; i<this->rows; i++)
    {
        this->data[i] = new char[this->cols];
    }

    for (int i=0; i<this->rows; i++)
    {
        for (int j=0; j<this->cols; j++)
        {
            this->data[i][j] = charPic.getData()[i][j];
        }
    }
    return *this;
}

void CharPic::display() const
{
    cout<<"CharPic display\n";

    for (int i=0; i<this->rows; i++)
    {
        cout<<"\n";
        for (int j=0; j<this->cols; j++)
        {
            cout<<this->data[i][j];
        }
    }
}

int CharPic::getRows() const
{
    return this->rows;
}

int CharPic::getCols() const
{
    return this->cols;
}

char** CharPic::getData() const
{
    return this->data;
}
