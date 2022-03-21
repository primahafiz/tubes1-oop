#include "Crafting.hpp"
#include <string>

Crafting::Crafting()
{
    for (int i = 0; i < 9; i++)
    {
        crafting[i] = SlotCrafting();
    }
}

// Crafting::Crafting(const Crafting &c)
// {
//     for (int i = 0; i < 9; i++)
//     {
//         crafting[i] = SlotCrafting(c.getCrafting(i));
//     }
// }

Crafting::~Crafting()
{
}

Item *Crafting::getCrafting(int i)
{
    return crafting[i].getSlotCraftingItem();
}

// add sebuah Item pada slot crafting ke i
void Crafting::addToCrafting(Item *a, int i)
{
    if (this->crafting[i].isSlotCraftingEmpty())
    {
        crafting[i].addSlotCrafting(a);
    }
    else
    {
        // exception
    }
}

// delete sebuah Item pada slot crafting ke i
void Crafting::deleteCrafting(int i)
{
    if (!this->crafting[i].isSlotCraftingEmpty())
    {
        crafting[i].dropSlotCrafting();
    }
    else
    {
        // exception
    }
}

// clear crafting
void Crafting::clearCrafting()
{
    for (int i = 0; i < 9; i++)
    {
        deleteCrafting(i);
    }
}

bool Crafting::isCraftingEmpty(int i)
{
    return crafting[i].isSlotCraftingEmpty();
}

void Crafting::swap(int i, int j)
{
    Item *a = getCrafting(j);
    deleteCrafting(j);
    addToCrafting(getCrafting(i), j);
    deleteCrafting(i);
    addToCrafting(a, i);
}

void Crafting::symmetry()
{
    swap(0, 2);
    swap(3, 5);
    swap(6, 8);
}

bool Crafting::isCraftable(string X)
{
    string crafting = "";
    string crafting2 = "";
    Crafting craft2 = *this;
    craft2.symmetry();

    cout << "hellllllllllooooooo" << endl;

    for (int i = 0; i < 9; i++)
    {
        if (isCraftingEmpty(i))
        {
            crafting += "-";
        }
        else
        {
            crafting += getCrafting(i)->getName();
        }
    }

    cout << "haaaaaaaaaaaaaaaiii" << endl;

    for (int i = 0; i < 9; i++)
    {
        if (craft2.isCraftingEmpty(i))
        {
            crafting2 += "-";
        }
        else
        {
            crafting2 += craft2.getCrafting(i)->getName();
        }
    }

    // return crafting2;
    cout << "kekekkekekekekekekk" << endl;
    size_t found = crafting.find(X);
    size_t found2 = crafting2.find(X);
    cout << "yooooooooooooooooooooooo" << endl;
    if (found != string::npos || found2 != string::npos)
    { // kalo ada pattern yang cocok
        return true;
    }
    else
    {
        return false;
    }
}

int Crafting::totalDurability()
{
    int total = 0;
    for (int i = 0; i < 9; i++)
    {
        if (!isCraftingEmpty(i) && getCrafting(i)->isTool())
        {
            total += getCrafting(i)->getDurability();
        }
    }
    return total;
}

void Crafting::printCrafting()
{
    for (int i = 0; i < 9; i++)
    {
        crafting[i].printSlotCrafting();
        if (i == 2 || i == 5 || i == 8)
        {
            cout << "\n";
        }
    }
}