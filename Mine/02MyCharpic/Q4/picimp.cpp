#include <iostream>
using namespace std;

#include "picimp.h"
#include "pic.h"
#include "global.h"

PicImp::PicImp()
{
    //ctor
    for(int i=0; i<26; i++)
    {
        this->encryptionMap['A'+i] = ('a' + i);  //converse the upper to the lower
        this->encryptionMap['a'+i] = ('A' + i);
    }
}

PicImp::~PicImp()
{
    //dtor
    for(int i=0; i<rows; i++)
    {
        delete[] data[i];
    }
    delete[] data;
}

PicImp& PicImp::operator=(const PicImp& picImp)
{
    return *this;
}

PicImp::PicImp(const PicImp& picImp)
{
    this->rows = picImp.rows;
    this->cols = picImp.cols;
    this->data = picImp.data;
}

int PicImp::getRows() const
{
    return this->rows;
}

int PicImp::getCols() const
{
    return this->cols;
}

char** PicImp::getData() const
{
    return this->data;
}

void PicImp::display(int indentationNum, bool isEncryption)
{
    string indent = " ";
    for(int i=0; i<indentationNum-1; i++)
    {
        indent.append(" ");
    }

    for (int i=0; i<this->rows; i++)
    {
        cout<<"\n";
        for (int j=0; j<this->cols; j++)
        {
            if (isEncryption && this->data[i][j] != ' ')
            {
                cout<< this->encryptionMap[this->data[i][j]];
            }
            else
            {
                cout<< this->data[i][j];
            }
            if(indentationNum!=0 && j!=this->cols-1)
                cout<<indent;
        }
    }
}

void PicImp::createData()
{
    this->data = new char* [this->rows];
    for (int i=0; i<this->rows; i++)
    {
        this->data[i] = new char[this->cols];
    }

    this->initData();
}

void PicImp::initData()
{
    for (int i=0; i<this->rows; i++)
    {
        for (int j=0; j<this->cols; j++)
        {
            this->data[i][j] = ' ';
        }
    }
}

// ----------

SimplePic::~SimplePic()
{
    //dtor

}

