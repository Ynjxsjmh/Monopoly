///======================================================================
///  Project:   Richer04
/// FileName:	gender.cpp
///     Desc:   Richer04
///   Author:	Chen Wei
///======================================================================
#include "gender.h"
#include "visitor.h"

void Male::accept(Visitor& v)
{
    v.visitMale(this);
}
void Female::accept(Visitor& v)
{
    v.visitFemale(this);
}
