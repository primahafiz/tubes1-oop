#ifndef CRAFTING_H
#define CRAFTING_H

#include "SlotCrafting.hpp"
#include "../Item/Item.hpp"
#include "../Item/Tool.hpp"
#include <map>
#include <string>

class Crafting
{
private:
    map<int, SlotCrafting> crafting;

public:
        Crafting();
        ~Crafting();
   
        // add sebuah Item pada slot crafting ke i
        void addToCrafting(Item *a, int i);
        // delete sebuah Item pada slot crafting ke i
        void deleteCrafting(int i);
        // mengambil item pada slot crafting ke i
        Item* getCrafting(int i);
        // clear crafting
        void clearCrafting();
        // cek apakah slot crafting ke i kosong
        bool isCraftingEmpty(int i);

        // swap position item i and j, untuk symmetry
        void swap(int i, int j);
        // membuat resep crafting yang direfleksi terhadap sumbu  y
        void symmetry();
        // mengubah crafting slot menjadi string
        string getStringCrafting();
        // helper function 
        bool Craftable(string X);
        // helper function 
        bool CraftableSymmetry (string X);

        // mengecek apakah craftable
        bool isCraftable(string X);

        // return total durability dari item yang ada di crafting
        int totalDurability();
        // mengecek apakah slot selain indeks a dan b kosong
        bool isOtherThanEmpty(int a, int b);

        // mengecek apakah kedua item tool craftable
        bool isToolCraftable();
        // crafting kedua item tool
        Item* getToolCraftable();

        // print slot crafting
        void printCrafting();
};

#endif