#include"Crafting.hpp"

Crafting::Crafting(){
    for (int i = 0; i < 9; i++){
        crafting[i] = SlotCrafting();
    }
}

Crafting::~Crafting(){

}

// add sebuah Item pada slot crafting ke i
void Crafting::addToCrafting(Item *a, int i){
    if (this->crafting[i].isSlotCraftingEmpty()){
        crafting[i].addSlotCrafting(a);
    } else {
        // exception
    }
}

// delete sebuah Item pada slot crafting ke i
void Crafting::deleteCrafting(int i){
    if (!this->crafting[i].isSlotCraftingEmpty()){
        crafting[i].dropSlotCrafting();
    } else {
        // exception
    }
}

Item* Crafting::getCrafting(int i){
    return crafting[i].getSlotCraftingItem();
}

void Crafting::printCrafting(){
    for (int i = 0; i < 9; i++){
        crafting[i].printSlotCrafting();
        if (i == 2 || i == 5 || i == 8){
            cout << "\n";
        }
    }
}