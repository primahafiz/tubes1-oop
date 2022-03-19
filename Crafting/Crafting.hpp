#ifndef CRAFTING_H
#define CRAFTING_H

#include "SlotCrafting.hpp"
#include "../Item/Item.hpp"
#include <map>

class Crafting{
    private:
        map<int,SlotCrafting> crafting;
    public:
        Crafting();
        ~Crafting();

        void printCrafting();

};

#endif