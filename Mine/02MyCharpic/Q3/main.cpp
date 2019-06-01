#include <iostream>

using namespace std;
#include "pic.h"

int main()
{
    char** arrayChar = new char *[3];

    arrayChar[0] = (char *)" a   ";
    arrayChar[1] = (char *)" bccd";
    arrayChar[2] = (char *)"bb   ";

    Pic* simplePic = new SimplePic(3, 5, arrayChar);
    Pic* framePic = new FramePic(3, 5, arrayChar);

    HCatPic* hCatPic = new HCatPic(*simplePic, *framePic);

    cout<<"hCatPic是:";
    hCatPic->display();


    cout<<"\n\nvCatPic的左子图是:";
    hCatPic->leftPic->display();


    cout<<"\n\nvCatPic的右子图是:";
    hCatPic->rightPic->display();

    cout<<"ok";
    delete simplePic;
    delete framePic;

    cout<<"ok";
    delete hCatPic;

    cout<<"ok";

    for(int i=0; i<3; i++)
    {
        delete[] arrayChar[i];
    }
    delete[] arrayChar;

    return 0;
}
