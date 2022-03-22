#include "Inventory.hpp"

Inventory::Inventory()
{
    this->inventory = new SlotInventory[27];
    for (int i = 0; i < 27; i++)
    {
        inventory[i] = SlotInventory();
    }
}
Inventory::~Inventory()
{
    delete[] this->inventory;
}

Inventory::Inventory(const Inventory &a)
{
    delete[] this->inventory;
    this->inventory = new SlotInventory[27];
    for (int i = 0; i < 27; i++)
    {
        inventory[i] = a.inventory[i];
    }
}

void Inventory::addToInventory(Item *a)
{
    if (a->isTool())
    {
        if (this->getAvailableSlot(a))
        {
            for (int i = 0; i < 27; i++)
            {
                if (inventory[i].isSlotEmpty())
                {
                    inventory[i].addSlot(a);
                    break;
                }
            }
        }
        else
        {
            throw InventoryFullException();
        }
    }
    else if (this->getAvailableSlot(a) >= a->getQuantity())
    {
        int cur = a->getQuantity();
        for (int i = 0; i < 27; i++)
        {
            if (inventory[i].isSlotEmpty())
                continue;
            if (inventory[i].getSlotItem()->getName() == a->getName())
            {
                if (cur == 0)
                    break;
                int toAdd = min(cur, 64 - inventory[i].getSlotItem()->getQuantity());
                cur -= toAdd;
                inventory[i] = new nonTool(a->getID(), a->getName(), a->getType(), toAdd + inventory[i].getSlotItem()->getQuantity());
            }
        }
        for (int i = 0; i < 27; i++)
        {
            if (cur == 0)
                break;
            if (inventory[i].isSlotEmpty())
            {
                int toAdd = min(cur, 64);
                cur -= toAdd;
                inventory[i].addSlot(new nonTool(a->getID(), a->getName(), a->getType(), toAdd));
            }
        }
    }
    else
    {
        throw InventoryFullException();
    }
}

void Inventory::addToInventory(string ID, Item *a)
{
    int slotId = this->parsingID(ID);
    if (inventory[slotId].isSlotEmpty())
    {
        if (a->isTool())
        {
            inventory[slotId].addSlot(a);
        }
        else
        {
            if (a->getQuantity() > 64)
            {
                throw InventoryFullException();
            }
            else
            {
                inventory[slotId].addSlot(a);
            }
        }
    }
    else
    {
        if (a->isTool())
        {
            throw InventoryFullException();
        }
        else
        {
            if (a->getName() == inventory[slotId].getSlotItem()->getName())
            {
                if (a->getQuantity() + inventory[slotId].getSlotItem()->getQuantity() > 64)
                {
                    throw InventoryFullException();
                }
                else
                {
                    inventory[slotId].getSlotItem()->modifyQuantity(a->getQuantity());
                }
            }
            else
            {
                throw CombineDifferentItemException();
            }
        }
    }
}

int Inventory::getAvailableSlot(Item *a)
{
    int res = 0;
    if (a->isTool())
    {
        for (int i = 0; i < 27; i++)
        {
            if (this->inventory[i].isSlotEmpty())
            {
                res++;
            }
        }
    }
    else
    {
        for (int i = 0; i < 27; i++)
        {
            if (this->inventory[i].isSlotEmpty())
            {
                res += 64;
            }
            else
            {
                if (a->getName() == this->inventory[i].getSlotItem()->getName())
                {
                    res += 64 - this->inventory[i].getSlotItem()->getQuantity();
                }
            }
        }
    }
    return res;
}

void Inventory::deleteFromInventory(string ID, int num)
{
    int slotId = this->parsingID(ID);
    if (inventory[slotId].isSlotEmpty())
    {
        throw DeleteInventoryException();
    }
    else if (inventory[slotId].getSlotItem()->isTool())
    {
        if (num == 1)
        {
            inventory[slotId].dropSlot();
        }
        else
        {
            throw DeleteInventoryException();
        }
    }
    else if (!inventory[slotId].getSlotItem()->isTool())
    {
        if (num <= inventory[slotId].getSlotItem()->getQuantity())
        {
            inventory[slotId].dropSlot(num);
        }
        else
        {
            throw DeleteInventoryException();
        }
    }
}

Item *Inventory::getInventory(int k)
{
    return this->inventory[k].getSlotItem();
}

void Inventory::combineTwoItem(string IDSrc, string IDDest)
{
    int slotId1 = this->parsingID(IDSrc);
    int slotId2 = this->parsingID(IDDest);
    if (inventory[slotId1].isSlotEmpty() || inventory[slotId2].isSlotEmpty())
    {
        throw CombineNullItemException();
    }
    else if (!inventory[slotId1].getSlotItem()->isTool() && !inventory[slotId2].getSlotItem()->isTool() && inventory[slotId1].getSlotItem()->getName() == inventory[slotId1].getSlotItem()->getName())
    {
        if (inventory[slotId1].getSlotItem()->getQuantity() + inventory[slotId2].getSlotItem()->getQuantity() > 64)
        {
            inventory[slotId1].getSlotItem()->setQuantity(inventory[slotId1].getSlotItem()->getQuantity() - (64 - inventory[slotId2].getSlotItem()->getQuantity()));
            inventory[slotId2].getSlotItem()->setQuantity(64);
        }
        else
        {
            inventory[slotId2].getSlotItem()->setQuantity(inventory[slotId1].getSlotItem()->getQuantity() + inventory[slotId2].getSlotItem()->getQuantity());
            inventory[slotId1].dropSlot(inventory[slotId1].getSlotItem()->getQuantity());
        }
    }
    else
    {
        throw CombineDifferentItemException();
    }
}
void Inventory::exportInventory(string path)
{
    ofstream inventoryFile;
    inventoryFile.open(path);
    for (int i = 0; i < 27; i++)
    {
        if (inventory[i].isSlotEmpty())
        {
            inventoryFile << "0:0\n";
        }
        else
        {
            inventoryFile << inventory[i].getSlotItem()->getID() << ":";
            if (inventory[i].getSlotItem()->isTool())
            {
                inventoryFile << inventory[i].getSlotItem()->getDurability();
            }
            else
            {
                inventoryFile << inventory[i].getSlotItem()->getQuantity();
            }
            inventoryFile << "\n";
        }
    }
    inventoryFile.close();
}
void Inventory::printInventory()
{
    for (int i = 0; i < 27; i++)
    {
        inventory[i].printSlot(i % 9 == 8);
    }
}
int Inventory::parsingID(string ID)
{
    int ans = 0;
    int mul = 1;
    int n = ID.size();
    for (int i = n - 1; i > 0; i--)
    {
        ans += (ID[i] - '0') * mul;
        mul *= 10;
    }
    return ans;
}