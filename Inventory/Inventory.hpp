#ifndef INVENTORY_H
#define INVENTORY_H

#include "SlotInventory.hpp"
#include "../Item/Item.hpp"
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
        void combineTwoItem(string ID1,string ID2);
        void exportInventory();
        void printInventory();
        int parsingID(string ID);
};

#endif