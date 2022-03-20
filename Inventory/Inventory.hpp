#ifndef INVENTORY_H
#define INVENTORY_H

#include "SlotInventory.hpp"
#include "../Item/Item.hpp"
#include "../Exception/DeleteInventoryException.hpp"
#include "../Exception/InventoryFullException.hpp"
#include "../Exception/CombineNullItemException.hpp"
#include "../Exception/CombineDifferentItemException.hpp"
#include <map>
#include <algorithm>

class Inventory{
    private:
        map<int,SlotInventory>inventory;
    public:
        Inventory();
        ~Inventory();

        void addToInventory(Item *a);
        void deleteFromInventory(string ID,int num);
        Item* getInventory(int k);
        void combineTwoItem(string IDSrc,string IDDest);
        void exportInventory();
        void printInventory();
        int parsingID(string ID);
};

#endif