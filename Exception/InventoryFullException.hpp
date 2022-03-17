#ifndef INVENTORY_FULL_EXP_H
#define INVENTORY_FULL_EXP_H

#include "BaseException.hpp"

class InventoryFullException:public BaseException{
    void printMessage();
};


#endif