#include"Crafting.hpp"

Crafting::Crafting(){
    for (int i = 0; i < 9; i++){
        crafting[i] = SlotCrafting();
    }
}

Crafting::~Crafting(){

}

void Crafting::printCrafting(){
    for (int i = 0; i < 9; i++){
        crafting[i].printSlotCrafting();
        if (i == 2 || i == 5 || i == 8){
            cout << "\n";
        }
    }
}