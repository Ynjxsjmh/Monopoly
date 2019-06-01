#ifndef CHARPIC_H
#define CHARPIC_H


class CharPic
{
public:
    CharPic(int type, int rs, int cs, char** arrayChars);
    CharPic(int type,
            const CharPic& aCenter);
    CharPic(int type,
            int rs1, int cs1, char** arrayChars1,
            int rs2, int cs2, char** arrayChars2);
    CharPic(int type,
            const CharPic& aLeftOrTop,
            int rs2, int cs2, char** arrayChars2);
    CharPic(int type,
            int rs1, int cs1, char** arrayChars1,
            const CharPic& aRightOrBottom);
    CharPic(int type,
            const CharPic& aLeftOrTop,
            const CharPic& aRightOrBottom);
    ~CharPic();

    CharPic(const CharPic&);
    CharPic& operator=(const CharPic&);
    virtual void display() const;

	virtual int getRows() const;
	virtual int getCols() const;
	virtual char** getData() const;

private:
    virtual void initData();

private:
    int rows;
    int cols;
    char** data;
};

#endif // CHARPIC_H
