#ifndef INVALID_ITEM_EXP
#define INVALID_ITEM_EXP

#include "BaseException.hpp"

class InvalidItemException:public BaseException{
    void printMessage();
};

#endif