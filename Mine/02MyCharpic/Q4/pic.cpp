#include <iostream>
#include <stdlib.h>
using namespace std;

#include "pic.h"

//Pic::Pic()
//{
//    for(int i=0; i<26; i++)
//    {
//        this->encryptionMap['A'+i] = ('a' + i);  //converse the upper to the lower
//        this->encryptionMap['a'+i] = ('A' + i);
//    }
//}

//Pic::Pic(const Pic& pic)
//
//{
//    this->rows = pic.rows;
//    this->cols = pic.cols;
//    this->data = pic.data;
//    this->encryptionMap = pic.encryptionMap;
//}

Pic& Pic::operator=(const Pic& pic)
{
    return *this;
}

Pic::~Pic()
{
    //dtor
//    for(int i=0; i<rows; i++)
//    {
//        delete[] data[i];
//    }
//    delete[] data;
}

void Pic::display(int indentationNum, bool isEncryption)
{
    picImp->display(indentationNum, isEncryption);
}

void Pic::swapPic()
{
    picImp->swapPic();
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
