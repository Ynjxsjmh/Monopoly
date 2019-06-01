///======================================================================
///  Project:   Richer04
/// FileName:	command.h
///     Desc:   Richer04
///   Author:	Chen Wei
///======================================================================
#ifndef COMMAND_H
#define COMMAND_H

class Command
{
public:
    Command() {}
    virtual ~Command() {}
    virtual void excute() = 0;
};
class CardCommand: public Command
{
public:
    CardCommand() {}
    virtual ~CardCommand() {}
    virtual void excute() = 0;
};
class SpellCommand: public Command
{
public:
    SpellCommand() {}
    virtual ~SpellCommand() {}
    virtual void excute() = 0;
};
///-----------------------------------------
class RobCardCommand: public CardCommand
{
public:
    RobCardCommand(Player* src, Player* tgt);
    virtual ~RobCardCommand() {}
    virtual void excute();
private:
    Player* source;
    Player* target;
};
class MeanCardCommand: public CardCommand
{
public:
    MeanCardCommand() {}
    virtual ~MeanCardCommand() {}
    virtual void excute();
};
class FlyCardCommand: public CardCommand
{
public:
    FlyCardCommand(Player* tgt);
    virtual ~FlyCardCommand() {}
    virtual void excute();
private:
    Player* target;
};
///-----------------------------------------
class ReturnSpellCommand: public SpellCommand
{
public:
    ReturnSpellCommand(Player* tgt);
    virtual ~ReturnSpellCommand() {}
    virtual void excute();
private:
    Player* target;
};
class FreezeSpellCommand: public SpellCommand
{
public:
    FreezeSpellCommand(Player* tgt);
    virtual ~FreezeSpellCommand() {}
    virtual void excute();
private:
    Player* target;
};
#endif // COMMAND_H
