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
        Crafting(const Crafting& c);
        ~Crafting();

        
        // add sebuah Item pada slot crafting ke i
        void addToCrafting(Item *a, int i);
        // delete sebuah Item pada slot crafting ke i
        void deleteCrafting(int i);
        // mengambil item pada slot crafting ke i
        Item* getCrafting(int i);
        // clear crafting
        void clearCrafting();
        // cek empty
        bool isCraftingEmpty(int i);


        // swap position item i and j
        void swap(int i, int j);
        // membuat resep crafting yang direfleksi terhadap sumbu  y
        void symmetry();
        // mengecek apakah craftable
        bool isCraftable(string X);

        // return total durability dari item yang ada di crafting
        int totalDurability();
        
        void printCrafting();

};

#endif