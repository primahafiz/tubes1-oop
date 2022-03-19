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

        // add sebuah Item pada slot crafting ke i
        void addToCrafting(Item *a, int i);
        // delete sebuah Item pada slot crafting ke i
        void deleteCrafting(int i);
        Item* getCrafting(int i);
        void printCrafting();

};

#endif