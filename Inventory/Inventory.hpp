#ifndef INVENTORY_H
#define INVENTORY_H

#include "SlotInventory.hpp"
#include <fstream>
#include <string>
#include "../Item/Item.hpp"
#include "../Item/nonTool.hpp"
#include "../Exception/DeleteInventoryException.hpp"
#include "../Exception/InventoryFullException.hpp"
#include "../Exception/CombineNullItemException.hpp"
#include "../Exception/CombineDifferentItemException.hpp"
#include <algorithm>

class Inventory{
    private:
        SlotInventory* inventory;
    public:
        Inventory();
        ~Inventory();
        Inventory(const Inventory&);

        void addToInventory(Item *a);
        void addToInventory(string ID,Item *a);
        int getAvailableSlot(Item *a);
        void deleteFromInventory(string ID,int num);
        Item* getInventory(int k);
        void combineTwoItem(string IDSrc,string IDDest);
        void exportInventory(string path);
        void printInventory();
        int parsingID(string ID);
};

#endif