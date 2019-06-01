#ifndef PICIMP_H
#define PICIMP_H

#include <map>

class PicImp
{
public:
    PicImp();
    virtual ~PicImp();
    PicImp(const PicImp & picImp);
    PicImp& operator=(const PicImp& picImp);

    int getRows() const;
    int getCols() const;
    char** getData() const;

public:
    virtual PicImp* clone() =0;

    virtual void display(int indentationNum, bool isEncryption);
    virtual void swapPic() {}

protected:
    int rows;
    int cols;
    char** data;

protected:
    virtual void createData();
    virtual void initData();

protected:
    map<char, char> encryptionMap;
};

// ----------
class SimplePic: public PicImp
{
public:
    SimplePic(int rs, int cs, char** arrayChars);
    virtual ~SimplePic();

    virtual SimplePic* clone() override;

    SimplePic& operator=(const SimplePic&)
    {
        return *this;
    }
};

// ----------
class FramePic: public PicImp
{
public:
    FramePic(int rs, int cs, char** arrayChars);
    FramePic(const PicImp& aCenter);
    virtual ~FramePic();

    virtual FramePic* clone() override;

    FramePic& operator=(const FramePic&)
    {
        return *this;
    }

public:
    virtual void setHSym(char HSym);
    virtual void setVSym(char VSym);

protected:
    char HSym;
    char VSym;
};

// ----------
class HCatPic: public PicImp
{
public:
    HCatPic(int rs1, int cs1, char** arrayChars1,
            int rs2, int cs2, char** arrayChars2);
    HCatPic(const PicImp& aLeftOrTop,
            int rs2, int cs2, char** arrayChars2);
    HCatPic(int rs1, int cs1, char** arrayChars1,
            const PicImp& aRightOrBottom);
    HCatPic(const PicImp& aLeftOrTop,
            const PicImp& aRightOrBottom);

    virtual ~HCatPic();

    virtual HCatPic* clone() override;

    HCatPic& operator=(const HCatPic&)
    {
        return *this;
    }

    virtual void swapPic();

    PicImp* leftPic;
    PicImp* rightPic;
};

// ----------
class VCatPic: public PicImp
{
public:
    VCatPic(int rs1, int cs1, char** arrayChars1,
            int rs2, int cs2, char** arrayChars2);
    VCatPic(const PicImp& aLeftOrTop,
            int rs2, int cs2, char** arrayChars2);
    VCatPic(int rs1, int cs1, char** arrayChars1,
            const PicImp& aRightOrBottom);
    VCatPic(const PicImp& aLeftOrTop,
            const PicImp& aRightOrBottom);

    virtual ~VCatPic();

    VCatPic& operator=(const VCatPic&)
    {
        return *this;
    }

    virtual void swapPic();
    virtual VCatPic* clone() override;

    PicImp* topPic;
    PicImp* bottomPic;
};


// -------
class CCatPic: public PicImp
{
public:
    CCatPic(int type, int rs1, int cs1, char** arrayChars1,
            int rs2, int cs2, char** arrayChars2);
    CCatPic(int type, const PicImp& aLeftOrTop,
            int rs2, int cs2, char** arrayChars2);
    CCatPic(int type, int rs1, int cs1, char** arrayChars1,
            const PicImp& aRightOrBottom);
    CCatPic(int type, const PicImp& aLeftOrTop,
            const PicImp& aRightOrBottom);

    virtual ~CCatPic();

    CCatPic& operator=(const CCatPic&)
    {
        return *this;
    }

    virtual CCatPic* clone() override;
    virtual void swapPic() {}

    PicImp* topPic;
    PicImp* bottomPic;
};

#endif // PICIMP_H
