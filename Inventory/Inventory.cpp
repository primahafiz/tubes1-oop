#include "Inventory.hpp"


Inventory::Inventory(){
    for(int i=0;i<27;i++){
        inventory[i]=SlotInventory();
    }
}
Inventory::~Inventory(){
    //
}

void Inventory::addToInventory(Item *a){
    if(!a->isTool()){
        for(int i=0;i<27;i++){
            if(inventory[i].isSlotEmpty())continue;
            if(inventory[i].getSlotItem()->getName()==a->getName()){
                if(inventory[i].canBeAdded(a->getQuantity())){
                    inventory[i].addQuantity(a->getQuantity());
                    return;
                }
            }
        }
    }
    for(int i=0;i<27;i++){
        if(inventory[i].isSlotEmpty()){
            inventory[i].addSlot(a);
            return;
        }
    }
    throw InventoryFullException();
}
void Inventory::deleteFromInventory(string ID,int num){
    int slotId=this->parsingID(ID);
    if(inventory[slotId].isSlotEmpty()){
        throw DeleteInventoryException();
    }else if(inventory[slotId].getSlotItem()->isTool()){
        if(num==1){
            inventory[slotId].dropSlot();
        }else{
            throw DeleteInventoryException();
        }
    }else if(!inventory[slotId].getSlotItem()->isTool()){
        if(num<=inventory[slotId].getSlotItem()->getQuantity()){
            inventory[slotId].dropSlot(num);
        }else{
            throw DeleteInventoryException();
        }
    }
}
void Inventory::combineTwoItem(string IDSrc,string IDDest){
    int slotId1=this->parsingID(IDSrc);
    int slotId2=this->parsingID(IDDest);
    if(inventory[slotId1].isSlotEmpty() || inventory[slotId2].isSlotEmpty()){
        throw CombineNullItemException();
    }else if(!inventory[slotId1].getSlotItem()->isTool() && !inventory[slotId2].getSlotItem()->isTool() && inventory[slotId1].getSlotItem()->getName()==inventory[slotId1].getSlotItem()->getName()){
        if(inventory[slotId1].getSlotItem()->getQuantity()+inventory[slotId2].getSlotItem()->getQuantity()>64){
            inventory[slotId1].getSlotItem()->setQuantity(inventory[slotId1].getSlotItem()->getQuantity()-(64-inventory[slotId2].getSlotItem()->getQuantity()));
            inventory[slotId2].getSlotItem()->setQuantity(64);
        }else{
            inventory[slotId2].getSlotItem()->setQuantity(inventory[slotId1].getSlotItem()->getQuantity()+inventory[slotId2].getSlotItem()->getQuantity());
            inventory[slotId1].dropSlot(inventory[slotId1].getSlotItem()->getQuantity());
        }
    }else{
        throw CombineDifferentItemException();
    }
}
void Inventory::exportInventory(){
    //
}
void Inventory::printInventory(){
    for(int i=0;i<27;i++){
        inventory[i].printSlot();
        if((i+1)%9==0){
            cout<<endl;
        }else{
            cout<<" ";
        }
    }
}
int Inventory::parsingID(string ID){
    int ans=0;
    int mul=1;
    int n=ID.size();
    for(int i=n-1;i>0;i--){
        ans+=(ID[i]-'0')*mul;
        mul*=10;
    }
    return ans;
}