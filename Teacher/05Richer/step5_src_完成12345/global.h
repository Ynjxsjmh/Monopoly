///======================================================================
///  Project:   Richer02
/// FileName:	global.h
///     Desc:   Richer 02
///   Author:	Chen Wei
///======================================================================
#ifndef GLOBAL_H
#define GLOBAL_H

class MoveStateID
{
public:
    static const int MOVE_STATE_NORMAL = 0;
    static const int MOVE_STATE_FLY = 1;
    static const int MOVE_STATE_FREEZE = 2;
    static const int MOVE_STATE_COUNT = 3;
};
class StrategyID
{
public:
    static const int STRATEGY_RANDOM = 0;
    static const int STRATEGY_USER1 = 1;
    static const int STRATEGY_COUNT = 2;
};

class DirID
{
public:
    static const int DIR_NONE      = 0;
    static const int DIR_LEFT      = 1;
    static const int DIR_RIGHT     = 2;
    static const int DIR_UP        = 3;
    static const int DIR_DOWN      = 4;
    static const int DIR_COUNT     = 5;
public:
    static int oppositeDir(int inDir) {
        static const int oppDirs[] = { DIR_NONE, DIR_RIGHT, DIR_LEFT, DIR_DOWN, DIR_UP};
        return oppDirs[inDir];
    }
    static int leftDir(int inDir) {
        static const int dirs[] = { DIR_NONE, DIR_UP, DIR_DOWN, DIR_RIGHT, DIR_LEFT};
        return dirs[inDir];
    }
    static int rightDir(int inDir) {
        static const int dirs[] = { DIR_NONE, DIR_DOWN, DIR_UP, DIR_LEFT, DIR_RIGHT};
        return dirs[inDir];
    }
};

class MenuID
{
public:
    static const int MAIN_MENU      = 0;
    static const int PLAYERS_MENU   = 1;
    static const int LOAD_MENU      = 2;
    static const int SAVE_MENU      = 3;
    static const int OPTION_MENU    = 4;
    static const int VOLUME_MENU    = 5;
    static const int RESOLUTION_MENU = 6;
    static const int PLAY_MENU = 7;

    static const int MENU_COUNT = 8;
};


class BlockID
{
public:
    static const int NONE_BLOCK     = 0;
    static const int MONEY_BLOCK     = 1;
    static const int TRIP_BLOCK      = 2;
    static const int BAR_BLOCK       = 3;
    static const int SLIDE_BLOCK     = 4;

    static const int BLOCK_COUNT     = 5;

    static const int BLOCK_ROWS     = 5;
    static const int BLOCK_COLS     = 5;
};

#endif // GLOBAL_H
