#ifndef COMBINE_NULL_ITEM_EXP_H
#define COMBINE_NULL_ITEM_EXP_H

#include "BaseException.hpp"

class CombineNullItemException:public BaseException{
    void printMessage();
};

#endif