#ifndef CHARPIC_H
#define CHARPIC_H

class CharPic
{
public:
    CharPic();
    virtual ~CharPic();

    CharPic(const CharPic&);
    CharPic& operator=(const CharPic&);
    virtual void display() const;

    virtual int getRows() const;
    virtual int getCols() const;
    virtual char** getData() const;

    virtual void initData();

public:
    int rows;
    int cols;
    char** data;
};

#endif // CHARPIC_H
