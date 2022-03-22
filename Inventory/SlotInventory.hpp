#ifndef SLOT_INVENTORY_H
#define SLOT_INVENTORY_H

#include <iostream>
#include <iomanip>
#include "../Item/Item.hpp"
#include "../Exception/DeleteInventoryException.hpp"

using namespace std;

class SlotInventory{
    private:
        Item *slotItem;
    public:
        SlotInventory();
        SlotInventory(Item *x);
        SlotInventory(const SlotInventory& a);
        ~SlotInventory();

        // cek apakah slot empty
        bool isSlotEmpty() const;

        // cek apakah slot full
        bool isSlotFull() const;

        // cek apkah bisa ditambahkan quantity sebesar num(total quantity akhir<=64) untuk item non tool
        bool canBeAdded(int num) const;

        // ambil item dari slot
        Item* getSlotItem() const;

        // masukkan item ke slot
        void addSlot(Item *x);

        // buang item tool dari slot
        void dropSlot();

        // buang item non tool dari slot sebesar num
        void dropSlot(int num);

        // tambahkan quantity item non tool sebesar num
        void addQuantity(int num);

        // tampilkan slot
        void printSlot(bool isNewLine);

        // print newline
        void printSpace(int num);
};


#endif