#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;
#include "CharPic.h"
#include "global.h"

CharPic::CharPic()
{

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
    for (int i=0; i<this->rows; i++)
    {
        cout<<"\n";
        for (int j=0; j<this->cols; j++)
        {
            cout<<this->data[i][j];
        }
    }
}

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
