// #include <iostream>
// #include "SlotInventory.hpp"
// #include "../Item/Tool.hpp"
// #include "../Item/nonTool.hpp"

// using namespace std;

// int main(){
//     SlotInventory s1,s2,s3,s4;

//     s1.addSlot(new Tool(1, "Pickaxe", "Iron", 10));
//     s2.addSlot(new Tool(2, "Pickaxe", "Diamond", 10));
//     s3.addSlot(new Tool(3, "Pickaxe", "Gold", 10));

//     s1.printSlot();
//     s2.printSlot();
//     s3.printSlot();

//     cout<<endl;

//     s1.dropSlot();

//     s1.printSlot();
//     s2.printSlot();
//     s3.printSlot();

//     cout<<endl;

//     s4.addSlot(new nonTool(5, "stick", "gold", 5));

//     cout<<s4.getSlotItem()->getQuantity()<<endl;

//     return 0;
// }