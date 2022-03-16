#include "SlotInventory.hpp"


SlotInventory::SlotInventory(){
    this->slotItem=NULL;
}
SlotInventory::SlotInventory(Item *x){
    this->slotItem=x;
}
SlotInventory::SlotInventory(const SlotInventory& a){
    this->slotItem=a.getSlotItem();
}
SlotInventory::~SlotInventory(){
    delete this->slotItem;
}

bool SlotInventory::isSlotEmpty() const{
    return this->slotItem==NULL;
}
bool SlotInventory::isSlotFull() const{
    return !this->isSlotEmpty();
}
Item* SlotInventory::getSlotItem() const{
    return this->slotItem;
}
bool SlotInventory::canBeAdded(int num) const{
    return this->slotItem->getQuantity();
}

void SlotInventory::addSlot(Item *x){
    this->slotItem=x;
}
void SlotInventory::dropSlot(){
    this->slotItem=NULL;
}
void SlotInventory::dropSlot(int num){
    if(this->getSlotItem()->getQuantity()-num>=0){
        this->slotItem->setQuantity(this->slotItem->getQuantity()-num);
        if(this->slotItem->getQuantity()==0){
            this->slotItem=NULL;
        }
    }else{
        //throw exception
    }
}
void SlotInventory::addQuantity(int num){
    this->slotItem->setQuantity(this->slotItem->getQuantity()+num);
}

void SlotInventory::printSlot(){
    if(this->slotItem==NULL){
        cout<<"[E]";
    }else{
        cout<<"["<<this->slotItem->getID()<<"]";
    }
}