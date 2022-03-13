/* File: Tool.cpp */
#include "Tool.hpp"

// Default Constructor
Tool::Tool() : Item() {
    setDurability(0);
}

// User-Defined Construtor
Tool::Tool(int id, string name, string type, int durability) : Item(id, name, type) {
    setDurability(durability);
}

// Setter durability
void Tool::setDurability(int durability) {
    this->durability = durability;
}

// Getter durability
int Tool::getDurability() const {
    return this->durability;
}

// modifyDurability: menambahkan durability tool sebanyak changes
// Variabel changes dapat bernilai positif/negatif
void Tool::modifyDurability(int changes) {
    this->durability += changes;
}

// isTool: mengecek kategori item (TOOL/NONTOOL)
// Mengembalikan true jika item masuk kategori TOOL
bool Tool::isTool() {
    return true;
}