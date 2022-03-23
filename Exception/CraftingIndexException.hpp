#ifndef CRAFTING_INDEX_EXP_H
#define CRAFTING_INDEX_EXP_H

#include "BaseException.hpp"

class CraftingIndexException : public BaseException{
    void printMessage(){
        cout<<"Crafting slot out of bound"<<endl;
    }
};