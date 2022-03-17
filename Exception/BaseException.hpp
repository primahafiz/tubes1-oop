#ifndef BASE_EXP_H
#define BASE_EXP_H

#include <iostream>
using namespace std;

class BaseException{
    public:
        virtual void printMessage()=0;
};

#endif