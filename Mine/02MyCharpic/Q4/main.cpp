#include <iostream>

using namespace std;
#include "pic.h"
#include "picimp.h"
#include "global.h"

int main()
{
    char** arrayChars1 = new char *[3];
    arrayChars1[0] = (char *)" a   io";
    arrayChars1[1] = (char *)" bccd p";
    arrayChars1[2] = (char *)"b   u  ";

    char** arrayChars2 = new char *[4];
    arrayChars2[0] = (char *)"iu   ";
    arrayChars2[1] = (char *)" bavd";
    arrayChars2[2] = (char *)"jk h ";
    arrayChars2[3] = (char *)"zs   ";

    PicImp* simplePicImp1 = new SimplePic(3, 7, arrayChars1);
    PicImp* simplePicImp2 = new SimplePic(4, 5, arrayChars2);

    PicImp* cCatPicImp = new CCatPic(CrossType::NW_TO_SE, *simplePicImp1, *simplePicImp2);
    Pic* cCatPic = new Pic(cCatPicImp);
    cout<<"�Խ������ӣ�";
    cCatPic->display();

    FramePic* framePicImp = new FramePic(*simplePicImp1);
    framePicImp->setHSym('$');
    framePicImp->setVSym('$');
    Pic* framePic = new Pic(framePicImp);
    cout<<"\n\n\n�����ʾ�Լ�FramePic�ı����";
    framePic->display(1);

    Pic* simplePic = new Pic(simplePicImp1);
    cout<<"\n\n\nsimplePic����ǰ:";
    simplePic->display();
    cout<<"\n\nsimplePic���ܺ�Сд���д��:";
    simplePic->display(0, true);

    PicImp* hCatPicImp = new HCatPic(*simplePicImp1, *simplePicImp2);
    Pic* hCatPic = new Pic(hCatPicImp);
    cout<<"\n\n\nHCat����ǰ��";
    hCatPic->display();
    hCatPic->swapPic();
    cout<<"\n\nHCat������";
    hCatPic->display();

    return 0;
}
