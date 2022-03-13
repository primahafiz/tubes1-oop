/* File: Tool.hpp */
#ifndef __TOOL_HPP__
#define __TOOL_HPP__

#include "Item.hpp"

/* Kelas Tool */
class Tool : public Item {
private:
    /* Atribut */
    int durability;     // durabilitas tool (nilai awal = 10)
public:
    // Default Constructor
    Tool();

    // User-Defined Construtor
    Tool(int id, string name, string type, int durability);

    // Setter durability
    void setDurability(int durability);

    // Getter durability
    int getDurability() const;
    
    // modifyDurability: menambahkan durability tool sebanyak changes
    // Variabel changes dapat bernilai positif/negatif
    void modifyDurability(int changes);

    // isTool: mengecek kategori item (TOOL/NONTOOL)
    // Mengembalikan true jika item masuk kategori TOOL
    bool isTool();
};

#endif