#include"SlotCrafting.hpp"


SlotCrafting::SlotCrafting(){
    this->slotItem = NULL;
}

SlotCrafting::SlotCrafting(Item *x){
    this->slotItem = x;
}

SlotCrafting::SlotCrafting(const SlotCrafting& a){
    this->slotItem = a.slotItem;
}

SlotCrafting::~SlotCrafting(){
    delete this->slotItem;
}

// cek apakah slot crafting empty
bool SlotCrafting::isSlotCraftingEmpty() const{
    return this->slotItem == NULL;
}

// cek apakah slot crafting sudah terisi
bool SlotCrafting::isSlotCraftingFilled() const{
    return (!this->isSlotCraftingEmpty());
}

// ambil item dari slot crafting
Item* SlotCrafting::getSlotCraftingItem() const{
    return this->slotItem;
}

// masukkan item ke slot crafting
void SlotCrafting::addSlotCrafting(Item *x){
    this->slotItem = x;
}

// buang item tool dari slot crafting
void SlotCrafting::dropSlotCrafting(){
    if (this->slotItem != NULL){
        this->slotItem = NULL;
    } else {
        // throw exception
    }
}

// tampilkan slot crafting
void SlotCrafting::printSlotCrafting(){
    if(this->slotItem==NULL){
        cout<<"[E]"<<string(7, ' ');
    }else{
        string output = "[" + to_string(this->slotItem->getID()) + "]";
        cout<<output<<string(10-output.length(), ' ');
    }    
}