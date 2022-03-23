#ifndef CRAFTING_FULL_EXP_H
#define CRAFTING_FULL_EXP_H

#include "BaseException.hpp"

class CraftingFullException : public BaseException{
    void printMessage(){
        cout<<"Cannot add to crafting because the crafting slot is filled"<<endl;
    }
};

#endif