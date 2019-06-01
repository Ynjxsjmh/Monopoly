#ifndef PIC_H
#define PIC_H

class Pic
{
public:
    Pic();
    Pic(const Pic & pic);
    Pic& operator=(const Pic& pic);

    virtual ~Pic();
    virtual Pic* clone() = 0;

    virtual void display() const;

    int getRows() const;
    int getCols() const;
    char** getData() const;

    void addReference();
    void removeReference();

protected:
    virtual void createData();
    virtual void initData();

protected:
    int refCount;

protected:
    int rows;
    int cols;
    char** data;
};

// -------------
class SimplePic: public Pic
{
public:
    SimplePic(int rs, int cs, char** arrayData);

    virtual ~SimplePic() {}
    virtual SimplePic* clone() override;

    SimplePic& operator=(const SimplePic&)
    {
        return *this;
    }

};

// -------------
class FramePic: public Pic
{
public:
    FramePic(int rs, int cs, char** arrayChar);
    FramePic(const Pic& aCenter);

    virtual ~FramePic() {}

    virtual FramePic* clone() override;
    FramePic& operator=(const FramePic&)
    {
        return *this;
    }
};

// -------------
class HCatPic: public Pic
{
public:
    HCatPic(int rs1, int cs1, char** arrayChars1,
            int rs2, int cs2, char** arrayChars2);
    HCatPic(const Pic& aLeftOrTop,
            int rs2, int cs2, char** arrayChars2);
    HCatPic(int rs1, int cs1, char** arrayChars1,
            const Pic& aRightOrBottom);
    HCatPic(const Pic& aLeftOrTop,
            const Pic& aRightOrBottom);

    virtual ~HCatPic();   //because the sub pic is from clone method, so if the precious object has been deleted, there is no need to delete them again.

    virtual HCatPic* clone() override;
    HCatPic& operator=(const HCatPic&)
    {
        return *this;
    }

    const Pic* leftPic;
    const Pic* rightPic;
};

// -------------
class VCatPic: public Pic
{
public:
    VCatPic(int rs1, int cs1, char** arrayChars1,
            int rs2, int cs2, char** arrayChars2);
    VCatPic(const Pic& aLeftOrTop,
            int rs2, int cs2, char** arrayChars2);
    VCatPic(int rs1, int cs1, char** arrayChars1,
            const Pic& aRightOrBottom);
    VCatPic(const Pic& aLeftOrTop,
            const Pic& aRightOrBottom);

    virtual ~VCatPic();

    virtual VCatPic* clone() override;
    VCatPic& operator=(const VCatPic&)
    {
        return *this;
    }

    const Pic* topPic;
    const Pic* bottomPic;
};


#endif // PIC_H
