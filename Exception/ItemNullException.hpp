#ifndef ITEM_NULL_EXP
#define ITEM_NULL_EXP

#include "BaseException.hpp"

class ItemNullException:public BaseException{
    void printMessage();
};

#endif