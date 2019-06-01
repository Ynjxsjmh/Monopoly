#include <iostream>
#include <stdlib.h>
using namespace std;

#include "pic.h"

Pic::Pic()
    :refCount(0) {}

Pic::Pic(const Pic& pic)
    :refCount(0)
{
    this->rows = pic.rows;
    this->cols = pic.cols;
    this->data = pic.data;
}

Pic& Pic::operator=(const Pic& pic)
{
    return *this;
}

Pic::~Pic()
{
    //dtor
    for(int i=0; i<rows; i++)
    {
        delete[] data[i];
    }
    delete[] data;
}

void Pic::createData()
{
    this->data = new char* [this->rows];
    for (int i=0; i<this->rows; i++)
    {
        this->data[i] = new char[this->cols];
    }

    this->initData();
}

void Pic::initData()
{
    for (int i=0; i<this->rows; i++)
    {
        for (int j=0; j<this->cols; j++)
        {
            this->data[i][j] = ' ';
        }
    }
}

void Pic::display() const
{
    for (int i=0; i<this->rows; i++)
    {
        cout<<"\n";
        for (int j=0; j<this->cols; j++)
        {
            cout<<this->data[i][j];
        }
    }
}

int Pic::getRows() const
{
    return this->rows;
}

int Pic::getCols() const
{
    return this->cols;
}

char** Pic::getData() const
{
    return this->data;
}

void Pic::addReference()
{
    ++refCount;
}

void Pic::removeReference()
{
    if(--refCount == 0)
    {
        delete this;
    }
}

//----

SimplePic::SimplePic(int rs, int cs, char** arrayChars)
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


SimplePic* SimplePic::clone()
{
    return new SimplePic(*this);
}


//----

FramePic::FramePic(int rs, int cs, char** arrayChars)
{
    this->rows = rs + 2;
    this->cols = cs + 2;

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

FramePic::FramePic(const Pic& aCenter)
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


FramePic* FramePic::clone()
{
    return new FramePic(*this);
}


//----

HCatPic::HCatPic(int rs1, int cs1, char** arrayChars1,
                 int rs2, int cs2, char** arrayChars2)
{
    this->leftPic = new SimplePic(rs1, cs1, arrayChars1);
    this->rightPic = new SimplePic(rs2, cs2, arrayChars2);

    this->rows = (rs1 > rs2 ? rs1 : rs2);
    this->cols = cs1 + cs2;

    this->createData();

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

HCatPic::HCatPic(const Pic& aLeftOrTop,
                 int rs2, int cs2, char** arrayChars2)
{
    this->leftPic = &aLeftOrTop;
    this->rightPic = new SimplePic(rs2, cs2, arrayChars2);

    this->rows = (aLeftOrTop.getRows() > rs2 ? aLeftOrTop.getRows() : rs2);
    this->cols = aLeftOrTop.getCols() + cs2;

    this->createData();

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

HCatPic::HCatPic(int rs1, int cs1, char** arrayChars1,
                 const Pic& aRightOrBottom)
{
    this->leftPic = new SimplePic(rs1, cs1, arrayChars1);
    this->rightPic = &aRightOrBottom;

    this->rows = (rs1 > aRightOrBottom.getRows() ? rs1 : aRightOrBottom.getRows());
    this->cols = cs1 + aRightOrBottom.getCols();

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

HCatPic::HCatPic(const Pic& aLeftOrTop,
                 const Pic& aRightOrBottom)
{
    this->leftPic = &aLeftOrTop;
    this->rightPic = &aRightOrBottom;

    this->rows = (aLeftOrTop.getRows() > aRightOrBottom.getRows() ? aLeftOrTop.getRows() : aRightOrBottom.getRows());
    this->cols = aLeftOrTop.getCols() + aRightOrBottom.getCols();

    this->createData();

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

HCatPic* HCatPic::clone()
{
    return new HCatPic(*this);
}

HCatPic::~HCatPic()
{

}

//----

VCatPic::VCatPic(int rs1, int cs1, char** arrayChars1,
                 int rs2, int cs2, char** arrayChars2)
{
    this->topPic = new SimplePic(rs1, cs1, arrayChars1);
    this->bottomPic = new SimplePic(rs2, cs2, arrayChars2);

    this->rows = (rs1 > rs2 ? rs1 : rs2);
    this->cols = cs1 + cs2;

    this->createData();

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

VCatPic::VCatPic(const Pic& aLeftOrTop,
                 int rs2, int cs2, char** arrayChars2)
{
    this->topPic = &aLeftOrTop;
    this->bottomPic = new SimplePic(rs2, cs2, arrayChars2);

    this->rows = aLeftOrTop.getRows() + rs2;
    this->cols = (aLeftOrTop.getCols() > cs2) ? aLeftOrTop.getCols() : cs2;

    this->createData();

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

VCatPic::VCatPic(int rs1, int cs1, char** arrayChars1,
                 const Pic& aRightOrBottom)
{
    this->topPic = new SimplePic(rs1, cs1, arrayChars1);
    this->bottomPic = &aRightOrBottom;

    this->rows = rs1 + aRightOrBottom.getRows();
    this->cols = (cs1 > aRightOrBottom.getCols()) ? cs1 : aRightOrBottom.getCols();

    this->createData();

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

VCatPic::VCatPic(const Pic& aLeftOrTop,
                 const Pic& aRightOrBottom)
{
    this->topPic = &aLeftOrTop;
    this->bottomPic = &aRightOrBottom;

    this->rows = aLeftOrTop.getRows() + aRightOrBottom.getRows();
    this->cols = (aLeftOrTop.getCols() > aRightOrBottom.getCols()) ? aLeftOrTop.getCols() : aRightOrBottom.getCols();

    this->createData();

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

VCatPic* VCatPic::clone()
{
    return new VCatPic(*this);
}


VCatPic::~VCatPic()
{

}
