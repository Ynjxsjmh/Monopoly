///======================================================================
///  Project:   Richer04
/// FileName:	visitor.h
///     Desc:   Richer04
///   Author:	Chen Wei
///======================================================================
#ifndef VISITOR_H
#define VISITOR_H

class Male;
class Female;
class Visitor
{
public:
    Visitor(){}
    virtual ~Visitor(){}
    virtual void  visitMale(Male* male) = 0;
    virtual void  visitFemale(Female* female) = 0;
};

class LuckVisitor:public Visitor
{
public:
    LuckVisitor(){}
    virtual ~LuckVisitor(){}
    virtual void  visitMale(Male* male);
    virtual void  visitFemale(Female* female);
};
#endif // VISITOR_H
