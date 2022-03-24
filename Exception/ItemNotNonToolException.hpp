#ifndef ITEM_NOT_NON_TOOL_EXP
#define ITEM_NOT_NON_TOOL_EXP

#include "BaseException.hpp"

class ItemNotNonToolException:public BaseException{
    void printMessage();
};

#endif