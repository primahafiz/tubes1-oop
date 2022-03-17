#ifndef COMBINE_DIFFERENT_ITEM_EXP_H
#define COMBINE_DIFFERENT_ITEM_EXP_H

#include "BaseException.hpp"

class CombineDifferentItemException:public BaseException{
    void printMessage();
};

#endif