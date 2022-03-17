#ifndef DELETE_INVENTORY_EXP_H
#define DELETE_INVENTORY_EXP_H

#include "BaseException.hpp"

class DeleteInventoryException:public BaseException{
    void printMessage();
};


#endif