SimplePic::SimplePic(int rs, int cs, char** arrayChars)
{
    this->rows = rs;
    this->cols = cs;

    this->createData();

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

// ---------
FramePic::~FramePic()
{
    //dtor

}

FramePic::FramePic(int rs, int cs, char** arrayChars)
    : HSym('-'), VSym('|')
{
    this->rows = rs + 2;
    this->cols = cs + 2;

    this->createData();

    for (int i=1; i<(this->rows-1); i++)
    {
        for (int j=1; j<(this->cols-1); j++)
        {
            this->data[i][j] = arrayChars[i-1][j-1];
        }
    }

    for (int i=0; i<this->cols; i++)
    {
        this->data[0][i] = this->HSym;
        this->data[this->rows-1][i] = this->HSym;
    }

    for (int i=0; i<this->rows; i++)
    {
        this->data[i][0] = this->VSym;
        this->data[i][this->cols-1] = this->VSym;
    }
}

FramePic::FramePic(const PicImp& aCenter)
    : HSym('-'), VSym('|')
{
    this->rows = aCenter.getRows() + 2;
    this->cols = aCenter.getCols() + 2;

    this->createData();

    for (int i=1; i<this->rows-1; i++)
    {
        for (int j=1; j<this->cols-1; j++)
        {
            this->data[i][j] = aCenter.getData()[i-1][j-1];
        }
    }

    for (int i=0; i<this->cols; i++)
    {
        this->data[0][i] = this->HSym;
        this->data[this->rows-1][i] = this->HSym;
    }

    for (int i=0; i<this->rows; i++)
    {
        this->data[i][0] = this->VSym;
        this->data[i][this->cols-1] = this->VSym;
    }
}

void FramePic::setHSym(char HSym)
{
    this->HSym = HSym;
    for (int i=0; i<this->cols; i++)
    {
        this->data[0][i] = this->HSym;
        this->data[this->rows-1][i] = this->HSym;
    }
}

void FramePic::setVSym(char VSym)
{
    this->VSym = VSym;
    for (int i=0; i<this->rows; i++)
    {
        this->data[i][0] = this->VSym;
        this->data[i][this->cols-1] = this->VSym;
    }
}

FramePic* FramePic::clone()
{
    return new FramePic(*this);
}

// ----------
HCatPic::~HCatPic()
{
    //dtor

}

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

HCatPic::HCatPic(const PicImp& aLeftOrTop,
                 int rs2, int cs2, char** arrayChars2)
{
    int rs1 = aLeftOrTop.getRows();
    int cs1 = aLeftOrTop.getCols();
    char** arrayChars1 = aLeftOrTop.getData();

    this->leftPic = new SimplePic(rs1, cs1, arrayChars1);
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
                 const PicImp& aRightOrBottom)
{
    this->leftPic = new SimplePic(rs1, cs1, arrayChars1);

    int rs2 = aRightOrBottom.getRows();
    int cs2 = aRightOrBottom.getCols();
    char** arrayChars2 = aRightOrBottom.getData();

    this->rightPic = new SimplePic(rs2, cs2, arrayChars2);

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

HCatPic::HCatPic(const PicImp& aLeftOrTop,
                 const PicImp& aRightOrBottom)
{
    int rs1 = aLeftOrTop.getRows();
    int cs1 = aLeftOrTop.getCols();
    char** arrayChars1 = aLeftOrTop.getData();

    int rs2 = aRightOrBottom.getRows();
    int cs2 = aRightOrBottom.getCols();
    char** arrayChars2 = aRightOrBottom.getData();

    this->leftPic = new SimplePic(rs1, cs1, arrayChars1);
    this->rightPic = new SimplePic(rs2, cs2, arrayChars2);

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

void HCatPic::swapPic()
{
    PicImp* tempPic;
    tempPic = this->leftPic;
    this->leftPic = this->rightPic;
    this->rightPic = tempPic;

    char** arrayChars1 = this->leftPic->getData();
    char** arrayChars2 = this->rightPic->getData();
    int rs1 = this->leftPic->getRows();
    int cs1 = this->leftPic->getCols();
    int rs2 = this->rightPic->getRows();

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

HCatPic* HCatPic::clone()
{
    return new HCatPic(*this);
}

//--------
VCatPic::~VCatPic()
{
    //dtor

}


VCatPic::VCatPic(int rs1, int cs1, char** arrayChars1,
                 int rs2, int cs2, char** arrayChars2)
{
    this->topPic = new SimplePic(rs1, cs1, arrayChars1);
    this->bottomPic = new SimplePic(rs2, cs2, arrayChars2);

    this->rows = rs1 + rs2;
    this->cols = (cs1 > cs2) ? cs1 : cs2;

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

VCatPic::VCatPic(const PicImp& aLeftOrTop,
                 int rs2, int cs2, char** arrayChars2)
{
    int rs1 = aLeftOrTop.getRows();
    int cs1 = aLeftOrTop.getCols();
    char** arrayChars1 = aLeftOrTop.getData();

    this->topPic = new SimplePic(rs1, cs1, arrayChars1);
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
                 const PicImp& aRightOrBottom)
{
    this->topPic = new SimplePic(rs1, cs1, arrayChars1);

    int rs2 = aRightOrBottom.getRows();
    int cs2 = aRightOrBottom.getCols();
    char** arrayChars2 = aRightOrBottom.getData();

    this->bottomPic = new SimplePic(rs2, cs2, arrayChars2);

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

VCatPic::VCatPic(const PicImp& aLeftOrTop,
                 const PicImp& aRightOrBottom)
{
    int rs1 = aLeftOrTop.getRows();
    int cs1 = aLeftOrTop.getCols();
    char** arrayChars1 = aLeftOrTop.getData();

    int rs2 = aRightOrBottom.getRows();
    int cs2 = aRightOrBottom.getCols();
    char** arrayChars2 = aRightOrBottom.getData();

    this->topPic = new SimplePic(rs1, cs1, arrayChars1);
    this->bottomPic = new SimplePic(rs2, cs2, arrayChars2);

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

void VCatPic::swapPic()
{
    PicImp* tempPic;
    tempPic = this->topPic;
    this->topPic = this->bottomPic;
    this->bottomPic = tempPic;

    char** arrayChars1 = this->topPic->getData();
    char** arrayChars2 = this->bottomPic->getData();
    int rs1 = this->topPic->getRows();
    int cs1 = this->topPic->getCols();
    int rs2 = this->bottomPic->getRows();

    for (int i=0; i<this->rows; i++)
    {
        for (int j=0; j<this->cols; j++)
        {
            if (i<rs1 && j<cs1)
            {
                this->data[i][j] = arrayChars1[i][j];
            }
            else if (i >= rs1 && j < rs2)
            {
                this->data[i][j] = arrayChars2[i-rs1][j];
            }

        }
    }
}

VCatPic* VCatPic::clone()
{
    return new VCatPic(*this);
}

// ------------

CCatPic::~CCatPic()
{
    //dtor

}

CCatPic::CCatPic(int type, int rs1, int cs1, char** arrayChars1,
                 int rs2, int cs2, char** arrayChars2)
{
    this->topPic = new SimplePic(rs1, cs1, arrayChars1);
    this->bottomPic = new SimplePic(rs2, cs2, arrayChars2);

    this->rows = rs1 + rs2;
    this->cols = cs1 + cs2;

    this->createData();

    if (type == CrossType::NW_TO_SE)
    {
        for (int i=0; i<this->rows; i++)
        {
            for (int j=0; j<this->cols; j++)
            {
                if (i<rs1 && j<cs1)
                {
                    this->data[i][j] = arrayChars1[i][j];
                }
                else if (i >= rs1 && j >= cs1)
                {
                    this->data[i][j] = arrayChars2[i-rs1][j-cs1];
                }
            }
        }
    }
    else if (type == CrossType::SW_TO_NE)
    {
        for (int i=0; i<this->rows; i++)
        {
            for (int j=0; j<this->cols; j++)
            {
                if (i>=rs2 && j<cs1)
                {
                    this->data[i][j] = arrayChars1[i-rs2][j];
                }
                else if (i <rs2 && j >= cs1)
                {
                    this->data[i][j] = arrayChars2[i][j-cs1];
                }
            }
        }
    }
}

CCatPic::CCatPic(int type, const PicImp& aLeftOrTop,
                 int rs2, int cs2, char** arrayChars2)
{
    this->bottomPic = new SimplePic(rs2, cs2, arrayChars2);

    int rs1 = aLeftOrTop.getRows();
    int cs1 = aLeftOrTop.getCols();
    char** arrayChars1 = aLeftOrTop.getData();

    this->topPic = new SimplePic(rs1, cs1, arrayChars1);

    this->rows = rs1 + rs2;
    this->cols = cs1 + cs2;

    this->createData();

    if (type == CrossType::NW_TO_SE)
    {
        for (int i=0; i<this->rows; i++)
        {
            for (int j=0; j<this->cols; j++)
            {
                if (i<rs1 && j<cs1)
                {
                    this->data[i][j] = arrayChars1[i][j];
                }
                else if (i >= rs1 && j >= cs1)
                {
                    this->data[i][j] = arrayChars2[i-rs1][j-cs1];
                }
            }
        }
    }
    else if (type == CrossType::SW_TO_NE)
    {
        for (int i=0; i<this->rows; i++)
        {
            for (int j=0; j<this->cols; j++)
            {
                if (i>=rs2 && j<cs1)
                {
                    this->data[i][j] = aLeftOrTop.getData()[i-rs2][j];
                }
                else if (i <rs2 && j >= cs1)
                {
                    this->data[i][j] = arrayChars2[i][j-cs1];
                }
            }
        }
    }
}

CCatPic::CCatPic(int type, int rs1, int cs1, char** arrayChars1,
                 const PicImp& aRightOrBottom)
{
    this->topPic = new SimplePic(rs1, cs1, arrayChars1);

    int rs2 = aRightOrBottom.getRows();
    int cs2 = aRightOrBottom.getCols();
    char** arrayChars2 = aRightOrBottom.getData();

    this->bottomPic = new SimplePic(rs2, cs2, arrayChars2);

    this->rows = rs1 + rs2;
    this->cols = cs1 + cs2;

    this->createData();

    if (type == CrossType::NW_TO_SE)
    {
        for (int i=0; i<this->rows; i++)
        {
            for (int j=0; j<this->cols; j++)
            {
                if (i<rs1 && j<cs1)
                {
                    this->data[i][j] = arrayChars1[i][j];
                }
                else if (i >= rs1 && j >= cs1)
                {
                    this->data[i][j] = arrayChars2[i-rs1][j-cs1];
                }
            }
        }
    }
    else if (type == CrossType::SW_TO_NE)
    {
        for (int i=0; i<this->rows; i++)
        {
            for (int j=0; j<this->cols; j++)
            {
                if (i>=rs2 && j<cs1)
                {
                    this->data[i][j] = arrayChars1[i-rs2][j];
                }
                else if (i <rs2 && j >= cs1)
                {
                    this->data[i][j] = arrayChars2[i][j-cs1];
                }
            }
        }
    }
}


CCatPic::CCatPic(int type, const PicImp& aLeftOrTop,
                 const PicImp& aRightOrBottom)
{
    int rs1 = aLeftOrTop.getRows();
    int cs1 = aLeftOrTop.getCols();
    char** arrayChars1 = aLeftOrTop.getData();

    int rs2 = aRightOrBottom.getRows();
    int cs2 = aRightOrBottom.getCols();
    char** arrayChars2 = aRightOrBottom.getData();

    this->topPic = new SimplePic(rs1, cs1, arrayChars1);
    this->bottomPic = new SimplePic(rs2, cs2, arrayChars2);

    this->rows = rs1 + rs2;
    this->cols = cs1 + cs2;

    this->createData();

    if (type == CrossType::NW_TO_SE)
    {
        for (int i=0; i<this->rows; i++)
        {
            for (int j=0; j<this->cols; j++)
            {
                if (i<rs1 && j<cs1)
                {
                    this->data[i][j] = arrayChars1[i][j];
                }
                else if (i >= rs1 && j >= cs1)
                {
                    this->data[i][j] = arrayChars2[i-rs1][j-cs1];
                }
            }
        }
    }
    else if (type == CrossType::SW_TO_NE)
    {
        for (int i=0; i<this->rows; i++)
        {
            for (int j=0; j<this->cols; j++)
            {
                if (i>=rs2 && j<cs1)
                {
                    this->data[i][j] = arrayChars1[i-rs2][j];
                }
                else if (i <rs2 && j >= cs1)
                {
                    this->data[i][j] = arrayChars2[i][j-cs1];
                }
            }
        }
    }
}

CCatPic* CCatPic::clone()
{
    return new CCatPic(*this);
}
