#ifndef CRAFTING_NULL_EXP_H
#define CRAFTING_NULL_EXP_H

#include "BaseException.hpp"

class CraftingNullException : public BaseException{
    void printMessage(){
        cout<<"Cannot get item from crafting because the crafting slot is empty"<<endl;
    }
};