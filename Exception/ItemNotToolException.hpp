#ifndef ITEM_NOT_TOOL_EXP
#define ITEM_NOT_TOOL_EXP

#include "BaseException.hpp"

class ItemNotToolException:public BaseException{
    void printMessage();
};

#endif