#ifndef SLOT_CRAFTING_H
#define SLOT_CRAFTING_H

#include <iostream>
#include "../Item/Item.hpp"

using namespace std;

class SlotCrafting{
    private:
        Item *slotItem;
    public:
        SlotCrafting();
        SlotCrafting(Item *x);
        SlotCrafting(const SlotCrafting& a);
        ~SlotCrafting();

        // cek apakah slot crafting empty
        bool isSlotCraftingEmpty() const;

        // cek apakah slot crafting sudah terisi
        bool isSlotCraftingFilled() const;

        // ambil item dari slot crafting
        Item* getSlotCraftingItem() const;

        // masukkan item ke slot crafting
        void addSlotCrafting(Item *x);

        // buang item tool dari slot crafting
        void dropSlotCrafting();

        // tampilkan slot crafting
        void printSlotCrafting();
};


#endif