/* File: nonTool.cpp */
#include "nonTool.hpp"

// Default Constructor
nonTool::nonTool() : Item()
{
    setQuantity(0);
}

// User-Defined Construtor
nonTool::nonTool(int id, string name, string type, int quantity) : Item(id, name, type)
{
    setQuantity(quantity);
}

// Setter Quantity
void nonTool::setQuantity(int quantity)
{
    this->quantity = quantity;
}

// Getter Quantity
int nonTool::getQuantity() const
{
    return this->quantity;
}

// modifyQuantity: menambahkan quantity item non tool sebanyak amount
// Variabel amount dapat bernilai positif/negatif
void nonTool::modifyQuantity(int amount)
{
    this->quantity += amount;
}

// isTool: mengecek kategori item (TOOL/NONTOOL)
// Mengembalikan true jika item masuk kategori TOOL
bool nonTool::isTool()
{
    return false;
}