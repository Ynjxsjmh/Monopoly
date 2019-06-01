#ifndef PIC_H
#define PIC_H

#include "picimp.h"

class Pic
{
public:
    Pic(PicImp* p): refCount(0), picImp(p) {}
    Pic(const Pic & pic): refCount(0), picImp(pic.picImp) {}
    Pic& operator=(const Pic& pic);

    virtual ~Pic();
//    virtual Pic* clone() {}

    virtual void display(int indentationNum=0, bool isEncryption=false);
    virtual void swapPic();

    int getRows() const;
    int getCols() const;
    char** getData() const;

    void addReference();
    void removeReference();

//private:
//    virtual void initData();
//    virtual void createData();

protected:
    int refCount;

//protected:
//    int rows;
//    int cols;
//    char** data;
//
//    map<char, char> encryptionMap;

public:
    PicImp* picImp;
};




// -------------
//class SimplePic: public Pic
//{
//public:
//    SimplePic(int rs, int cs, char** arrayData);
//
//    virtual ~SimplePic() {}
//    virtual SimplePic* clone() override;
//    virtual void swapPic() {}
//
//    SimplePic& operator=(const SimplePic&)
//    {
//        return *this;
//    }
//
//};
//
//// -------------
//class FramePic: public Pic
//{
//public:
//    FramePic(int rs, int cs, char** arrayChar);
//    FramePic(const Pic& aCenter);
//
//    virtual ~FramePic() {}
//    virtual FramePic* clone() override;
//    virtual void swapPic() {}
//
//    FramePic& operator=(const FramePic&)
//    {
//        return *this;
//    }
//
//public:
//    virtual void setHSym(char HSym);
//    virtual void setVSym(char VSym);
//
//protected:
//    char HSym;
//    char VSym;
//};
//
//// -------------
//class HCatPic: public Pic
//{
//public:
//    HCatPic(int rs1, int cs1, char** arrayChars1,
//            int rs2, int cs2, char** arrayChars2);
//    HCatPic(const Pic& aLeftOrTop,
//            int rs2, int cs2, char** arrayChars2);
//    HCatPic(int rs1, int cs1, char** arrayChars1,
//            const Pic& aRightOrBottom);
//    HCatPic(const Pic& aLeftOrTop,
//            const Pic& aRightOrBottom);
//
//    virtual ~HCatPic() {}
//    virtual HCatPic* clone() override;
//    HCatPic& operator=(const HCatPic&)
//    {
//        return *this;
//    }
//
//    virtual void swapPic();
//
//    char** leftData;
//    char** rightData;
//};
//
//// -------------
//class VCatPic: public Pic
//{
//public:
//    VCatPic(int rs1, int cs1, char** arrayChars1,
//            int rs2, int cs2, char** arrayChars2);
//    VCatPic(const Pic& aLeftOrTop,
//            int rs2, int cs2, char** arrayChars2);
//    VCatPic(int rs1, int cs1, char** arrayChars1,
//            const Pic& aRightOrBottom);
//    VCatPic(const Pic& aLeftOrTop,
//            const Pic& aRightOrBottom);
//
//    virtual void swapPic();
//
//    virtual ~VCatPic() {}
//    virtual VCatPic* clone() override;
//    VCatPic& operator=(const VCatPic&)
//    {
//        return *this;
//    }
//
//    char** topData;
//    char** bottomData;
//};
//
//class CCatPic: public Pic
//{
//    CCatPic(int type, int rs1, int cs1, char** arrayChars1,
//            int rs2, int cs2, char** arrayChars2);
//    CCatPic(int type, const Pic& aLeftOrTop,
//            int rs2, int cs2, char** arrayChars2);
//    CCatPic(int type, int rs1, int cs1, char** arrayChars1,
//            const Pic& aRightOrBottom);
//    CCatPic(cint type, onst Pic& aLeftOrTop,
//            const Pic& aRightOrBottom);
//
//    virtual void swapPic();
//
//    virtual ~CCatPic() {}
//    virtual CCatPic* clone() override;
//    CCatPic& operator=(const CCatPic&)
//    {
//        return *this;
//    }
//
//    int type;
//    char** topData;
//    char** bottomData;
//};

#endif // PIC_H
