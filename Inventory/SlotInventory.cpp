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
    if(this->isSlotEmpty()){
        throw new DeleteInventoryException();
    }else if(this->getSlotItem()->isTool()){
        this->dropSlot();
    }else if(this->getSlotItem()->getQuantity()-num>=0){
        this->slotItem->setQuantity(this->slotItem->getQuantity()-num);
        if(this->slotItem->getQuantity()==0){
            this->slotItem=NULL;
        }
    }else{
        throw new DeleteInventoryException();
    }
}

void SlotInventory::addQuantity(int num){
    this->slotItem->setQuantity(this->slotItem->getQuantity()+num);
}

void SlotInventory::printSlot(bool isNewLine){
    if(this->slotItem==NULL){
        cout<<"[E]";
        if(isNewLine){
            cout<<endl;
        }else{
            printSpace(7);
        }
    }else{
        cout<<"["<<this->slotItem->getID()<<"(";
        if(this->slotItem->isTool()){
            cout<<this->slotItem->getDurability();
        }else{
            cout<<this->slotItem->getQuantity();
        }
        cout<<")]";
        if(isNewLine){
            cout<<endl;
        }else if(this->slotItem->isTool()){
            printSpace(4-(this->slotItem->getID()<10?0:1)-(this->slotItem->getDurability()<10?0:1));
        }else{
            printSpace(4-(this->slotItem->getID()<10?0:1)-(this->slotItem->getQuantity()<10?0:1));
        }
    }
}

void SlotInventory::printSpace(int num){
    for(int i=0;i<num;i++){
        cout<<" ";
    }
}