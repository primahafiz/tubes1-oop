#ifndef ID_EXP_H
#define ID_EXP_H

#include "BaseException.hpp"

class IDException:public BaseException{
    void printMessage();
};

#endif