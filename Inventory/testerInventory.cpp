#include <iostream>
#include "SlotInventory.hpp"
#include "../Item/Tool.hpp"

using namespace std;

int main(){
    SlotInventory s1,s2,s3;

    s1.addSlot(new Tool(1, "Pickaxe", "Iron", 10));
    s2.addSlot(new Tool(2, "Pickaxe", "Diamond", 10));
    s3.addSlot(new Tool(3, "Pickaxe", "Gold", 10));

    s1.printSlot();
    s2.printSlot();
    s3.printSlot();

    cout<<endl;

    s1.dropSlot();

    s1.printSlot();
    s2.printSlot();
    s3.printSlot();

    return 0;
}